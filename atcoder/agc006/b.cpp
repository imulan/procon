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
    int n,x;
    cin >>n >>x;

    int m=2*n-1;

    if(x==1 || x==m)
    {
        printf("No\n");
        return 0;
    }
    if(n==2)
    {
        printf("Yes\n");
        rep(i,3) printf("%d\n", i+1);
        return 0;
    }

    vector<int> a(m,0);
    vector<bool> used(m+1,false);
    if(x-2>=1)
    {
        a[m/2-2]=x-1;
        a[m/2-1]=x+1;
        a[m/2]=x;
        a[m/2+1]=x-2;
        for(int i=x-2; i<=x+1; ++i) used[i]=true;
    }
    else
    {
        a[m/2-2]=x+1;
        a[m/2-1]=x-1;
        a[m/2]=x;
        a[m/2+1]=x+2;
        for(int i=x-1; i<=x+2; ++i) used[i]=true;
    }

    int now=1;
    rep(i,m)
    {
        if(a[i]!=0) continue;

        while(now<=m && used[now]) ++now;
        a[i]=now;
        used[now]=true;
    }

    printf("Yes\n");
    rep(i,m) printf("%d\n", a[i]);
    return 0;
}
