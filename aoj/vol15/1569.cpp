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

const int dx[9]={1,1,1,0,0,0,-1,-1,-1};
const int dy[9]={1,0,-1,1,0,-1,1,0,-1};

const int T = 44;
bool vis[20][20][T][1<<5]={};

struct State{
    int y,x,t,mask;
};

int solve(){
    int w,h,n;
    cin >>w >>h >>n;

    pi s;
    cin >>s.se >>s.fi;
    --s.fi;
    --s.se;

    set<pi> bomb;
    vector<vector<pi>> l(n);
    rep(i,n){
        int L;
        cin >>L;
        rep(j,L){
            int x,y;
            cin >>x >>y;
            --x;
            --y;
            l[i].pb({y,x});
        }
        bomb.insert(l[i][L-1]);
    }

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    queue<State> que;
    vis[s.fi][s.se][0][0] = true;
    que.push({s.fi,s.se,0,0});
    while(!que.empty()){
        State c = que.front();
        que.pop();
        if(c.t==T-1) break;

        int nmask = c.mask;
        rep(i,n){
            int L = l[i].size();
            if(c.t<L && l[i][c.t] == pi(c.y,c.x)) nmask |= (1<<i);
        }
        if(!vis[c.y][c.x][c.t][nmask]){
            vis[c.y][c.x][c.t][nmask] = true;
            que.push({c.y,c.x,c.t,nmask});
        }

        rep(d,9){
            int ny = c.y+dy[d], nx = c.x+dx[d];
            if(IN(ny,nx) && !bomb.count({ny,nx}) && !vis[ny][nx][c.t+1][c.mask]){
                vis[ny][nx][c.t+1][c.mask] = true;
                que.push({ny,nx,c.t+1,c.mask});
            }
        }
    }

    rep(i,T){
        rep(y,h)rep(x,w){
            if(vis[y][x][i][(1<<n)-1]) return i;
        }
    }
    return -1;
}

int main(){
    cout << solve() << endl;
    return 0;
}
