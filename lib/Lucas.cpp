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
