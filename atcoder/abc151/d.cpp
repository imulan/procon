#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};

const int INF = 1010101;

int main(){
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    int ans = 0;
    rep(sy,h)rep(sx,w)if(s[sy][sx]=='.'){
        vector<vector<int>> d(h,vector<int>(w,INF));
        d[sy][sx] = 0;
        queue<pi> que({{sy,sx}});
        while(!que.empty()){
            pi p = que.front();
            que.pop();
            rep(i,4){
                int ny = p.fi+dy[i], nx = p.se+dx[i];
                if(IN(ny,nx) && s[ny][nx]!='#' && d[ny][nx] > d[p.fi][p.se]+1){
                    que.push({ny,nx});
                    d[ny][nx] = d[p.fi][p.se]+1;
                }
            }
        }

        rep(i,h)rep(j,w)if(d[i][j]<INF) ans = max(ans, d[i][j]);
    }
    cout << ans << "\n";
    return 0;
}
