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
    int n,k;
    scanf(" %d %d", &n, &k);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int ans=0;
    vector<int> b(n);
    b[0]=a[0];
    for(int i=1; i<n; ++i)
    {
        if(a[i]+b[i-1]<k) b[i]=k-b[i-1];
        else b[i]=a[i];

        ans+=b[i]-a[i];
    }

    printf("%d\n", ans);
    rep(i,n)
    {
        if(i) printf(" ");
        printf("%d", b[i]);
    }
    printf("\n");
    return 0;
}
