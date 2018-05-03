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

const ll mod = 1e9+7;

int len[11][91][201][201];

int ct[5]={};
ll sum[5]={};

inline int LEN(int x){
    if(x==0) return 0;
    if(x<10) return 1;
    if(x<100) return 2;
    if(x<1000) return 3;
    return 4;
}

ll f[202];
ll C[202][202];

ll pre_P[202];

ll TEN[2000];


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
    return mod_pow(x,mod-2);
}


int main(){
    f[0] = 1;
    rep(i,202-1) f[i+1] = (f[i]*(i+1))%mod;

    rep(i,202){
        rep(j,i+1){
            C[i][j] = f[i];
            (C[i][j] *= mod_inv(f[j])) %= mod;
            (C[i][j] *= mod_inv(f[i-j])) %= mod;
        }
    }

    rep(i,202){
        rep(j,i+1) (pre_P[i] += (f[i]*mod_inv(f[i-j]))%mod) %= mod;
    }

    TEN[0] = 1;
    rep(i,2000-1) TEN[i+1] = (TEN[i]*10)%mod;

    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    rep(i,n){
        ++ct[LEN(a[i])];
        sum[LEN(a[i])] += a[i];
    }

    ll ans = 0;
    for(int d=1; d<=4; ++d){
        --ct[d];

        ll p = 0;
        rep(i0,ct[0]+1)rep(i1,ct[1]+1)rep(i2,ct[2]+1)rep(i3,ct[3]+1)rep(i4,ct[4]+1){
            int L = i0 + i1 + 2*i2 + 3*i3 + 4*i4;

            ll add = 1;
            (add *= C[ct[1]][i1]) %= mod;
            (add *= C[ct[2]][i2]) %= mod;
            (add *= C[ct[3]][i3]) %= mod;
            (add *= C[ct[4]][i4]) %= mod;

            int rsz = i0+i1+i2+i3+i4;
            (add *= f[rsz]) %= mod;

            // 全部選ぶ必要はない
            int lsz = n-1-rsz;
            if(ct[0]==1 && i0==0) (add *= (pre_P[lsz]-pre_P[lsz-1]+mod)%mod) %= mod;
            else (add *= pre_P[lsz]) %= mod;

            (p += (TEN[L]*add)%mod) %= mod;
        }

        (ans += sum[d]*p) %= mod;
        ++ct[d];
    }
    cout << ans << endl;
    return 0;
}
