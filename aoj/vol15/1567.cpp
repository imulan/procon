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

const int mod = 1e9+7;
const int N = 5005;

int dp[N][N]={};

int main(){
    int n,m,k,q;
    scanf(" %d %d %d %d", &n, &m, &k, &q);

    dp[0][0] = 1;
    rep(i,N-1){
        int val = 0;
        rep(j,n){
            if( (j/k)%2==0 ){
                int idx = (0-j+n)%n;
                (val += dp[i][idx]) %= mod;
            }
        }

        int B = 2*k;
        rep(j,B){
            for(int x=j; x<n; x+=B) dp[i+1][x] = val;

            rep(x,n/k){
                int idx = (j+1-x*k+n)%n;
                if(x%2==0) val = (val+dp[i][idx])%mod;
                else val = (val-dp[i][idx]+mod)%mod;
            }
        }
    }

    rep(i,q){
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        int d = c-a;
        if(d<0) d+=n;
        printf("%d\n", dp[b][d]);
    }

    return 0;
}
