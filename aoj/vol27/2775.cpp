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

ll query(int x)
{
    printf("? 1 %d\n", x); fflush(stdout);
    ll ret;
    scanf(" %lld", &ret);
    return ret;
}

int main()
{
    int n;
    scanf(" %d", &n);

    vector<int> ans(n);

    BIT bit(n);
    for(int i=1; i<=n; ++i) bit.add(i,1);

    ll x = query(n);
    for(int i=n-1; i>0; --i)
    {
        ll y = query(i);
        ll diff = x-y;

        int l=0, r=n;
        while(r-l>1)
        {
            int m = (l+r)/2;
            if(bit.sum(n)-bit.sum(m)<=diff) r=m;
            else l=m;
        }

        // dbg(l);dbg(r);
        ans[i] = r;
        bit.add(r,-1);
        x = y;
    }

    for(int i=1; i<=n; ++i) if(bit.sum(i)-bit.sum(i-1)>0) ans[0] = i;

    printf("!");
    rep(i,n) printf(" %d", ans[i]);
    printf("\n");
    return 0;
}
