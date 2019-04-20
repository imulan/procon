#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second


struct BIT{
    int n;
    vector<ll> bit;
    BIT(int _n){
        n = _n;
        bit = vector<ll>(n+1,0);
    }

//    [1,i]
    ll sum(int i){
        if(i<=0) return 0;

        ll s = 0;
        while(i>0){
            s += bit[i];
            i -= i&-i;
        }
        return s;
    }

    void add(int i, ll x){
        while(i<=n){
            bit[i] += x;
            i += i&-i;
        }
    }

    ll sum(int l, int r){
        return sum(r)-sum(l-1);
    }
};

int main(){
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    BIT pre(n+3),suf(n+3);
    rep(i,n) suf.add(a[i],1);

    ll ans = 0;
    rep(i,n){
        suf.add(a[i],-1);
        ll tmp = pre.sum(a[i]+1,n)*suf.sum(1,a[i]-1);
        ans += tmp;
        pre.add(a[i],1);
    }

    cout << ans << endl;
    return 0;
}


