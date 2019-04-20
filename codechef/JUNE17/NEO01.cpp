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

ll solve()
{
    int n;
    scanf(" %d", &n);

    ll sum=0;
    int p=0;

    vector<ll> m;
    rep(i,n)
    {
        int a;
        scanf(" %d", &a);
        if(a>=0)
        {
            sum+=a;
            ++p;
        }
        else m.pb(a);
    }

    int M=m.size();

    sort(all(m),greater<ll>());

    ll ss=0;
    rep(i,M) ss+=m[i];

    ll ans = sum*p + ss;
    rep(i,M)
    {
        sum += m[i];
        ++p;
        ss -= m[i];

        ans = max(ans, sum*p+ss);
    }

    return ans;
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--) printf("%lld\n", solve());
    return 0;
}
