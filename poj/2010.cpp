#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

struct BIT{
    // [1,n]
    int n; vector<ll> bit;
    // 初期化
    BIT(int _n){
        n = _n+1;
        bit = vector<ll>(n,0);
    }
    // sum of [1,i]
    ll sum(int i){
        ++i;
        ll s = 0;
        while(i>0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    // add x in i-th element
    void add(int i, ll x){
        ++i;
        while(i<=n){
            bit[i] += x;
            i += i & -i;
        }
    }
};

int solve()
{
    int N,C,F;
    scanf(" %d %d %d", &N, &C, &F);

    vector<pi> cow(C);
    rep(i,C) scanf(" %d %d", &cow[i].fi, &cow[i].se);
    sort(all(cow));

    // 失敗判定
    ll smallest_sum=0;
    rep(i,N) smallest_sum+=cow[i].se;
    if(smallest_sum>F) return -1;

    if(N==1)
    {
        for(int i=C-1; i>=0; --i)if(cow[i].se<=F) return cow[i].fi;
    }

    int B = (N-1)/2;

    ll lower_sum = 0;
    vector<int> taid;
    BIT bit(100001);
    rep(i,C-1-B)
    {
        bit.add(cow[i].se,1);
        taid.pb(cow[i].se);
    }
    sort(all(taid));
    rep(i,B) lower_sum += taid[i];

    ll upper_sum = 0;
    priority_queue<ll> que;
    for(int i=C-1; i>C-1-B; --i)
    {
        upper_sum += cow[i].se;
        que.push(cow[i].se);
    }

    if(lower_sum + cow[C-1-B].se + upper_sum<=F) return cow[C-1-B].fi;

    for(int i=C-1-B-1; i>=B; --i)
    {
        // upperを更新
        ll largest = que.top();
        que.pop();
        upper_sum -= largest;
        largest = min(largest, (ll)cow[i+1].se);
        upper_sum += largest;
        que.push(largest);

        // lowerを更新
        if(bit.sum(cow[i].se)<=B)
        {
            bit.add(cow[i].se,-1);

            int l=0, r=100000;
            while(r-l>1)
            {
                int m=(l+r)/2;

                if(bit.sum(m)>=B) r=m;
                else l=m;
            }

            lower_sum -= cow[i].se;
            lower_sum += r;
        }
        else bit.add(cow[i].se,-1);

        if(lower_sum + cow[i].se + upper_sum<=F) return cow[i].fi;
    }

    return -2;
}

int main()
{
    printf("%d\n", solve());
    return 0;
}
