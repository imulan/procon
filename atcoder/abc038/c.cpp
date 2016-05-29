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

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) scanf(" %d",&a[i]);

    long ans=0;

    int st=0;
    rep(i,n-1)
    {
        if(a[i]>=a[i+1])
        {
            ans+=(long)(i-st+1)*(i-st+2)/2;
            st=i+1;
        }
    }
    ans+=(long)(n-1-st+1)*(n-1-st+2)/2;

    cout << ans << endl;
    return 0;
}
