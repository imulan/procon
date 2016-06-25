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
    ll a,b,k,l;
    cin >>a >>b >>k >>l;

    ll x=k/l;
    if(k%l!=0) ++x;

    ll y=k-l*(x-1);

    cout << min(b*x,b*(x-1)+a*y) << endl;
    return 0;
}
