#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF= LLONG_MAX/3;
using pl = pair<ll,ll>;

int main()
{
    int n;
    scanf(" %d", &n);

    ll rl=INF, rr=0, bl=INF, br=0;

    vector<pl> p(n);
    multiset<ll> R,B;
    rep(i,n)
    {
        ll x,y;
        scanf(" %lld %lld", &x, &y);
        if(x>y) swap(x,y);

        p[i] = pl(x,y);

        rl=min(rl,x);
        rr=max(rr,x);
        bl=min(bl,y);
        br=max(br,y);

        R.insert(x);
        B.insert(y);
    }

    sort(all(p));
    priority_queue<pl> que;
    rep(i,n) que.push(pl(p[i].se,i));

    ll ans=(rr-rl)*(br-bl);
    while(!que.empty())
    {
        pl val=que.top();
        que.pop();

        int idx=val.se;
        auto ir = R.find(p[idx].fi);
        auto ib = B.find(p[idx].se);

        R.erase(ir);
        R.insert(p[idx].se);

        B.erase(ib);
        B.insert(p[idx].fi);

        rl = *R.begin();
        rr = *R.rbegin();
        bl = *B.begin();
        br = *B.rbegin();
        ans = min(ans,(rr-rl)*(br-bl));
    }

    cout << ans << endl;
    return 0;
}
