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
    int a[3],b[3];
    rep(i,3) cin >>a[i];
    rep(i,3) cin >>b[i];
    sort(a,a+3);
    sort(b,b+3);

    int ans = 0;
    rep(i,3) ans += abs(a[i]-b[i]);
    cout << ans << endl;
    return 0;
}
