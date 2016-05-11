#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;

int main()
{
    while(1)
    {
        int w,d;
        cin >>w >>d;
        if(w*d==0) break;

        vector<int> hw(w),hd(d);
        rep(i,w) cin >>hw[i];
        rep(i,d) cin >>hd[i];

        vector<vi> f(d,vi(w,0));

        //i行目に注目
        rep(i,d)
        {
            int now=hd[i];
            int idx=-1;

            rep(j,w)
            {
                if(now==hw[j])
                {
                    //j列目の最大値がnowに一致していればスルー
                    int m=0;
                    rep(k,d) m=max(m,f[k][j]);

                    if(m!=now)
                    {
                        idx=j;
                        break;
                    }
                }
            }

            //not found
            if(idx==-1)
            {
                rep(j,w)
                {
                    if(hw[j]>=now)
                    {
                        idx=j;
                        break;
                    }
                }
            }
            f[i][idx]=now;
        }

        /*
        for(int i=d-1; i>=0; --i)
        {
            rep(j,w) printf("%3d",f[i][j]);
            printf("\n");
        }
        */

        rep(i,w)
        {
            int m=0;
            rep(j,d) m=max(m,f[j][i]);

            if(m!=hw[i])
            {
                rep(j,d)
                {
                    if(hd[j]>=hw[i])
                    {
                        f[j][i]=hw[i];
                        break;
                    }
                }
            }
        }

        /*
        for(int i=d-1; i>=0; --i)
        {
            rep(j,w) printf("%3d",f[i][j]);
            printf("\n");
        }
        */
        
        int ans=0;
        rep(i,d)rep(j,w) ans+=f[i][j];
        std::cout << ans << std::endl;
    }
    return 0;
}
