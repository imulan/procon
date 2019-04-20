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

const ll mod = 1e9+7;
using pl = pair<ll,ll>;

int main()
{
    int n;
    cin >>n;

    vector<ll> v(n);
    ll a,b,c;
    cin >>v[0] >>a >>b >>c;
    for(int i=1; i<n; ++i) v[i] = (a*v[i-1]+b)%c;

    ll ans = 0;
    ll t = 0;
    set<pl> s;
    rep(i,n)
    {
        auto itr = s.begin();
        ll w = 1;
        while(itr != s.end())
        {
            if(itr->fi<=v[i])
            {
                w += itr->se;
                t = (t - ((itr->fi)*(itr->se))%mod + 2*mod)%mod;
                itr = s.erase(itr);
            }
            else break;
        }

        s.insert({v[i],w});
        (t += (v[i]%mod *w )%mod) %=mod;
        (ans += t)%=mod;
    }

    cout << ans << endl;
    return 0;
}
