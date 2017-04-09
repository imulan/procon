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
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<bool> f(n+1,false);
    int now=n;
    rep(i,n)
    {
        f[a[i]]=true;

        vector<int> b;
        while(now>0 && f[now])
        {
            b.pb(now);
            --now;
        }

        rep(j,b.size())
        {
            if(j) printf(" ");
            printf("%d", b[j]);
        }
        printf("\n");
    }

    return 0;
}
