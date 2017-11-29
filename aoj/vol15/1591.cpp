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

ll solve(ll n, ll d)
{
    if(d==1) return n*(n-1)/2;

    ll r = n-(d+1);
    return d + r*3 + r*(r-1)/2;
}

int main()
{
    ll n,d;
    cin >>n >>d;
    cout << solve(n,d) << endl;
    return 0;
}
