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
    int T;
    scanf(" %d", &T);
    while(T--)
    {
        double s,v;
        scanf(" %lf %lf", &s, &v);
        printf("%.10lf\n", s*2/3/v);
    }
    return 0;
}
