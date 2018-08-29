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

map<int,int> ct[11];

int digit(int x){
    int ret = 0;
    while(x>0){
        x/=10;
        ++ret;
    }
    return ret;
}

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    vector<int> d(n);
    rep(i,n) d[i] = digit(a[i]);

    rep(i,n){
        int v = a[i]%k;
        ++ct[d[i]][v];
    }

    ll ans = 0;
    rep(i,n){
        int v = a[i]%k;

        ll mul = 10;
        for(int j=1; j<=10; ++j){
            int x = (mul*a[i])%k;
            int y = (k-x)%k;

            int add = 0;
            if(ct[j].count(y)) add = ct[j][y];
            if(d[i]==j && v==y) --add;
            ans += add;

            (mul*=10)%=k;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
