#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF=123456;

vvi rotate(const vvi &v)
{
    int m=v.size();
    vvi ret(m,vi(m));

    rep(i,m)rep(j,m) ret[j][m-1-i]=v[i][j];

    return ret;
}

int main()
{
    int n,m;
    while(scanf(" %d %d",&n,&m),n)
    {
        vvi w(n,vi(n)), p(m,vi(m));
        rep(i,n)rep(j,n) scanf(" %d", &w[i][j]);
        rep(i,m)rep(j,m) scanf(" %d", &p[i][j]);

        int ax=INF, ay=INF;
        rep(rotates,4)
        {
            rep(i,n-m+1)rep(j,n-m+1)
            {
                bool ok=true;
                rep(y,m)rep(x,m)
                {
                    if(p[y][x]==-1) continue;
                    if(p[y][x]!=w[i+y][j+x]) ok=false;
                }

                if(!ok) continue;

                rep(y,m)rep(x,m)
                {
                    if(p[y][x]!=-1)
                    {
                        if(i+y<ay || (i+y==ay && j+x<ax))
                        {
                            ay=i+y;
                            ax=j+x;
                        }
                        break;
                    }
                }
            }

            p=rotate(p);
        }

        if(ax==INF) printf("NA\n");
        else printf("%d %d\n", ax+1,ay+1);
    }
    return 0;
}
