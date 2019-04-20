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
const ll mod = 1e9+7;

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x, mod-2);
}

const int N = 42;
ll f[N];
ll finv[N];

int h,w;
map<vi,ll> m[N][N];

ll dfs(int num, int rem, const vi &v){
    if(m[num][rem].count(v)) return m[num][rem][v];

    int sum_v = 0;
    rep(i,w) sum_v += v[i];

    if(num==w+1){
        if(rem==0 && sum_v==0) return f[h];
        return 0;
    }

    ll ret = 0;
    vi t(v);
    rep(i,rem+1){
        int need = num*i;
        if(sum_v < need) continue;

        int r = sum_v-need;
        int field = w*(rem-i);
        if(r>field) continue;


        printf(" %d, %d ",num,rem);
        dbg(v);
        dbg(i);

        bool ok = true;
        rep(j,num){
            --t[w-1-j];
            if(t[w-1-j]<0) ok = false;
        }
        sort(all(t));
        // dbg(t);

        if(ok) (ret += dfs(num+1,rem-i,t)*finv[i]) %= mod;
    }
    return m[num][rem][v] = ret;
}

int main(){
    f[0]=1;
    rep(i,N-1) f[i+1] = (f[i]*i)%mod;
    rep(i,N) finv[i] = mod_inv(f[i]);

    cin >>h >>w;
    vi a(w);
    rep(i,w) cin >>a[i];
    sort(all(a));
    cout << dfs(0,h,a) << endl;
    return 0;
}
