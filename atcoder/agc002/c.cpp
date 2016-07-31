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

int main()
{
    int n,L;
    cin >>n >>L;
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int idx=-1;
    rep(i,n-1)
    {
        if(a[i]+a[i+1]>=L)
        {
            idx=i;
            break;
        }
    }

    if(idx>=0)
    {
        printf("Possible\n");

        vector<int> ans;
        rep(i,idx) ans.pb(i+1);
        for(int i=n-2; i>=idx; --i) ans.pb(i+1);

        rep(i,ans.size()) printf("%d\n", ans[i]);
    }
    else printf("Impossible\n");

    return 0;
}
