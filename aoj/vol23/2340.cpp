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
    int q;
    scanf(" %d", &q);

    ll l=0,r=0;

    while(q--)
    {
        int p,n;
        char c;
        scanf(" %d %c %d", &p, &c, &n);

        if(c=='(') l+=n;
        else r+=n;

        if(l==r) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
