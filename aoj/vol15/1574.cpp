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

int main(){
    int n,m;
    cin >>n >>m;

    const int INF = 10000000;
    vector<int> a;
    a.pb(-INF);
    rep(i,m){
        int v;
        cin >>v;
        a.pb(v);
    }
    a.pb(INF);

    int idx = 0;
    int ans = 0;
    for(int i=1; i<=n; ++i){
        ans = max(ans, min(i-a[idx], a[idx+1]-i));
        if(a[idx+1] == i) ++idx;
    }
    cout << ans << endl;
    return 0;
}
