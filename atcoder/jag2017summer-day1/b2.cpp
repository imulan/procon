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

const int INF = 19191919;

int LIS(const vector<int> &a)
{
    int n = a.size();
    vector<int> dp(n,INF);
    rep(i,n) *lower_bound(all(dp),a[i]) = a[i];
    return lower_bound(all(dp),INF)-dp.begin();
}

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

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<int> x(n);
    BIT bit(n);
    for(int i=1; i<=n; ++i) bit.add(i,1);
    for(int i=n-1; i>=0; --i)
    {
        int l=0, r=n;
        while(r-l>1)
        {
            int m = (l+r)/2;
            if(bit.sum(m)>a[i]) r=m;
            else l=m;
        }
        bit.add(r,-1);
        x[n-1-l] = i;
    }

    printf("%d\n", LIS(x));
    return 0;
}
