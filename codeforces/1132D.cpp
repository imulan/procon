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

const ll INF = 2000000000002LL;

// (deadline, index)
using pi = pair<int,int>;

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<ll> a(n),b(n);
    rep(i,n) scanf(" %lld", &a[i]);
    rep(i,n) scanf(" %lld", &b[i]);

    auto check = [&](ll x){

        vector<vector<int>> deadline(k-1);
        rep(i,n)if(a[i]/b[i] < k-1){
            deadline[a[i]/b[i]].pb(i);
        }

        vector<ll> c(a);
        vector<int> upd(n,-1);

        int dpos = 0, didx = 0;
        rep(i,k-1){
            while(dpos<k-1){
                if(didx < deadline[dpos].size()) break;
                else{
                    ++dpos;
                    didx = 0;
                }
            }
            if(dpos == k-1) break;

            int idx = deadline[dpos][didx];
            ++didx;
            if(dpos < i) return false;

            int D = i-upd[idx];
            c[idx] -= b[idx]*(D-1);
            if(c[idx]<0) return false;

            c[idx] -= b[idx];
            c[idx] += x;
            if(c[idx]<0) return false;

            ll nx = c[idx]/b[idx]+1;
            if(i+nx < k-1) deadline[i+nx].pb(idx);

            upd[idx] = i;
            // dbg(c); dbg(upd);
        }

        while(dpos<k-1){
            if(didx < deadline[dpos].size()) break;
            else{
                ++dpos;
                didx = 0;
            }
        }

        return dpos==k-1;
    };

    ll ng = -1, ok = INF;
    while(ok-ng>1){
        ll mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    ll ans = ok;
    if(ok == INF) ans = -1;
    printf("%lld\n", ans);
    return 0;
}
