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

const int H = 12;
const int W = 6;

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

const vector<vector<bool>> B(H, vector<bool>(W, false));

bool IN(int y, int x){
    return 0<=y && y<H && 0<=x && x<W;
}

vector<string> f(const vector<string> &s){
    vector<string> t(s);

    vector<vector<bool>> er(B), vis(B);

    rep(i,H)rep(j,W){
        if(vis[i][j]) continue;

        char c = s[i][j];
        if(c=='O' || c=='.') continue;

        queue<pi> que;
        vector<pi> cc;

        vis[i][j] = true;
        cc.pb({i,j});
        que.push({i,j});
        while(!que.empty()){
            pi now = que.front();
            que.pop();
            rep(d,4){
                int ny = now.fi+dy[d], nx = now.se+dx[d];
                if(!IN(ny,nx)) continue;
                if(!vis[ny][nx] && s[ny][nx]==c){
                    vis[ny][nx] = true;
                    cc.pb({ny,nx});
                    que.push({ny,nx});
                }
            }
        }

        if(cc.size()>=4){
            for(pi p:cc){
                er[p.fi][p.se] = true;
                rep(d,4){
                    int ny = p.fi+dy[d], nx = p.se+dx[d];
                    if(!IN(ny,nx)) continue;
                    if(s[ny][nx]=='O') er[ny][nx] = true;
                }
            }
        }
    }

    rep(i,H)rep(j,W)if(er[i][j]) t[i][j] = '.';

    rep(j,W){
        vector<char> obj;
        for(int i=H-1; i>=0; --i){
            if(t[i][j]!='.') obj.pb(t[i][j]);
            t[i][j] = '.';
        }

        int idx = H-1;
        for(char c:obj) t[idx--][j] = c;
    }
    return t;
}

int solve(){
    vector<string> s(H);
    rep(i,H) cin >>s[i];

    int ret = 0;
    while(1){
        vector<string> nx = f(s);
        if(nx == s) break;
        ++ret;
        s = nx;
    }
    return ret;
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << solve() << "\n";
    return 0;
}
