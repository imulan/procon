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

int solve(ll p, ll q, ll x, ll y)
{
    ll a = p+q, b = p-q;
    ll g = __gcd(a,b);
    ll c = abs(x+y);
    return (c%g==0);
}

int main()
{
    ll p,q;
    cin >>p >>q;
    if(p<q) swap(p,q);

    int n;
    cin >>n;

    int ans = 0;
    while(n--)
    {
        ll x,y;
        cin >>x >>y;
        ans += solve(p,q,x,y);
    }
    cout << ans << endl;
    return 0;
}
