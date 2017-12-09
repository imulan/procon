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

int main()
{
    int n,x;
    string s;
    cin >>n >>x >>s;

    vector<int> t(n);
    rep(i,n) cin >>t[i];

    ll ans = 0;
    rep(i,n)
    {
        if(s[i]=='0') ans += t[i];
        else ans += min(t[i],x);
    }

    cout << ans << endl;
    return 0;
}
