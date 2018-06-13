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

const int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1};
const double eps = 1e-8;

int main(){
    int w,h;
    while(cin >>w >>h,w){
        vector<string> s(h);
        rep(i,h) cin >>s[i];

        auto IN = [&](int y, int x){
            return 0<=y && y<h && 0<=x && x<w;
        };

        vector<vector<pi>> b;
        int B = 0;

        vector<vector<bool>> vis(h,vector<bool>(w));
        vector<vector<int>> f(h,vector<int>(w,-1));

        rep(i,h)rep(j,w){
            if(s[i][j]!='.' && !vis[i][j]){
                vector<pi> block;

                char focus = s[i][j];
                queue<pi> que;

                f[i][j] = B;
                vis[i][j] = true;
                que.push({i,j});
                block.pb({i,j});
                while(!que.empty()){
                    pi now = que.front();
                    que.pop();
                    rep(d,4){
                        int ny = now.fi+dy[d], nx = now.se+dx[d];
                        if(IN(ny,nx) && !vis[ny][nx] && s[ny][nx]==focus){
                            f[ny][nx] = B;
                            vis[ny][nx] = true;
                            que.push({ny,nx});
                            block.pb({ny,nx});
                        }
                    }
                }

                b.pb(block);
                ++B;
            }
        }

        vector<int> par(B,-1);
        rep(i,B){
            for(pi p:b[i]){
                int ny=p.fi+1, nx=p.se;
                if(IN(ny,nx) && f[ny][nx]!=-1 && f[ny][nx]!=f[p.fi][p.se]){
                    par[i] = f[ny][nx];
                }
            }
        }

        vector<vector<int>> ch(B);
        rep(i,B){
            if(par[i]!=-1) ch[par[i]].pb(i);
        }

        auto check = [&](int root){
            int xl = w+1, xr = 0;
            for(pi p:b[root]){
                int ny=p.fi+1, nx=p.se;

                if(!IN(ny,nx) || (f[ny][nx]!=-1 && f[ny][nx]!=f[p.fi][p.se])){
                    xl = min(xl,nx);
                    xr = max(xr,nx+1);
                }
            }
            // printf(" %d: x[%d,%d]\n",root,xl,xr);

            vector<int> idx;
            queue<int> que;
            idx.pb(root);
            que.push(root);
            while(!que.empty()){
                int now = que.front();
                que.pop();
                for(int c:ch[now]){
                    idx.pb(c);
                    que.push(c);
                }
            }

            double mx = 0;
            int W = 0;
            for(int i:idx){
                for(pi p:b[i]){
                    mx += p.se+0.5;
                    ++W;
                }
            }
            mx /= W;

            return mx-xl>eps && xr-mx>eps;
        };

        bool ok = true;
        rep(i,B) ok &= check(i);
        cout << (ok?"":"UN") << "STABLE" << endl;
    }
    return 0;
}
