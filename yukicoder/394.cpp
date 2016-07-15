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
    int s[6];
    rep(i,6) cin >>s[i];

    sort(s,s+6);

    double a=0;
    for(int i=1; i<=4; ++i) a+=s[i]*100;
    printf("%.2lf\n",a/400);
    return 0;
}
