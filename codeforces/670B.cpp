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
    ll n,k;
    cin >>n >>k;
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    ll now=1;
    while(now*(now+1)/2<k) ++now;
    now=(now-1)*now/2;

    cout << a[k-now-1] << endl;
    return 0;
}
