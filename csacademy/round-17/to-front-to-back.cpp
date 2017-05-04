#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
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

    vector<int> pos(n);
    rep(i,n) pos[a[i]] = i;

    vector<int> p(n-1);
    rep(i,n-1) p[i] = (pos[i]<pos[i+1]);

    int st=0;
    int l=0,r=0,ans=n-1;
    int M=0;
    while(st<n-1)
    {
        if(p[st]==1)
        {
            int ed=st;
            while(ed<n-1 && p[ed]==1) ++ed;

            if(ed-st>M)
            {
                M = ed-st;
                ans = n-1-M;

                l = st;
                r = ed;
            }

            st=ed;
        }
        else ++st;
    }

    // printf("l,r %d %d\n", l,r);

    printf("%d\n", ans);
    for(int i=l-1; i>=0; --i) printf("%d 0\n", i+1);
    for(int i=r+1; i<n; ++i) printf("%d 1\n", i+1);
    return 0;
}
