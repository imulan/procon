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
    int f[46];
    f[0]=f[1]=1;
    for(int i=2; i<=n; ++i) f[i]=f[i-1]+f[i-2];
    cout << f[n] << endl;
    return 0;
}
