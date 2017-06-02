#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

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

const int INF=1010101010;

// (pos, ans_idx)
vector<pi> Q[100001];

int main()
{
    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);

    vector<int> a(n),b(n);
    rep(i,n) scanf(" %d %d", &a[i], &b[i]);

    vector<int> p(m),l(m),r(m);
    vector<int> pos;
    rep(i,m)
    {
        scanf(" %d %d %d", &p[i], &l[i], &r[i]);
        pos.pb(p[i]);
        Q[l[i]-1].pb(pi(p[i],2*i));
        Q[r[i]].pb(pi(p[i],2*i+1));
    }

    pos.pb(-1);
    pos.pb(0);
    pos.pb(INF);
    sort(all(pos));
    pos.erase(unique(all(pos)),pos.end());
    int P = pos.size();

    map<int,int> pos2id;
    rep(i,P) pos2id[pos[i]] = i;

    vector<int> ans(2*m);
    BIT bit(P);
    rep(q,n+1)
    {
        if(q>0)
        {
            int lidx = lower_bound(all(pos),a[q-1])-pos.begin();
            int ridx = upper_bound(all(pos),b[q-1])-pos.begin();

            bit.add(lidx,1);
            bit.add(ridx,-1);
        }

        for(const auto &query:Q[q])
        {
            int x = query.fi;
            int ans_idx = query.se;

            int v = bit.sum(pos2id[x]);
            ans[ans_idx] = v;
        }
    }

    rep(i,m) printf("%d\n", ans[2*i+1]-ans[2*i]);
    return 0;
}
