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
    int n;
    ll k;
    cin >>n >>k;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    sort(all(a));

    int idx = 0;
    int ans = 0;
    while(idx<n)
    {
        if(2*k>=a[idx])
        {
            k = max(k,a[idx]);
            ++idx;
        }
        else
        {
            k *= 2;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
