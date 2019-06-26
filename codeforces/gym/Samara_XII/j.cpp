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

using vl = vector<ll>;

int main(){
    int n;
    scanf(" %d", &n);

    vector<vl> p(n);
    vl s(n);
    rep(i,n){
        vl v(3);
        rep(j,3) scanf(" %lld", &v[j]);
        sort(all(v));

        p[i] = v;
        s[i] = v[0]+v[1];
    }
    sort(all(s));

    rep(i,n){
        ll t = accumulate(all(p[i]), 0LL);
        int ans = upper_bound(all(s), t-2) - s.begin();
        if(p[i][2]>=2) --ans;

        printf("%d%c", ans, " \n"[i==n-1]);
    }
}
