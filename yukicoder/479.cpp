#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<pi> e(m);
    rep(i,m)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        e[i]=pi(a,b);
    }

    sort(all(e));

    vector<int> bought(n,0);

    for(int i=m-1; i>=0; --i)
    {
        int a=e[i].fi, b=e[i].se;
        if(!bought[a] && !bought[b]) bought[a]=1;
    }

    reverse(all(bought));
    int idx=0;
    while(idx<n && bought[idx]==0) ++idx;
    while(idx<n) printf("%d", bought[idx++]);
    printf("\n");
    return 0;
}
