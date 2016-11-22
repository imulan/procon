#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct person
{
    int x,y,dir;
};

// 右 上 左 下
int dx[4]={1,0,-1,0}, dy[4]={0,-1,0,1};
// 右 前 左 後
int dd[4]={3,0,1,2};

inline int detdir(char c)
{
    int r;
    if(c=='E') r=0;
    else if(c=='N') r=1;
    else if(c=='W') r=2;
    else r=3;
    return r;
}

inline char writedir(int d)
{
    string s="ENWS";
    return s[d];
}

int main()
{
    int w,h;
    while(scanf(" %d %d",&w,&h),w)
    {
        vector<string> s(h);
        rep(i,h) cin >>s[i];

        int t=0;
        while(t<181)
        {
            ++t;

            int ct[50][50]={0};

            vector<person> p;
            // 各人の向きを決定
            rep(i,h)rep(j,w)
            {
                if(s[i][j]!='.' && s[i][j]!='#' && s[i][j]!='X')
                {
                    int dir=detdir(s[i][j]);
                    rep(k,4)
                    {
                        int ndir=(dir+dd[k])%4;
                        // printf("ndir= %d\n", ndir);
                        int nx=j+dx[ndir], ny=i+dy[ndir];
                        if(s[ny][nx]=='.' || s[ny][nx]=='X')
                        {
                            ++ct[ny][nx];
                            dir=ndir;
                            break;
                        }
                    }

                    s[i][j]=writedir(dir);
                    p.pb(person{j,i,dir});
                }
            }

            int canmove[50][50]={0};
            rep(i,h)rep(j,w)
            {
                if(s[i][j]=='.' || s[i][j]=='X') canmove[i][j]=1;
            }

            for(const auto &a:p)
            {
                int nx=a.x+dx[a.dir], ny=a.y+dy[a.dir];
                if(canmove[ny][nx])
                {
                    if(ct[ny][nx]==1)
                    {
                        if(s[ny][nx]=='.') s[ny][nx]=s[a.y][a.x];
                        s[a.y][a.x]='.';
                        canmove[ny][nx]=0;
                    }
                    else
                    {
                        bool found=false;
                        if(s[ny][nx]=='.')
                        {
                            rep(k,4)
                            {
                                int X=nx+dx[k], Y=ny+dy[k];
                                if(X==a.x && Y==a.y) break;

                                if(s[Y][X]=='E' || s[Y][X]=='N' || s[Y][X]=='W' || s[Y][X]=='S') found=true;
                            }
                        }
                        if(!found)
                        {
                            if(s[ny][nx]=='.') s[ny][nx]=s[a.y][a.x];
                            s[a.y][a.x]='.';
                            canmove[ny][nx]=0;
                        }
                    }
                }
            }

            // printf(" ---time %d ---\n", t);
            // rep(i,h) cout << s[i] <<endl;

            bool done=true;
            rep(i,h)rep(j,w)
            {
                if(s[i][j]=='E' ||s[i][j]=='N' ||s[i][j]=='W' ||s[i][j]=='S') done=false;
            }
            if(done) break;
        }

        if(t==181) printf("NA\n");
        else printf("%d\n",t);
    }
    return 0;
}
