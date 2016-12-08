#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

long double sum(int n)
{
    double ret=0;
    for(int i=1; i<=n; ++i) ret+=1.0/i/i;
    return ret;
}

const long double pi=acos(-1);
const int N=50000000;

int main()
{
    double x;
    cin >>x;

    long double s=0,a=0;
    for(int i=1; i<=N; ++i)
    {
        s+=1.0L/i/i;
        a+=1.0L/(i+x)/(i+x);
    }
    for(int i=N+1; i<=N+(int)x; ++i) s+=1.0/i/i;

    cout.precision(50);
    cout<< a+(pi*pi/6-s) << endl;
    return 0;
}
