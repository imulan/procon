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
    int n,k;
    cin >>n >>k;
    vector<int> h(n);
    rep(i,n) scanf(" %d", &h[i]);

    //0の個数の累積和
    vector<int> z(n+1);
    z[0]=0;
    rep(i,n) z[i+1]=z[i]+(!h[i]);

    int ans=0;
    rep(i,n)
    {
        int end=upper_bound(all(z),k+z[i])-z.begin();
        ans=max(ans,end-1-i);
    }
    cout << ans << endl;
    return 0;
}
