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

ll C(int n, int r)
{
    ll x = 1;
    rep(i,r) x*=n-i;
    rep(i,r) x/=i+1;
    return x;
}

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<int> s(a);
    sort(all(s));

    map<int,int> ct;
    rep(i,n) ++ct[a[i]];

    ll ans = ct[s[2]];
    if(s[2]==s[1] && s[2]==s[0]) ans = C(ct[s[2]],3);
    else if(s[2]==s[1]) ans = C(ct[s[2]],2);

    cout << ans << endl;
    return 0;
}
