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

using pi = pair<int,int>;

int main(){
    int n,k;
    cin >>n >>k;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<pi> v(n);
    rep(i,n) v[i] = {-a[i],i};
    sort(all(v));

    int ans = 0;
    vector<int> idx;
    rep(i,k){
        ans += -v[i].fi;
        idx.pb(v[i].se);
    }
    idx.pb(-1);
    sort(all(idx));
    idx[k]=n-1;

    vector<int> t(k);
    for(int i=1; i<=k; ++i) t[i-1] = idx[i]-idx[i-1];

    cout << ans << endl;
    rep(i,k) cout << t[i] << " \n"[i==k-1];
    return 0;
}
