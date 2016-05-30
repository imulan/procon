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
    int a,b,c,d,p;
    cin >>a >>b >>c >>d >>p;

    int x=a*p;
    int y=b;
    if(c<p) y+=d*(p-c);

    cout << min(x,y) << endl;
    
    return 0;
}
