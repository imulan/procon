#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=1000000;

int n;
char s[N+1];

ll ku[N]={},kd[N]={};
ll tl[N],tr[N];

int posd[N],posu[N];
int PD=0,PU=0;

int main()
{
    scanf(" %d", &n);
    scanf(" %s", s);

    for(int i=1; i<n; ++i) ku[i] = ku[i-1]+(s[i-1]=='U');
    for(int i=n-2; i>=0; --i) kd[i] = kd[i+1]+(s[i+1]=='D');

    tl[0]=1;
    for(int i=1; i<n; ++i) tl[i] = tl[i-1] + 2*ku[i] + 1;
    tr[n-1]=1;
    for(int i=n-2; i>=0; --i) tr[i] = tr[i+1] + 2*kd[i] + 1;

    rep(i,n)if(s[i]=='U') posu[PU++] = i;
    for(int i=n-1; i>=0; --i)if(s[i]=='D') posd[PD++] = i;

    rep(i,n)
    {
        int f = (s[i]=='U');
        ll ans;
        if(kd[i]-ku[i]-f >= 0)
        {
            ans = tl[i]+tr[i];
            int j = posd[kd[i]-ku[i]-f];

            ans -= tr[j];
            ans -= (2LL*(kd[i]-ku[i]-f)+1)*(j-i);
        }
        else
        {
            f = (s[i]=='D');
            ans = tl[i]+tr[i];
            int j = posu[ku[i]-kd[i]-f];

            ans -= tl[j];
            ans -= (2LL*(ku[i]-kd[i]-f)+1)*(i-j);
        }

        if(i) printf(" ");
        printf("%lld", ans);
    }
    printf("\n");
    return 0;
}
