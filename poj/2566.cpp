#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

const int N=100000;

int a[N];
pi suma[N+1];

int main()
{
    int n,Q;
    while(scanf(" %d %d", &n, &Q),n)
    {
        rep(i,n) scanf(" %d", &a[i]);

        suma[0]=pi(0,0);
        for(int i=1; i<=n; ++i) suma[i]=pi(suma[i-1].fi+a[i-1],i);
        sort(suma,suma+n+1);

        // rep(i,n+1) printf(" suma %d = %d\n", i,suma[i].fi);

        while(Q--)
        {
            int t;
            scanf(" %d", &t);

            int diff=1000000001;
            int ans=-1,ax=-1,ay=-1;

            // 単要素をチェック
            rep(i,n)
            {
                int td=abs(abs(a[i])-t);
                if(td<diff)
                {
                    diff=td;
                    ans=abs(a[i]);
                    ax=i+1;
                    ay=i+1;
                }
            }

            int r_idx=0;
            rep(i,n+1)
            {
                while(r_idx<n && suma[r_idx+1].fi-suma[i].fi<=t) ++r_idx;
                // printf("i,r %d %d\n", i,r_idx);

                for(int j=0; j<=1; ++j)
                {
                    if(r_idx+j<n+1 && r_idx+j>i)
                    {
                        int td=suma[r_idx+j].fi-suma[i].fi;
                        // printf("(%d,%d), td =%d \n",i,r_idx+j, td);
                        if(abs(td-t)<diff)
                        {
                            diff=abs(td-t);
                            ans=td;

                            int tx=suma[i].se, ty=suma[r_idx+j].se;
                            if(tx>ty) swap(tx,ty);

                            ax=tx+1;
                            ay=ty;
                        }
                    }
                }
            }

            printf("%d %d %d\n",ans,ax,ay);
        }
    }
    return 0;
}
