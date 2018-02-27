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

const ll INF = 19191919;

const int N = 100010;
ll dp[N+1];
ll nx[N+1];

int main(){
    int a,b,h,w,n;
    scanf(" %d %d %d %d %d", &a, &b, &h, &w, &n);

    if(a>b) swap(a,b);
    if(h>w) swap(h,w);

    vector<ll> x(n);
    rep(i,n) scanf(" %lld", &x[i]);
    sort(all(x), greater<ll>());

    if(h>=a && w>=b){
        printf("0\n");
        return 0;
    }

    fill(dp,dp+N+1,-INF);
    dp[h] = w;
    rep(i,n){
        fill(nx,nx+N+1,-INF);
        for(ll j=1; j<=N; ++j)if(dp[j]>0){
            ll na = min((ll)N, j*x[i]);
            nx[na] = max(nx[na], dp[j]);

            ll nb = min((ll)N, dp[j]*x[i]);
            nx[j] = max(nx[j], nb);
        }

        rep(j,N+1) dp[j]=nx[j];

        for(int j=a; j<=N; ++j){
            if(dp[j]>=b){
                printf("%d\n",i+1);
                return 0;
            }
        }
        for(int j=b; j<=N; ++j){
            if(dp[j]>=a){
                printf("%d\n",i+1);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}
