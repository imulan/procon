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
    cin >>n;

    map<ll,int> ct;
    rep(i,n)
    {
        ll a;
        cin >>a;
        ++ct[a];
    }

    vector<ll> t;
    ll ret = 0;
    for(const auto &p:ct)
    {
        if(p.se>=2) t.pb(p.fi);
        if(p.se>=4) ret = max(ret,p.fi*p.fi);
    }

    sort(all(t));
    int T = t.size();

    if(T>=2) ret = max(ret,t[T-1]*t[T-2]);
    return ret;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
