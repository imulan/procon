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
    int k,t;
    scanf(" %d %d", &k, &t);

    int max_cake=0;
    rep(i,t)
    {
        int a;
        scanf(" %d", &a);
        max_cake = max(max_cake,a);
    }

    int ans=0;
    if(max_cake>=(k+1)/2+1) ans = 2*max_cake-k-1;
    printf("%d\n", ans);
    return 0;
}
