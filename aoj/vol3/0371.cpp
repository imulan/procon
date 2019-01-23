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

vector<int> divisor(int n){
    vector<int> d;
    for(int i=1; i*i<=n; ++i){
        if(n%i==0){
            d.pb(i);
            if(i != n/i) d.pb(n/i);
        }
    }
    sort(all(d));
    return d;
}

int main(){
    int n;
    scanf(" %d", &n);
    vector<int> t(n);
    rep(i,n) scanf(" %d", &t[i]);

    int T = 0;
    rep(i,n) T = max(T, t[i]);

    vector<int> d = divisor(T);

    int ans = 0;
    rep(i,n) ans += (*lower_bound(all(d), t[i])) - t[i];
    printf("%d\n", ans);
    return 0;
}
