#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

inline ll A(ll i, ll j)
{
    return i*i + j*j + i*j + 100000LL*(i-j);
}

int main()
{
    int Q;
    scanf(" %d",&Q);
    while(Q--)
    {
        ll N,M;
        scanf(" %lld %lld", &N, &M);

        ll l = -2499849999LL-1, r = 7500000001LL;
        while(r-l>1)
        {
            ll m=(l+r)/2;

            ll ct=0;
            for(int j=1; j<=N; ++j)
            {
                if(m<A(1,j)) continue;
                if(A(N,j)<=m)
                {
                    ct+=N;
                    continue;
                }

                int lidx=1, ridx=N;
                while(ridx-lidx>1)
                {
                    int midx=(lidx+ridx)/2;
                    if(A(midx,j)<=m) lidx=midx;
                    else ridx=midx;
                }
                ct+=lidx;
            }

            if(ct<M) l=m;
            else r=m;
        }

        printf("%lld\n", r);
    }
    return 0;
}
