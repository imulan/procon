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

const int N = 15;
const int INF = 19191919;
int dp[1<<N];

int main(){
    int n,m;
    while(scanf(" %d %d", &n, &m),n){
        vector<int> s(n),d(m);
        rep(i,n) cin >>s[i];
        rep(i,m) cin >>d[i];
        sort(all(d));

        vector<int> nuk(1<<n);
        rep(mask,1<<n){
            rep(i,n)if(mask>>i&1) nuk[mask] += s[i];
        }

        fill(dp, dp+(1<<N), INF);
        dp[0] = 0;
        rep(mask,1<<n){
            rep(i,n)if(!(mask>>i&1)){
                int nx = mask|(1<<i);

                int lidx = lower_bound(all(d), nuk[mask]) - d.begin();
                int ridx = upper_bound(all(d), nuk[nx]) - d.begin();
                int add = 0;
                for(int j=lidx; j<ridx; ++j){
                    add += min(d[j]-nuk[mask], nuk[nx]-d[j]);
                }
                dp[nx] = min(dp[nx], dp[mask]+add);
            }
        }

        int add = 0;
        rep(i,m)if(nuk[(1<<n)-1] < d[i]) add += d[i]-nuk[(1<<n)-1];
        printf("%d\n", dp[(1<<n)-1]+add);
    }
    return 0;
}
