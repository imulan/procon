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
    cin >>n;
    vector<int> x(n),y(n);
    rep(i,n) cin >>x[i] >>y[i];

    int lx = *min_element(all(x)), rx = *max_element(all(x));
    int ly = *min_element(all(y)), ry = *max_element(all(y));
    int ans = (rx-lx)*(ry-ly);
    cout << ans << endl;
    return 0;
}
