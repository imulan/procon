#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int solve(int s, int t, int pos, int num)
{
    int ret=0;
    rep(T,num)
    {
        int x;
        scanf(" %d", &x);

        int fall=pos+x;
        if(s<=fall && fall<=t) ++ret;
    }
    return ret;
}

int main()
{
    int s,t,a,b,m,n;
    cin >>s >>t >>a >>b >>m >>n;

    printf("%d\n", solve(s,t,a,m));
    printf("%d\n", solve(s,t,b,n));
    return 0;
}
