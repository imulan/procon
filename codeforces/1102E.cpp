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

const int mod = 998244353;

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> u;
    vector<int> a(n);
    rep(i,n){
        scanf(" %d", &a[i]);
        u.pb(a[i]);
    }

    sort(all(u));
    u.erase(unique(all(u)), u.end());
    int U = u.size();

    rep(i,n) a[i] = lower_bound(all(u), a[i])-u.begin();

    vector<int> r(U);
    rep(i,n) r[a[i]] = i;

    set<int> s;
    int ct = 0;
    rep(i,n){
        s.insert(a[i]);
        if(r[a[i]] == i) s.erase(a[i]);
        if(s.empty()) ++ct;
    }

    int ans = 1;
    rep(i,ct-1) (ans *= 2) %= mod;
    printf("%d\n", ans);
    return 0;
}
