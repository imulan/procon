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
typedef vector<vi> vvi;
typedef pair<int,int> pi;

int main()
{
    int n,m;
    cin >>n >>m;

    vvi a(n,vi(n));
    rep(i,n)rep(j,n) cin >>a[i][j];

    //query
    rep(M,m)
    {
        int op;
        scanf(" %d", &op);

        vvi b(a);
        if(op==0)
        {
            int r,c,size,angle;
            scanf(" %d %d %d %d",&r,&c,&size,&angle);
            --r;
            --c;

            rep(T,angle/90)
            {
                vvi t(b);

                for(int i=r; i<r+size; ++i)
                for(int j=c; j<c+size; ++j)
                t[r+(j-c)][c+size-1-(i-r)]=b[i][j];

                for(int i=r; i<r+size; ++i)
                for(int j=c; j<c+size; ++j)
                b[i][j]=t[i][j];
            }

        }
        else if(op==1)
        {
            int r,c,size;
            scanf(" %d %d %d",&r,&c,&size);
            --r;
            --c;

            for(int i=r; i<r+size; ++i)
            for(int j=c; j<c+size; ++j)
            b[i][j]=!b[i][j];
        }
        else if(op==2)
        {
            int r;
            scanf(" %d",&r);
            --r;

            int tmp=b[r][0];
            rep(i,n-1) b[r][i]=b[r][i+1];
            b[r][n-1]=tmp;
        }
        else if(op==3)
        {
            int r;
            scanf(" %d",&r);
            --r;

            int tmp=b[r][n-1];
            for(int i=n-1; i>0; --i) b[r][i]=b[r][i-1];
            b[r][0]=tmp;
        }
        else
        {
            int r,c;
            scanf(" %d %d",&r,&c);
            --r;
            --c;

            int dr[4]={1,-1,0,0}, dc[4]={0,0,1,-1};

            vvi vis(n,vi(n,0));
            vis[r][c]=1;
            queue<pi> que;
            que.push(pi(r,c));
            while(!que.empty())
            {
                pi v=que.front();
                que.pop();
                rep(i,4)
                {
                    int nr=v.fi+dr[i], nc=v.se+dc[i];
                    if(0<=nr&&nr<n && 0<=nc&&nc<n)
                    {
                        if(!vis[nr][nc] && b[nr][nc]==b[r][c])
                        {
                            vis[nr][nc]=1;
                            que.push(pi(nr,nc));
                        }
                    }
                }
            }

            rep(i,n)rep(j,n)
            {
                if(vis[i][j]) b[i][j]=!b[i][j];
            }
        }

        a=b;
    }

    //output
    rep(i,n)
    {
        rep(j,n)
        {
            if(j) printf(" ");
            printf("%d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
