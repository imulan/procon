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

using vi = vector<int>;

ll f(ll x){
    return x*(x+1)/2;
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<vi> add(n+1,vi(3));
    rep(i,m){
        int q;
        ll k;
        scanf(" %d %lld", &q, &k);
        if(q==0){
            ll l=0, r=100000;
            while(r-l>1){
                ll mid = (l+r)/2;
                if(f(mid)<k) l=mid;
                else r=mid;
            }
            if(r<=n) ++add[r][q];
        }
        else{
            if(k<=n) ++add[k][q];
        }
    }

    ll ans = 0;
    ll a[3]={};
    for(ll i=1; i<=n; ++i){
        a[0] = add[i][0];
        for(int j=1; j<3; ++j) a[j] += add[i][j];

        ans += i*i*i;
        ans -= i*i*(a[0]+a[1]+a[2]);
        ans += i*(a[0]*a[1]+a[1]*a[2]+a[2]*a[0]);
        ans -= a[0]*a[1]*a[2];
    }
    printf("%lld\n", ans);
    return 0;
}
