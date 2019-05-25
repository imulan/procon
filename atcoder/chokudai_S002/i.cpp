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

using P = pair<ll,int>;

int main(){
    int n;
    cin >>n;

    vector<ll> a(n),b(n);
    vector<P> p(n);
    rep(i,n){
        cin >>a[i] >>b[i];
        p[i] = {a[i]*b[i], i};
    }
    sort(all(p));

    int ans = p[n-1].se;
    rep(i,n-1){
        int idx = p[i].se;

        ll x = (a[idx]+b[ans]-1)/b[ans];
        if(a[ans] <= b[idx]*x){
            ans = -2;
            break;
        }
    }
    cout << ans+1 << endl;
    return 0;
}
