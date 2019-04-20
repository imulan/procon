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

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

int main(){
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    pi start;
    vector<pi> q;
    rep(i,h)rep(j,w){
        if(s[i][j]=='.') start = {i,j};
        if(s[i][j]=='?') q.pb({i,j});
    }

    vector<vector<bool>> reach(h,vector<bool>(w));
    reach[start.fi][start.se] = true;
    queue<pi> que({start});
    while(!que.empty()){
        pi p = que.front();
        que.pop();
        rep(i,4){
            int ny = p.fi+dy[i], nx = p.se+dx[i];
            if(IN(ny,nx) && !reach[ny][nx] && s[ny][nx]!='#'){
                reach[ny][nx] = true;
                que.push({ny,nx});
            }
        }
    }

    for(pi p:q){
        if(reach[p.fi][p.se]) s[p.fi][p.se] = '.';
        else s[p.fi][p.se] = '#';
    }

    auto connected = [&](){
        vector<vector<bool>> vis(h,vector<bool>(w));
        vis[start.fi][start.se] = true;
        que.push(start);
        while(!que.empty()){
            pi p = que.front();
            que.pop();
            rep(i,4){
                int ny = p.fi+dy[i], nx = p.se+dx[i];
                if(IN(ny,nx) && !vis[ny][nx] && s[ny][nx]!='#'){
                    vis[ny][nx] = true;
                    que.push({ny,nx});
                }
            }
        }

        rep(i,h)rep(j,w)if(s[i][j]=='.' && !vis[i][j]) return false;
        return true;
    };

    if(!connected()){
        cout << "Impossible" << "\n";
        return 0;
    }

    for(pi p:q)if(reach[p.fi][p.se]){
        s[p.fi][p.se] = '#';
        if(connected()){
            cout << "Ambiguous" << "\n";
            return 0;
        }
        s[p.fi][p.se] = '.';
    }

    rep(i,h) cout << s[i] << "\n";
    return 0;
}
