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
const int T = 2200;
ll dp[T];

int main()
{
    int n,k,m;
    cin >>n >>k >>m;
    vector<ll> t(k);
    rep(i,k) cin >>t[i];
    sort(all(t));

    // subtaskをi個解くのにかかる時間
    vector<ll> st(k+1);
    rep(i,k) st[i+1] = st[i]+t[i];

    fill(dp,dp+T,INF);
    dp[0] = 0;
    rep(i,n)
    {
        for(int j = T-100; j>=0; --j)
        {
            rep(x,k+1)
            {
                int add = x+(x==k);
                dp[j+add] = min(dp[j+add], dp[j]+st[x]);
            }
        }
    }

    int ans = T-1;
    while(dp[ans]>m) --ans;
    cout << ans << endl;
    return 0;
}
