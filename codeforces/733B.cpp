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

    int L=0,R=0;
    vector<int> l(n),r(n);
    rep(i,n)
    {
        scanf(" %d %d", &l[i], &r[i]);
        L+=l[i];
        R+=r[i];
    }

    int ans=0;
    int b=abs(L-R);

    rep(i,n)
    {
        int tb,tL,tR;

        tL=L+r[i]-l[i];
        tR=R+l[i]-r[i];
        tb=abs(tL-tR);
        if(tb>b)
        {
            b=tb;
            ans=i+1;
        }
    }

    printf("%d\n", ans);
    return 0;
}
