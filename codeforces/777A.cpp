#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int A=2000000004;

int f(int n, int x)
{
    int ret;
    if(n%2==0)
    {
        if(x==1) ret=4;
        else ret=x;
    }
    else
    {
        if(x==0) ret=5;
        else if(x==1) ret=1;
        else ret=3;
    }
    return ret;
}

int main()
{
    int n,x;
    cin >>n >>x;

    int c[6]={0,1,2,2,1,0};
    printf("%d\n", c[(f(n,x)-n+A)%6]);
    return 0;
}
