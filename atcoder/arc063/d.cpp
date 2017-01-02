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
    int n,t;
    scanf(" %d %d", &n, &t);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int B=0;
    int max_a = a[n-1];
    int ans=1;
    for(int i=n-2; i>=0; --i)
    {
        if(B < max_a-a[i])
        {
            B = max_a-a[i];
            ans=1;
        }
        else if(B == max_a-a[i]) ++ans;

        max_a = max(max_a,a[i]);
    }

    printf("%d\n", ans);
    return 0;
}
