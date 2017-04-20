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
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<ll> a(n+1);
    rep(i,n) scanf(" %lld", &a[i+1]);

    vector<bool> vis(n+1,false);
    vector<ll> ans(n+1);
    for(int i=1; i<=n; ++i)
    {
        if(vis[i]) continue;

        vector<ll> v;
        int now=i;
        v.pb(a[now]);
        vis[now]=true;
        while(!vis[a[now]])
        {
            now=a[now];
            vis[now]=true;
            v.pb(a[now]);
        }

        int cycle = v.size();

        ll v_sum = 0;
        rep(j,cycle) v_sum += v[j];

        ll tmp=0;
        int s=0,t=(m-1)%cycle;
        for(int j=s; j<=t; ++j) tmp+=v[j];
        // printf(" v_sum = %lld, tmp = %lld\n", v_sum, tmp);

        ans[i] = v_sum*((m-1)/cycle)+tmp;
        now = a[i];
        while(now!=i)
        {
            tmp-=v[s];
            (s+=1)%=cycle;
            (t+=1)%=cycle;
            tmp+=v[t];

            ans[now] = v_sum*((m-1)/cycle)+tmp;
            now = a[now];
        }
    }

    rep(i,n)
    {
        if(i) printf(" ");
        printf("%lld", ans[i+1]);
    }
    printf("\n");
    return 0;
}
