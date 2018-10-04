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

int main(){
    int n,m,RULE;
    while(scanf(" %d %d %d", &n, &m, &RULE),n){
        vector<int> A(n),B(m);
        rep(i,n){
            scanf(" %d", &A[i]);
            --A[i];
        }
        rep(i,m){
            scanf(" %d", &B[i]);
            --B[i];
        }

        vector< pair<vector<int>,int> > rule(RULE);
        rep(i,RULE){
            int k;
            scanf(" %d", &k);

            vector<int> x(k);
            int y;
            rep(j,k){
                scanf(" %d", &x[j]);
                --x[j];
            }
            scanf(" %d", &y);
            --y;

            rule[i] = {x,y};
        }

        auto make_f = [&](vector<int> &v){
            int V = v.size();
            int N = 2*V;
            vector<vector<int>> f(N,vector<int>(N));

            rep(i,N){
                int vv = v[i%V];
                f[i][i] |= (1<<vv);
            }

            for(int b=2; b<=V; ++b){
                for(int l=0; l+b-1<N; ++l){
                    int r = l+b-1;

                    // calc f[l][r]
                    rep(rr,RULE){
                        vector<int> x = rule[rr].fi;
                        int y = rule[rr].se;

                        int X = x.size();
                        vector<vector<bool>> valid(b+1, vector<bool>(X+1));
                        valid[0][0] = true;
                        rep(i,b)rep(j,X)if(valid[i][j]){
                            int val = x[j];
                            for(int k=i; k<b; ++k){
                                if(f[l+i][l+k]>>val&1) valid[k+1][j+1] = true;
                            }
                        }

                        if(valid[b][X]) f[l][r] |= (1<<y);
                    }
                }
            }

            // rep(i,N)rep(j,N) printf("f[%d][%d] = %d\n",i,j,f[i][j]);
            return f;
        };

        vector<vector<int>> fa = make_f(A), fb = make_f(B);
        int ans = -1;
        rep(i,n)rep(j,m){
            // printf("CALC %d %d\n",i,j);
            vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
            dp[0][0]=0;
            rep(ii,n)rep(jj,m)if(dp[ii][jj]>=0){
                for(int ni=ii+1; ni<=n; ++ni)for(int nj=jj+1; nj<=m; ++nj){
                    if(fa[i+ii][i+ni-1]&fb[j+jj][j+nj-1]) dp[ni][nj] = max(dp[ni][nj], dp[ii][jj]+1);
                }
            }
            ans = max(ans, dp[n][m]);
        }

        printf("%d\n", ans);
    }
    return 0;
}
