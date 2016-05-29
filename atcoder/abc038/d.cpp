#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
const int INF=12345678;

int main()
{
    int n;
    cin >>n;
    vector<pi> p(n);
    rep(i,n) scanf(" %d %d", &p[i].fi, &p[i].se);
    rep(i,n) p[i].se=-p[i].se;

    sort(all(p));

    vector<int> h(n);
    rep(i,n) h[i]=-p[i].se;

    vector<int> dp(n+1,INF);
    rep(i,n)
    {
        *lower_bound(all(dp),h[i])=h[i];
    }
    printf("%d\n", lower_bound(all(dp),INF)-dp.begin());

    return 0;
}
