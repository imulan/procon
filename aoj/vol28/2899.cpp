#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;

string d = "URDL";
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

inline bool query(int idx){
    printf("? %c\n", d[idx]);
    fflush(stdout);

    char s[10];
    scanf("%s",s);
    return s[0]=='Y';
}

const int B = 505;
const int N = 1010;
bool already[N][N], trail[N][N];

void dfs(int y, int x){
    // printf(" (%d %d)\n",y,x);
    rep(i,4){
        if(already[y+dy[i]+B][x+dx[i]+B]) continue;
        bool res = query(i);
        already[y+dy[i]+B][x+dx[i]+B] = true;
        if(res){
            dfs(y+dy[i],x+dx[i]);
            trail[y+dy[i]+B][x+dx[i]+B] = true;
            query(i^2);
        }
    }
}

int main(){
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    trail[B][B] = true;
    already[B][B] = true;
    dfs(0,0);

    int ty = h, tx = w;
    rep(i,N)rep(j,N)if(trail[i][j]){
        int py = i-B, px = j-B;
        if(py < ty){
            ty = py;
            tx = px;
        }
        else if(py == ty) tx = min(tx,px);
    }

    set<pi> fix_trail;
    rep(i,N)rep(j,N)if(trail[i][j]){
        int py = i-B, px = j-B;
        fix_trail.insert({py-ty, px-tx});
    }

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    vector<vector<bool>> vis(h,vector<bool>(w));
    rep(i,h)rep(j,w){
        if(s[i][j]=='.' || vis[i][j]) continue;

        queue<pi> que;
        vector<pi> cc;
        vis[i][j] = true;
        que.push({i,j});
        cc.pb({i,j});
        while(!que.empty()){
            pi now = que.front();
            que.pop();
            rep(k,4){
                int ny=now.fi+dy[k], nx = now.se+dx[k];
                if(IN(ny,nx) && s[ny][nx]=='#' && !vis[ny][nx]){
                    vis[ny][nx] = true;
                    que.push({ny,nx});
                    cc.pb({ny,nx});
                }
            }
        }

        int my=h, mx=w;
        for(pi p:cc){
            if(p.fi < my){
                my = p.fi;
                mx = p.se;
            }
            else if(p.fi == my) mx = min(mx,p.se);
        }

        set<pi> fix_cc;
        for(pi p:cc) fix_cc.insert({p.fi-my, p.se-mx});

        if(fix_cc == fix_trail){
            printf("! %d %d\n", i-ty, j-tx);
            fflush(stdout);
            break;
        }
    }

    return 0;
}
