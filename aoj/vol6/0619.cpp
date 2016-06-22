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
    int a[4],b[2];
    rep(i,4) cin >>a[i];
    rep(j,2) cin >>b[j];

    sort(a,a+4,greater<int>());
    sort(b,b+2,greater<int>());

    printf("%d\n", a[0]+a[1]+a[2]+b[0]);
    return 0;
}
