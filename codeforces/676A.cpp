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

int ab(int z)
{
    return (z>0?z:-z);
}

int main()
{
    int n;
    cin >>n;

    vector<int> a(n);
    int x=-1,y=-1;
    rep(i,n)
    {
        scanf(" %d", &a[i]);
        if(a[i]==1) x=i;
        if(a[i]==n) y=i;
    }

    int ans=0;
    ans=max(ans,ab(x-0));
    ans=max(ans,ab(n-1-x));
    ans=max(ans,ab(y-0));
    ans=max(ans,ab(n-1-y));

    cout << ans << endl;
    return 0;
}
