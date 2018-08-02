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

using M = map<ll,int>;
using P = pair<ll,int>;

M factorize(ll n){
    map<ll,int> ret;
    ll t = n;
    for(ll i=2; i*i<=n; ++i){
        while(t%i==0){
            ++ret[i];
            t/=i;
        }
    }
    if(t>1) ++ret[t];
    return ret;
}

M merge(M a, M b){
    for(const auto &p:b) a[p.fi] += p.se;
    return a;
}

ll l,r,x,y;

bool IN(ll v){
    return l<=v && v<=r;
}

ll lcm(ll p, ll q){
    return p*q/__gcd(p,q);
}

vector<P> f;
int F;
ll ans = 0;
void dfs(int d, ll a){
    if(d==F){
        ll b = x*y/a;
        if(IN(a) && IN(b) && __gcd(a,b)==x && lcm(a,b)==y) ++ans;
        return;
    }

    int lim = f[d].se;
    ll mul = 1;
    rep(i,lim+1){
        dfs(d+1, a*mul);
        mul *= f[d].fi;
    }
}

int main(){
    cin >>l >>r >>x >>y;

    M tmp = merge(factorize(x), factorize(y));
    f = vector<P>(tmp.begin(), tmp.end());
    F = f.size();

    dfs(0,1);
    cout << ans << endl;
    return 0;
}
