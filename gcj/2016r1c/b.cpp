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

int main()
{
    int t;
    cin >>t;
    rep(T,t)
    {
        int b;
        ll m;
        cin >>b >>m;

        int ans[50][50]={0};

        bool valid=false;

        rep(i,b-1) ans[i][b-1]=1;

        int pat=(b-2)*(b-1)/2;
        rep(i,1<<pat)
        {
            int tmp[50][50]={0};
            rep(j,b)rep(k,b) tmp[j][k]=ans[j][k];

            int ct=0;
            rep(j,b-1)
            {
                for(int k=j+1; k<b-1; ++k)
                {
                    if(i>>ct & 1) tmp[j][k]=1;
                    ++ct;
                }
            }

            ll p[50]={0};
            p[0]=1;
            rep(j,b)
            {
                for(int k=j+1; k<b; ++k)
                {
                    if(tmp[j][k]) p[k]+=p[j];
                }
            }

            if(p[b-1]==m)
            {
                valid=true;
                rep(j,b)rep(k,b) ans[j][k]=tmp[j][k];
                break;
            }
        }

        printf("Case #%d: ",T+1);
        if(valid)
        {
            cout << "POSSIBLE" << endl;
            rep(i,b)
            {
                rep(j,b) printf("%d", ans[i][j]);
                printf("\n");
            }
        }
        else cout << "IMPOSSIBLE" << endl;

    }
    return 0;
}
