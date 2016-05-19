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
    int n;
    while(cin >>n,n)
    {
        //schedule
        int s[50][31]={0};

        rep(i,n)
        {
            int f;
            cin >>f;
            rep(j,f)
            {
                int d;
                cin >>d;
                s[i][d]=1;
            }
        }

        int ans=-1;
        vector<vi> v(n,vi(n,0));

        //i-th day
        for(int i=1; i<=30; ++i)
        {
            rep(j,n)rep(k,n)
            {
                if(s[j][i] && s[k][i])
                {
                    v[j][j]=1;
                    v[k][k]=1;
                    v[j][k]=1;
                    v[k][j]=1;

                    rep(x,n)
                    {
                        v[j][x]|=v[k][x];
                        v[k][x]|=v[j][x];
                    }
                }
            }

            rep(j,n)
            {
                int ct=0;
                rep(k,n) ct+=v[j][k];
                if(ct==n)
                {
                    ans=i;
                    break;
                }
            }

            if(ans>0) break;
        }

        printf("%d\n", ans);
    }
    return 0;
}
