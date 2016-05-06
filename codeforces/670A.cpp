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

    int x=n/7*2, y=n/7*2;

    if(n%7==1) y+=1;
    if(n%7>1) y+=2;

    if(n%7==6) ++x;

    printf("%d %d\n",x,y);
    return 0;
}
