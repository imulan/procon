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

const ll INF = 1100000100000100000;

int main(){
    int n,R;
    ll k;
    scanf(" %d %d %lld", &n, &R, &k);
    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    vector<ll> d(n+1);
    rep(i,n){
        int l = max(0,i-R), r = min(n-1,i+R);
        d[l] += a[i];
        d[r+1] -= a[i];
    }
    rep(i,n) d[i+1] += d[i];

    auto check = [&](ll x){
        ll ct = 0;

        vector<ll> add(n);
        ll cov = 0;
        rep(i,n){
            if(d[i]+cov<x){
                add[i] = x-d[i]-cov;
                cov += add[i];
                ct += add[i];
            }

            if(ct>k) return false;

            int sub_idx = i-2*R;
            if(sub_idx>=0) cov -= add[sub_idx];
        }
        return true;
    };

    ll l=0, r=INF;
    while(r-l>1){
        ll m = (l+r)/2;
        if(check(m)) l = m;
        else r = m;
    }
    printf("%lld\n",l);
    return 0;
}
