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

const int N = 2000020;
const int INF = 19191919;
int a[N];

const int L = 21;
// const int L = 5;
int OR[L][N];

int f[L][N];

int main(){
    int n,K;
    scanf(" %d %d", &n, &K);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,n) a[n+i] = a[i];

    rep(i,2*n) OR[0][i] = a[i];
    for(int i=1; i<L; ++i){
        rep(j,2*n){
            OR[i][j] = OR[i-1][j];
            int idx = j+(1<<(i-1));
            if(idx<N) OR[i][j] |= OR[i-1][idx];
            // printf(" OR[ %d ][ %d ] = %d\n", i,j,OR[i][j]);
        }
    }

    int start = 29;
    int ans = 0;
    for(int i=start; i>=0; --i){
        int pre = ans|(1<<i);
        // dbg(pre);

        rep(j,L)rep(k,N) f[j][k] = INF;

        rep(j,2*n){
            int add = 0;
            if( (OR[L-1][j]&pre) != pre ) continue;

            // printf(" --- j %d --- \n",j);
            int v = 0;
            int now = j;
            for(int k=L-1; k>=0; --k){
                int nv = v|OR[k][now];
                // dbg(nv);
                if( (nv&pre) != pre){
                    v |= OR[k][now];
                    now += (1<<k);
                }
            }

            if( (v&pre) != pre){
                v |= OR[0][now];
                ++now;
            }
            assert( (v&pre) == pre );
            f[0][j] = now;

            // printf(" f[0][%d] = %d\n", j,now);
        }

        for(int j=1; j<L; ++j){
            rep(k,2*n){
                if(f[j-1][k]==INF) continue;
                f[j][k] = f[j-1][f[j-1][k]];
                // printf(" f[%d][%d] = %d\n",j,k,f[j][k]);
            }
        }

        bool ok = false;
        rep(j,n){
            int pos = j;
            for(int k=L-1; k>=0; --k){
                if(K>>k&1){
                    pos = f[k][pos];
                }
                if(pos == INF) break;
            }
            // printf("   j pos %d %d\n",j,pos);
            if(pos-j<=n){
                ok = true;
                break;
            }
        }

        if(ok) ans |= (1<<i);
    }

    printf("%d\n", ans);
    return 0;
}
