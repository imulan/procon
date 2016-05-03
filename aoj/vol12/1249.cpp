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

typedef pair<int,int> pi;

int n,m;
int f[7][7][7];
int h[7][7];

inline bool ok(int a)
{
    return (0<=a && a<n);
}

bool check()
{
    //3:one,6:two,4:three _dimension
    int dx[13]={1,0,0,1,1,1,-1,0,0,1,1,1,1};
    int dy[13]={0,1,0,1,-1,0,0,1,1,1,1,-1,-1};
    int dz[13]={0,0,1,0,0,1,1,1,-1,1,-1,1,-1};

    //start point
    rep(i,n)rep(j,n)rep(k,n)
    {
        int col=f[i][j][k];

        if(col==-1) continue;

        //printf("start check %d,%d,%d :col %d\n", i,j,k,col);

        rep(d,13)
        {
            bool valid=true;
            for(int s=1; s<m; ++s)
            {
                int nx=i+s*dx[d];
                int ny=j+s*dy[d];
                int nz=k+s*dz[d];
                if(ok(nx) && ok(ny) && ok(nz))
                {
                    if(f[nx][ny][nz]!=col)
                    {
                        valid=false;
                        break;
                    }
                }
                else
                {
                    valid=false;
                    break;
                }
            }

            //found sequence
            if(valid) return true;
        }
    }

    //failed
    return false;
}

int main()
{
    while(1)
    {
        int p;
        cin >>n >>m >>p;
        if(n==0) break;

        vector<pi> v(p);
        rep(i,p)
        {
            scanf(" %d %d", &v[i].fi, &v[i].se);
            --v[i].fi;
            --v[i].se;
        }

        memset(f,-1,sizeof(f));
        memset(h,0,sizeof(h));

        //simulation
        int ans=-1;
        rep(i,p)
        {
            //0:black, 1:white
            int col=i%2;

            int x=v[i].fi;
            int y=v[i].se;

            f[x][y][h[x][y]++]=col;

            if(check())
            {
                ans=i;
                break;
            }
        }

        //output
        if(ans==-1) printf("Draw\n");
        else
        {
            if(ans%2==0) printf("Black ");
            else printf("White ");

            printf("%d\n", ans+1);
        }
    }
    return 0;
}
