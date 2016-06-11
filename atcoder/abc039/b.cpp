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

int f(int x)
{
    return x*x*x*x;
}

int main()
{
    int x;
    cin >>x;

    int ans=0;
    for(int i=1; f(i)<=x; ++i)
    {
        if(f(i)==x)
        {
            ans=i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
