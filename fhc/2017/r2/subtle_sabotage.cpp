#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=12345678;

int solve()
{
    int N,M,K;
    cin >>N >>M >>K;

    if(N<M) swap(N,M);

    int ret=INF;

    if(K+1<=N && 2*K+3<=M)
    {
        int need = (N+K-1)/K;
        ret = min(ret,need);
    }

    if(K+1<=M && 2*K+3<=N)
    {
        int need = (M+K-1)/K;
        ret = min(ret,need);
    }

    if(2*K+1<=M && 2*K+3<=N)
    {
        if(K==1) ret = min(ret,5);
        else ret = min(ret,4);
    }

    if(ret==INF) ret=-1;
    return ret;
}

int main()
{
    int T;
    cin >>T;
    rep(i,T) printf("Case #%d: %d\n", i+1, solve());
    return 0;
}
