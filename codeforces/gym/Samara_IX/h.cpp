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

struct BIT{
    // [1,n]
    int n; vector<ll> bit;
    // 初期化
    BIT(int _n){
        n = _n;
        bit = vector<ll>(n+1,0);
    }
    // sum of [1,i]
    ll sum(int i){
        ll s = 0;
        while(i>0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    // add x in i-th element
    void add(int i, ll x){
        while(i<=n){
            bit[i] += x;
            i += i & -i;
        }
    }
};

int main(){
    int n;
    cin >>n;

    vector<vector<int>> s(n+1),e(n+1);
    rep(i,n){
        int a,b;
        cin >>a >>b;
        s[a].pb(i+1);
        e[b].pb(i+1);
    }

    BIT b(n+1);
    vector<int> ans(n);
    for(int i=1; i<=n; ++i){
        for(int j:s[i]) b.add(j,1);

        int ng = 0, ok = n+1;
        while(ok-ng>1){
            int mid = (ng+ok)/2;
            if(b.sum(mid) >= i) ok = mid;
            else ng = mid;
        }

        if(b.sum(ok) == i) ans[i-1] = ok;
        else ans[i-1] = -1;

        for(int j:e[i]) b.add(j,-1);
    }

    rep(i,n) cout << ans[i] << " \n"[i==n-1];
    return 0;
}
