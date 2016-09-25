#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    rep(i,n)
    {
        scanf(" %d", &a[i]);
        --a[i];
    }

    int ans=0;

    rep(i,n)
    {
        // printf("%d, %d, %d\n", i,a[i],a[a[i]]);
        if(a[a[i]]==i && i<a[i]) ++ans;
    }

    printf("%d\n", ans);
    return 0;
}
