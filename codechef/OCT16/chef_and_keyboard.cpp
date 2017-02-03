#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

vector<int> divisor(int n)
{
    vector<int> ret;
    for(int i=1; i*i<=n; ++i)
    {
        if(n%i==0)
        {
            ret.pb(i);
            if(i != n/i) ret.pb(n/i);
        }
    }
    sort(all(ret));
    return ret;
}

int main()
{
    int T;
    scanf(" %d",&T);
    while(T--)
    {
        int n,m,c;
        scanf(" %d %d %d",&n,&m,&c);

        vector<int> d=divisor(c);
        int ans=0;
        rep(i,d.size())
        {
            int x=d[i];
            int y=c/x;

            if(x<=n && y<=m) ++ans;
        }

        printf("%d\n", ans);
    }
    return 0;
}
