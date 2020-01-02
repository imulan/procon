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

void solve(){
    int n;
    scanf(" %d", &n);

    vector<int> r;
    r.pb(0);

    for(int i=1; i*i<=n; ++i){
        r.pb(i);
        r.pb(n/i);
    }
    sort(all(r));
    r.erase(unique(all(r)), r.end());

    int R = r.size();
    printf("%d\n", R);
    rep(i,R) printf("%d%c", r[i], " \n"[i==R-1]);
}

int main(){
    int t;
    scanf(" %d", &t);
    while(t--) solve();
    return 0;
}
