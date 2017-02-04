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

typedef pair<int,int> pi;
vector<pi> range[101010];

int main()
{
    int N,M;
    scanf(" %d %d", &N, &M);
    rep(i,N)
    {
        int l,r;
        scanf(" %d %d", &l, &r);
        range[r-l+1].pb(pi(l,r));
    }

    BIT bit(M+1);
    int up_d=N;
    for(int d=1; d<=M; ++d)
    {
        for(pi p:range[d])
        {
            bit.add(p.fi,1);
            bit.add(p.se+1,-1);
            --up_d;
        }

        int ct=0;
        for(int i=d; i<=M; i+=d) ct+=bit.sum(i);

        printf("%d\n", up_d + ct);
    }
    return 0;
}
