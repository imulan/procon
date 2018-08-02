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

using P = pair<ll,int>;

const ll INF = 2000000000000000020LL;

inline ll mul(ll x, ll y){
    // x*y>INF
    if(x>INF/y) return INF;
    return x*y;
}

int main(){
    int n;
    ll k;
    cin >>n >>k;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    vector<P> v;
    int idx = 0;
    while(idx<n){
        if(a[idx]==1){
            int st = idx;
            while(idx<n && a[idx]==1) ++idx;
            v.pb({1,idx-st});
        }
        else{
            v.pb({a[idx],1});
            ++idx;
        }
    }
    int V = v.size();

    ll ans = 0;
    rep(i,V){
        if(v[i].fi==1){
            for(int num=1; num<=v[i].se; ++num){
                ll p=1, s=num;
                if(p<=k*s && p%k==0) ++ans;

                for(int j=i+1; j<V; ++j){
                    if(v[j].fi==1){
                        ll ns = s+v[j].se;
                        if(k*s<p && p<=k*ns && p%k==0) ++ans;
                        s = ns;
                    }
                    else{
                        p = mul(p,v[j].fi);
                        s += v[j].fi;
                        if(p == k*s) ++ans;
                    }
                    if(p>=INF) break;
                }
            }
        }
        else{
            ll p=1, s=0;
            for(int j=i; j<V; ++j){
                if(v[j].fi==1){
                    ll ns = s+v[j].se;
                    if(k*s<p && p<=k*ns && p%k==0) ++ans;
                    s = ns;
                }
                else{
                    p = mul(p,v[j].fi);
                    s += v[j].fi;
                    if(p == k*s) ++ans;
                }
                if(p>=INF) break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
