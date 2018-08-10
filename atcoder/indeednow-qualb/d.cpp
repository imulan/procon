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

ll f(ll x){
    return x*(x+1)/2;
}

int main(){
    int n,c;
    cin >>n >>c;

    vector<vector<int>> m(c+1);
    for(int i=1; i<=c; ++i) m[i].pb(0);
    for(int i=1; i<=n; ++i){
        int a;
        cin >>a;
        m[a].pb(i);
    }
    for(int i=1; i<=c; ++i) m[i].pb(n+1);

    for(int i=1; i<=c; ++i){
        ll ans = f(n);

        vector<int> v = m[i];
        int V = v.size();
        rep(j,V-1){
            int b = v[j+1]-1-v[j];
            ans -= f(b);
        }

        cout << ans << endl;
    }
    return 0;
}
