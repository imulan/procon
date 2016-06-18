#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int ab(int x)
{
    return (x>0)?x:-x;
}

int main()
{
    int n;
    cin >>n;

    if(n==1)
    {
        printf("0\n");
        return 0;
    }

    int ans=n;
    for(int i=1; i<n; ++i)
    {
        int x=n/i;
        int tmp=ab(i-x)+n-(i*x);
        ans=min(ans,tmp);
    }

    cout << ans << endl;
    return 0;
}
