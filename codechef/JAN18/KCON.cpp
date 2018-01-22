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

ll solve(){
    int n,k;
    cin >>n >>k;
    vector<ll> a(n+1);
    rep(i,n) cin >>a[i];

    ll ret = -LLONG_MAX;
    ll m = a[0];
    for(int i=1; i<=n; ++i){
        ret = max(ret,m);
        m = max(m,0LL)+a[i];
    }

    if(k>1){
        vector<ll> pre(n),suf(n);
        pre[0] = a[0];
        rep(i,n-1) pre[i+1] = pre[i]+a[i+1];
        suf[n-1] = a[n-1];
        for(int i=n-2; i>=0; --i) suf[i] = suf[i+1]+a[i];

        ll one = pre[n-1];
        ll P = *max_element(all(pre)), S = *max_element(all(suf));
        
        if(one>0) ret = max(ret, P+S+one*(k-2));
        else ret = max(ret, P+S);
    }
    return ret;
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
