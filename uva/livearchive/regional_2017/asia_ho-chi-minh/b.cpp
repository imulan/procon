#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16

#define pb push_back

map<ll,int> factorize(ll n){
    ll t = n;
    map<ll,int> ret;
    for(int i=2; i*i<=n; ++i){
        while(t%i==0){
            ++ret[i];
            t /= i;
        }
    }
    if(t>1) ++ret[t];
    return ret;
}

ll extgcd(ll a, ll b, ll &x, ll &y){
    ll g = a;
    x = 1;
    y = 0;
    if(b!=0) g = extgcd(b,a%b,y,x), y -= (a/b)*x;
    return g;
}

// a^(-1) mod m
// aとmは互いに素でなければならない
ll mod_inverse(ll a, ll m){
    assert(__gcd(a,m)==1);
    ll x,y;
    ll g = extgcd(a,m,x,y);
    while(x<0) x+=m;
    return x%m;
}

void makeFF(int p, int q, vector<ll> &fact, vector<ll> &ifact){
    ll PQ = 1;
    rep(_,q) PQ*=p;

    fact[0] = 1;
    for(int i=1; i<=PQ; ++i){
        if(i%p==0) fact[i] = fact[i-1];
        else fact[i] = (fact[i-1]*i)%PQ;
    }
    rep(i,PQ+1) ifact[i] = mod_inverse(fact[i], PQ);
}

// nCr mod p^q
ll nCrModPowpq(ll n, ll r, int p, int q){
    if(n<0 || r<0 || r>n) return 0;

    ll PQ = 1;
    rep(_,q) PQ*=p;

    vector<ll> fact(PQ+1),ifact(PQ+1);
    makeFF(p, q, fact, ifact);

    ll z = n-r;

    ll e0 = 0;
    for(ll i=n/p; i>0; i/=p) e0 += i;
    for(ll i=r/p; i>0; i/=p) e0 -= i;
    for(ll i=z/p; i>0; i/=p) e0 -= i;

    ll em = 0;
    for(ll i=n/PQ; i>0; i/=p) em += i;
    for(ll i=r/PQ; i>0; i/=p) em -= i;
    for(ll i=z/PQ; i>0; i/=p) em -= i;

    ll ret = 1;
    while(n>0){
        (ret *= fact[n%PQ]) %= PQ;
        (ret *= ifact[r%PQ]) %= PQ;
        (ret *= ifact[z%PQ]) %= PQ;
        n /= p; r /= p; z /= p;
    }
    rep(_,e0) (ret *= p) %= PQ;
    if(!(p==2 && q>=3) && (em&1)) ret = (PQ-ret)%PQ;
    return ret;
}

// 中国剰余定理を計算((mod,reminder)を渡す)
ll solveCRT(const vector<ll> &mods, const vector<ll> &rems){
    int SZ = mods.size();
    ll P = 1;
    rep(i,SZ) P *= mods[i];

    ll ret = 0;
    rep(i,SZ){
        ll pp = P/mods[i];
        ret += (rems[i]*mod_inverse(pp,mods[i]))%P * pp;
        ret %= P;
    }
    return ret;
}

// Lucasの定理の拡張
ll nCrModm(ll n, ll r, int m)
{
    vector<ll> mods,rems;
    for(const auto &f:factorize(m)){
        ll p = f.fi, q = f.se;
        ll P = 1;
        rep(_,q) P*=p;

        mods.pb(P);
        rems.pb(nCrModPowpq(n,r,p,q));
    }
    return solveCRT(mods, rems);
}



ll mod_pow(ll a,ll n,ll mod){
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll fac[2000010];
ll f[1000010],e[1000010];
ll finv[1000010];
int tt[1000010];

ll comb(ll n,ll r,ll mod){
  if(n<0||r<0||n<r)return 0;
  ll e1 = e[n], e2 = e[r] ,e3 = e[n-r];
  // ll a1=mod_fact(n,mod,e1); ll a2=mod_fact(r,mod,e2); ll a3=mod_fact(n-r,mod,e3);
  // ll a1 = fac[n], a2 = fac[r], a3 = fac[n-r];

  if(e1 > e2+e3)return 0;
  else return (fac[n]*finv[r]%mod)*finv[n-r]%mod;
}

ll t;
ll n,mod;

int main(){
  cin>>t;
  while(t--){
    cin>>n>>mod;

    int resa=0,resb=0,resc=0;
    if(n%2==0){
      resa=nCrModm(n,n/2,mod)%mod;
    }

    { // b=0
      (resb+=1)%=mod;
    }
    if(n!=2){ // b=1
      (resb+=nCrModm(n,1,mod))%=mod;
    }
    repl(b,2,n+1){
      if(n%2==0&&n/2==b)continue;
      int r=n-b;
      int rest=r+1-b;
      if(rest<0)continue;
      (resb+=nCrModm(rest+b,b,mod))%=mod;
    }
    cout<<(resa+resb)%mod<<endl;
  }
  return 0;
}
