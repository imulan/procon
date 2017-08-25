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

int solve()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> h(n+1),c(m);
    rep(i,n) scanf(" %d", &h[i+1]);
    rep(i,m) scanf(" %d", &c[i]);

    h[0]=19191919;
    sort(all(h),greater<int>());

    BIT bit(n+1);
    rep(i,m)
    {
        if(n<c[i]) return i;

        int x = h[c[i]]+bit.sum(c[i]);
        if(x<=0) return i;

        // x+1 と x の境界を見つける(lのindexがx+1以上の値の右端)
        int l=0,r=c[i];
        while(r-l>1)
        {
            int mid = (l+r)/2;
            int tx = h[mid]+bit.sum(mid);
            if(tx>x) l=mid;
            else r=mid;
        }
        bit.add(1,-1);
        bit.add(l+1,1);

        // x と x-1 の境界を見つける(lのindexがxの値の右端)
        int same = c[i]-l;
        l=0,r=n+1;
        while(r-l>1)
        {
            int mid = (l+r)/2;
            int tx = h[mid]+bit.sum(mid);
            if(tx>=x) l=mid;
            else r=mid;
        }
        bit.add(l-same+1,-1);
        bit.add(l+1,1);
    }
    return m;
}

int main()
{
    printf("%d\n", solve());
    return 0;
}
