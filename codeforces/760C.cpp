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

    vector<int> p(n);
    rep(i,n)
    {
        scanf(" %d", &p[i]);
        --p[i];
    }

    int B=0;
    rep(i,n)
    {
        int b;
        scanf(" %d", &b);
        B += b;
    }

    int ans = !(B%2);

    int c=0;
    vector<bool> vis(n,false);
    rep(i,n)
    {
        if(vis[i]) continue;
        ++c;

        int now=i;
        vis[now]=true;
        while(!vis[p[now]])
        {
            vis[p[now]]=true;
            now=p[now];
        }
    }

    if(c>1) ans += c;

    printf("%d\n", ans);
    return 0;
}
