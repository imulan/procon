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
    ll h,w,k;
    cin >>h >>w >>k;

    ll g=__gcd(w,k);
    w/=g;
    k/=g;

    cout << (w/2)*(k/2) + ((w-1)/2)*((k-1)/2) << endl;
    return 0;
}
