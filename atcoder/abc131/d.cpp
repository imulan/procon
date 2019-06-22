#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pl = pair<ll,ll>;

int main(){
    int n;
    cin >>n;

    vector<pl> v(n);
    rep(i,n){
        ll a,b;
        cin >>a >>b;
        v[i] = {b,a};
    }
    sort(all(v));

    ll t = 0;
    rep(i,n){
        ll b = v[i].fi, a = v[i].se;
        if(t+a > b){
            cout << "No" << endl;
            return 0;
        }
        t += a;
    }
    cout << "Yes" << endl;
    return 0;
}
