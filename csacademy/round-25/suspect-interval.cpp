#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int solve()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    sort(all(a));

    if(n==1) return 100000;

    int ret=1;
    ret = max(ret,(a[1]-1)-1+1);
    ret = max(ret,100000-(a[n-2]+1)+1);
    for(int i=1; i<n-1; ++i) ret = max(ret,(a[i+1]-1)-(a[i-1]+1)+1);

    return ret;
}

int main()
{
    printf("%d\n", solve());
    return 0;
}
