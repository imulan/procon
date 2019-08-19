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

const ll LIM = 1000000000000000LL;

int s(ll x){
    int ret = 0;
    while(x){
        ret += x%10;
        x/=10;
    }
    return ret;
}

int main(){
    int k;
    cin >>k;

    vector<ll> v;
    rep(i,15){
        string nine(i,'9');
        for(int j=1; j<=999; ++j){
            string t = to_string(j) + nine;
            ll val = stoll(t);
            if(val <= LIM) v.pb(val);
        }
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    sort(all(v), [](const ll &lh, const ll &rh){
        return (lh*s(rh) == rh*s(lh)) ? lh<rh : lh*s(rh) < rh*s(lh);
    });

    vector<ll> ans;
    ll pre = 0;
    for(ll i:v){
        if(pre<i){
            pre = i;
            ans.pb(i);
        }
    }
    rep(i,k) cout << ans[i] << endl;
    return 0;
}
