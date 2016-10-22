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
    cin >>n >>m;

    int ct=0;
    rep(i,n/2+1)
    {
        if(i) printf(" ");
        printf("%d", 0);
        ++ct;
    }
    while(ct<n)
    {
        printf(" %d", m);
        ++ct;
    }
    printf("\n");
    return 0;
}
