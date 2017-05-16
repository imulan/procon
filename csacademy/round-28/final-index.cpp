#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int N,M,K;
    scanf(" %d %d %d", &N, &M, &K);

    rep(i,M)
    {
        int ps,l;
        scanf(" %d %d", &ps, &l);

        if(ps==0)
        {
            if(K<=l) K = l-K+1;
        }
        else
        {
            if(N-l+1<=K) K = 2*N-l+1-K;
        }
    }

    printf("%d\n", K);
    return 0;
}
