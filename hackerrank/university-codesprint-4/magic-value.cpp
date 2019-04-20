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

const ll inf = LLONG_MAX/1000000;

const ll mod = 1e9+7;

ll magic(const vector<ll> &v){
    int n = v.size();
    set<ll> s;

    rep(i,n)for(int j=i; j<n; ++j){
        ll G = v[i];
        for(int k=i; k<=j; ++k) G = __gcd(G,v[k]);
        s.insert((i+1)*G);
    }

    ll MAX = *s.rbegin();
    ll MIN = *s.begin();
    // printf(" %lld - %lld \n", MAX,MIN);
    return n*(MAX-MIN);
}

int main(){
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    // make GCD
    vector<vector<ll>> GCD(n,vector<ll>(n));
    rep(i,n){
        GCD[i][i] = a[i];
        for(int j=i+1; j<n; ++j){
            if(GCD[i][j-1]==0 || a[j]==0) GCD[i][j] = 0;
            else GCD[i][j] = __gcd(GCD[i][j-1], a[j]);
        }
    }

    // make v
    vector<vector<ll>> v(n,vector<ll>(n));
    rep(i,n){
        rep(j,i) v[i][j] = inf;
        v[i][i] = a[i];

        for(int j=i+1; j<n; ++j){
            v[i][j] = max(v[i][j-1], (j-i+1)*a[j]);
        }
    }
    // dbg(v);

    // calc
    ll ans = 0;

    rep(j,n){
        ll max_v = v[j][j];
        for(int i=j-1; i>=0; --i){
            max_v = max(max_v, v[i][j]);
            ll min_v = GCD[i][j];

            ll add = ((max_v-min_v)%mod * (j-i+1));
            add %= mod;
            // printf(" %d %d : %lld - %lld : add %lld\n",i,j,max_v,min_v, add);

            (ans += add) %= mod;
        }
    }

    // rep(i,n)for(int j=i+1; j<n; ++j){
    //     ll max_v = 0;
    //     for(int k=i; k<=j; ++k) max_v = max(max_v, v[k][j]);
    //     ll min_v = GCD[i][j];

    //     ll add = ((max_v-min_v)%mod * (j-i+1));
    //     add %= mod;
    //     // printf(" %d %d : %lld - %lld : add %lld\n",i,j,max_v,min_v, add);

    //     (ans += add) %= mod;
    // }
    cout << ans << endl;
    return 0;
}
