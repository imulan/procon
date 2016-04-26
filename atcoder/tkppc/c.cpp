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
    int n,m,s;
    cin >>n >>m >>s;
    
    int ct[10001]={0};
    rep(i,n)
    {
        int t,k;
        scanf(" %d %d", &t, &k);
        ct[t]+=k;
    }

    for(int i=1; i<=s; ++i) ct[i]+=ct[i-1];

    int ans=0;
    rep(i,s) ans+=(ct[i]>=m);
    cout << ans << endl;
    return 0;
}
