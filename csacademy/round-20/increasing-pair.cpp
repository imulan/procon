#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

int main()
{
    int n;
    scanf(" %d", &n);
    vector<pi> p(n);
    rep(i,n)
    {
        int a;
        scanf(" %d", &a);
        p[i] = pi(-a,i);
    }
    sort(all(p),greater<pi>());

    set<int> idx;
    rep(i,n) idx.insert(i);

    int ans=-1;
    rep(i,n-1)
    {
        int r = p[i].se;
        idx.erase(r);

        int mr = *idx.rbegin();
        if(mr-r>0) ans=max(ans,mr-r);
    }

    printf("%d\n", ans);
    return 0;
}
