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
    string ok="Possible", ng="Impossible";

    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    if(n==2)
    {
        string ans=ng;
        if(a[0]==1 && a[1]==1) ans=ok;
        cout << ans << endl;
        return 0;
    }

    sort(all(a));
    int max_dist=a[n-1];
    int min_dist=max_dist/2+max_dist%2;

    vector<int> ct(n,0);
    rep(i,n) ++ct[a[i]];

    string ans=ok;
    for(int i=0; i<min_dist; ++i)
    {
        if(ct[i]>0) ans=ng;
    }
    if(ct[min_dist] != 1+max_dist%2) ans=ng;
    for(int i=min_dist+1; i<=max_dist; ++i)
    {
        if(ct[i]<2) ans=ng;
    }

    cout << ans << endl;
    return 0;
}
