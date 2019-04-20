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

// const int B = 5;
// const int N = 20;

const int B = 30;
const int N = 2000020;
const int INF = 19191919;
int a[N];

int nx[B][N];
int ct[B][N+1];

inline bool exist(int b, int l, int r){
    int res = ct[b][r+1] - ct[b][l];
    return res>0;
}

int f[N];
int nf[N];

using pi = pair<int,int>;

vector<int> cc[N];
int sz[N];
bool vis[N];
pi idx[N];

bool used[N];
int endk[N];

int main(){
    int n,K;
    scanf(" %d %d", &n, &K);
    rep(i,n) scanf(" %d", &a[i]);

    rep(i,n) a[n+i] = a[i];

    rep(i,B)rep(j,N) nx[i][j] = INF;
    rep(i,2*n){
        rep(j,B){
            if(a[i]>>j&1){
                nx[j][i]=i;
                ++ct[j][i+1];
            }
        }
    }

    rep(i,B){
        for(int j=N-2; j>=0; --j){
            nx[i][j] = min(nx[i][j], nx[i][j+1]);
        }

        rep(j,N-1) ct[i][j+1] += ct[i][j];
    }

    f[2*n] = INF;
    rep(i,2*n) f[i] = i+1;

    int ans = 0;
    for(int i=B-1; i>=0; --i){
        // construct nf
        for(int j=2*n-1; j>=0; --j){
            nf[j] = f[j];
            if(nf[j] == INF) continue;
            if(exist(i,j,nf[j]-1)) continue;

            int pos = nf[j]-1;
            nf[j] = min(INF, nx[i][pos]+1);
        }

        // dbg(i);
        // rep(j,N) printf(" nf[%d] = %d\n",j,nf[j]);

        fill(vis,vis+2*n,false);
        int C = 0;
        rep(j,2*n)if(!vis[j]){
            sz[C] = 0;
            int now = j;
            while(now<2*n && !vis[now]){
                // dbg(now);
                cc[C].pb(now);
                vis[now] = true;
                idx[now] = {C,sz[C]};
                ++sz[C];

                now = nf[now];
            }
            ++C;
        }

        fill(used,used+2*n,false);
        fill(endk,endk+2*n,INF);
        rep(cidx,C){
            int V = sz[cidx];

            int ED = nf[cc[cidx][V-1]];
            if(ED < 2*n){
                pi pos = idx[ED];
                --pos.se;

                int vidx = V-1;
                while(pos.se>=0 && vidx>=0){
                    endk[cc[cidx][vidx]] = endk[cc[pos.fi][pos.se]];
                    used[cc[cidx][vidx]] = true;
                    --pos.se;
                    --vidx;
                }
            }

            rep(j,V-K){
                if(used[j]) break;
                used[j] = true;
                endk[j] = cc[cidx][j+K];
            }
        }

        bool ok = false;
        rep(j,n){
            int e = endk[j];
            if(e-j <= n){
                ok = true;
                break;
            }
        }
        if(ok){
            ans |= (1<<i);
            rep(j,2*n) f[j] = nf[j];
        }

        rep(j,C) cc[j].clear();
    }

    printf("%d\n", ans);
    return 0;
}
