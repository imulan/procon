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

using pl = pair<ll,ll>;

pl solve()
{
    string s;
    cin >>s;
    int S = s.size();

    ll p=1,q=1;

    int t=0,l=0,r=0;
    while(t<S && s[t]!='.') ++t;
    while(l<S && s[l]!='(') ++l;
    while(r<S && s[r]!=')') ++r;
    // dbg(t); dbg(l); dbg(r);
    rep(_,l-t-1) q*=10;

    ll num = 0;
    rep(i,l)if(isdigit(s[i])) num = num*10+s[i]-'0';

    if(l==r) p = num;
    else
    {
        ll num2 = 0;
        rep(i,r)if(isdigit(s[i])) num2 = num2*10+s[i]-'0';

        ll PW = 1;
        rep(_,r-l-1) PW*=10;
        p = num2 - num;
        q *= (PW-1);
    }

    ll g = __gcd(p,q);
    // dbg(p); dbg(q); dbg(g);
    p /= g;
    q /= g;
    return {p,q};
}

int main()
{
    pl ans = solve();
    cout << ans.fi << "/" << ans.se << endl;
    return 0;
}
