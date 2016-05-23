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
    string s;
    cin >>n >>s;

    int r=0,g=0,b=0;
    rep(i,n)
    {
        if(s[i]=='R') ++r;
        else if(s[i]=='G') ++g;
        else ++b;
    }

    printf("%d\n", (r%2)+(g%2)+(b%2));
    return 0;
}
