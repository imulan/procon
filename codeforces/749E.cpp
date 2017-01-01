#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

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

ll invcount(int n, const vector<int>& a)
{
    ll ret=0;
    BIT b(n);
    for(int i=n; i>=1; --i)
    {
        ret+=b.sum(a[i]);
        b.add(a[i],1);
    }
    return ret;
}

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n+1);
    for(int i=1; i<=n; ++i) scanf(" %d", &a[i]);

    // 全体の反点数の計算
    double ans = invcount(n,a)*0.5*n*(n+1);

    // 区間の長さがiの部分列の個数はn-i+1なのでそれを利用してシャッフル時の期待値を計算
    for(int i=1; i<=n; ++i) ans+=0.25*i*(i-1) * (n-i+1);

    // inv(l,r)の和を計算
    BIT bit(n);
    vector<ll> b(n+1,0);
    bit.add(a[n],1);
    for(int i=n-1; i>=1; --i)
    {
        b[i] = b[i+1]+bit.sum(a[i]);
        bit.add(a[i],n-i+1);
    }
    for(int i=1; i<=n; ++i) ans-=b[i];

    ans /= 0.5*n*(n+1);
    printf("%.12f\n", ans);
    return 0;
}
