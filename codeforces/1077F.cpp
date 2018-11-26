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

const ll INF = LLONG_MAX/3;

int main(){
    int n,k,x;
    scanf(" %d %d %d", &n, &k, &x);

    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    vector<ll> dp(n,-INF);
    rep(i,k) dp[i] = a[i];

    rep(xxx,x-1){
        vector<ll> nx(n,-INF);
        deque<int> deq;
        rep(i,n){
            if(!deq.empty()) nx[i] = max(nx[i], dp[deq.front()]+a[i]);

            while(!deq.empty() && dp[deq.back()]<=dp[i]) deq.pop_back();
            deq.push_back(i);

            if(i-k>=0 && deq.front() == i-k) deq.pop_front();
        }

        dp = nx;
    }

    ll ans = -1;
    rep(i,k) ans = max(ans, dp[n-1-i]);
    printf("%lld\n", ans);
    return 0;
}
