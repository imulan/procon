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

    vector<pi> r(n);
    rep(i,n)
    {
        int w,h;
        scanf(" %d %d", &w, &h);
        r[i]=pi(w,-h);
    }
    sort(all(r));

    vector<int> y(n);
    rep(i,n) y[i]=-r[i].se;

    int ans=0;
    int t=0;
    for(int i=n-1; i>=0; --i)
    {
        if(t<=y[i])
        {
            t=y[i];
            ++ans;
        }
    }

    printf("%d\n", ans);
    return 0;
}
