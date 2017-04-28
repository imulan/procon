#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF = 123456789;

int main()
{
    int n;
    scanf(" %d", &n);

    vector<int> a(n),b(n);
    rep(i,n) scanf(" %d %d", &a[i], &b[i]);

    int ans = INF;
    rep(flip,2)
    {
        bool valid=true;

        vector<int> f(n);
        f[0]=flip;
        for(int i=1; i<n; ++i)
        {
            int x = f[i-1]?a[i-1]:b[i-1];

            if(a[i]!=x)
            {
                if(b[i]==x) f[i]=1;
                else
                {
                    valid=false;
                    break;
                }
            }
        }

        if(valid)
        {
            int ct=0;
            rep(i,n) ct+=f[i];
            ans=min(ans,ct);
        }
    }

    if(ans==INF) ans=-1;
    printf("%d\n", ans);
    return 0;
}
