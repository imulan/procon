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
    ll L,a,b,t,r;
    scanf(" %lld %lld %lld %lld %lld", &L, &a, &b, &t, &r);

    int n;
    scanf(" %d", &n);

    vector<ll> p(n);
    rep(i,n) scanf(" %lld", &p[i]);
    p.pb(L);
    p.pb(INF);

    sort(all(p));
    p.erase(unique(all(p)), p.end());
    n = p.size();

    vector<ll> dp(n);
    vector<int> par(n,-1);
    rep(i,n-1){
        ll d = t*a+r*b;

        int idx = lower_bound(all(p), p[i]+d) - p.begin();
        // dbg(i);dbg(idx);
        for(int j:{idx-1, idx}){
            ll add = min(p[j]-p[i]-t*a, r*b);
            if(add<0) add = 0;

            // dbg(j);dbg(dp[i]+add);
            if(dp[j] < dp[i]+add){
                dp[j] = dp[i]+add;
                par[j] = i;
            }
        }

        if(dp[i+1] < dp[i]){
            dp[i+1] = dp[i];
            par[i+1] = i;
        }
    }
    // dbg(dp);

    vector<int> ans;
    int idx = n-2;
    while(par[idx] != -1){
        int nx = par[idx];
        if(dp[nx] < dp[idx]){
            ans.pb(nx);
        }
        idx = nx;
    }
    reverse(all(ans));

    int A = ans.size();
    printf("%d\n", A);
    rep(i,A) printf("%d%c", ans[i], " \n"[i==A-1]);
    return 0;
}
