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

void solve()
{
    int n;
    scanf(" %d", &n);

    vector<int> a(n+1),b(n+1);
    int suma=0,sumb=0;
    rep(i,n+1)
    {
        scanf(" %d", &a[i]);
        suma+=a[i];
    }
    rep(i,n+1)
    {
        scanf(" %d", &b[i]);
        sumb+=b[i];
    }

    // ムリ
    if(suma!=n || sumb!=n)
    {
        printf("NO\n");
        return;
    }

    int edges=0;
    rep(i,n+1) edges += i*(a[i]-b[i]);

    if(edges!=0)
    {
        printf("NO\n");
        return;
    }

    int in[50],out[50];

    int idx=0;
    rep(i,n)
    {
        while(idx<=n && a[idx]==0) ++idx;

        in[i] = idx;
        --a[idx];
    }

    idx=0;
    rep(i,n)
    {
        while(idx<=n && b[idx]==0) ++idx;

        out[i] = idx;
        --b[idx];
    }
    reverse(out,out+n);

    priority_queue<pi> que;
    rep(i,n)if(in[i]>0) que.push(pi(in[i],i));

    int e[50][50]={};
    rep(i,n)
    {
        vector<pi> poped;

        rep(j,out[i])
        {
            pi v=que.top();
            que.pop();

            int to=v.se;
            e[i][to]=1;
        
            --v.fi;
            if(v.fi>0) poped.pb(v);
        }

        rep(j,poped.size()) que.push(poped[j]);
    }

    // output
    printf("YES\n");
    rep(i,n)
    {
        rep(j,n)
        {
            if(j) printf(" ");
            printf("%d", e[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    solve();
    return 0;
}
