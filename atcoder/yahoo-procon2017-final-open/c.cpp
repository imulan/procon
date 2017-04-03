#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct SqrtDecomposition{
    int n;
    vector<int> dat;
    int mod;

    int sqrt_n;
    int sz;
    vector<int> add;
    vector<vector<int>> num;

    SqrtDecomposition(int _n, int _mod, const vector<int> &a){
        n = _n;
        mod = _mod;

        dat = vector<int>(n);
        rep(i,n) dat[i] = a[i]%mod;

        sqrt_n = 1;
        while((sqrt_n+1)*(sqrt_n+1) <= n) ++sqrt_n;

        sz = (n+sqrt_n-1)/sqrt_n;

        add = vector<int>(sz,0);
        num = vector<vector<int>>(sz,vector<int>(mod,0));
        rep(i,sz)
        {
            rep(j,sqrt_n)
            {
                int idx = i*sqrt_n+j;
                if(idx>=n) continue;

                ++num[i][dat[idx]];
            }
        }
    }

    int query(int l, int r, int d){
        int l_b = l/sqrt_n, r_b = r/sqrt_n;
        int ret = 0;

        if(l_b == r_b)
        {
            for(int i=l; i<=r; ++i)
            {
                --num[l_b][dat[i]];
                (dat[i]+=d)%=mod;
                ++num[l_b][dat[i]];

                if((dat[i]+add[l_b])%mod==0) ++ret;
            }
        }
        else
        {
            for(int i=l; i<(l_b+1)*sqrt_n; ++i)
            {
                --num[l_b][dat[i]];
                (dat[i]+=d)%=mod;
                ++num[l_b][dat[i]];

                if((dat[i]+add[l_b])%mod==0) ++ret;
            }

            for(int b=l_b+1; b<r_b; ++b)
            {
                (add[b]+=d)%=mod;
                ret += num[b][(mod-add[b])%mod];
            }

            for(int i=r_b*sqrt_n; i<=r; ++i)
            {
                --num[r_b][dat[i]];
                (dat[i]+=d)%=mod;
                ++num[r_b][dat[i]];

                if((dat[i]+add[r_b])%mod==0) ++ret;
            }
        }

        return ret;
    }
};

int main()
{
    int N,M,Q;
    scanf(" %d %d %d", &N, &M, &Q);
    vector<int> a(N);
    rep(i,N) scanf(" %d", &a[i]);

    SqrtDecomposition sd(N,M,a);

    while(Q--)
    {
        int l,r,d;
        scanf(" %d %d %d", &l, &r, &d);
        --l;
        --r;
        printf("%d\n", sd.query(l,r,d));
    }

    return 0;
}
