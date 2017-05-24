#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=400000;
int ct[N]={};

int main()
{
    int n;
    scanf(" %d", &n);
    rep(i,n)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        a+=b;
        ++ct[a];
    }

    rep(i,N-100)
    {
        for(int j=20; j>0; --j)
        {
            if(ct[i]>>j&1)
            {
                ct[i] -= 1<<j;
                ++ct[i+j];
            }
        }
    }

    rep(i,N)
    {
        if(ct[i]>0) printf("%d 0\n", i);
    }
    return 0;
}
