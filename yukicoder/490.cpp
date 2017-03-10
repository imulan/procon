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
    cin >>n;

    vector<int> a(n);
    rep(i,n) cin >>a[i];

    for(int i=1; i<2*n-3; ++i)
    {
        rep(p,n)
        {
            int q=i-p;
            if(p<q && q<n)
            {
                if(a[p]>a[q]) swap(a[p],a[q]);
            }
        }
    }

    rep(i,n)
    {
        if(i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
