#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back

using ll = long long;

ll ct2(ll n)
{
    ll r = 0;
    while(n>0 && n%2==0)
    {
        n/=2;
        ++r;
    }
    return r;
}

ll pw(int x, int n)
{
    ll r = 1;
    rep(i,n) r *=x;
    return r;
}

ll num(int n)
{
    ll ct = 0;
    rep(i,n+1)
    {
        ct += ct2(i);
    }
    return ct;
}

ll C(int n, int m)
{
    ll p = num(n);
    ll q = num(m) + num(n-m);
    // printf("C %d %d %lld\n", n,m,p-q);
    return p-q;
}

void test()
{
    for(int i=3; i<=100000; i+=2)
    {
        printf(" i %d\n", i);
        for(int j=2; j<=i; j+=2)
        {
            if(C(i,j)>0)
            {
                assert(j==pw(2,ct2(i+1)));
                break;
            }
        }
    }
    printf(" END\n");
}

int main()
{
    // test();

    ll n;
    cin >>n;

    cout << pw(2,ct2(n+1)) << endl;
    return 0;
}
