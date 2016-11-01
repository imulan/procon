#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

int main()
{
    int m,n;
    cin >>m >>n;
    vector<string> c(m);
    rep(i,m) cin >>c[i];

    vector<pi> t[26];
    rep(i,m)rep(j,n)
    {
        if(c[i][j]!='.') t[c[i][j]-'A'].pb(pi(i,j));
    }

    int exist[26]={0};
    rep(i,26) if(t[i].size()>0) exist[i]=1;

    int ans=0;

    while(1)
    {
        bool erased=false;
        rep(i,26)
        {
            if(!exist[i]) continue;

            pi p=t[i][0], q=t[i][1];

            // 叩く位置の候補 (1or2箇所)
            vector<pi> quake;
            if(p.fi==q.fi)
            {
                int l=min(p.se,q.se)+1, r=max(p.se,q.se)-1;
                for(int j=l; j<=r; ++j)
                {
                    if(c[p.fi][j]=='.')
                    {
                        quake.pb(pi(p.fi,j));
                        break;
                    }
                }
            }
            else if(p.se==q.se)
            {
                int l=min(p.fi,q.fi)+1, r=max(p.fi,q.fi)-1;
                for(int j=l; j<=r; ++j)
                {
                    if(c[j][p.se]=='.')
                    {
                        quake.pb(pi(j,p.se));
                        break;
                    }
                }
            }
            else
            {
                if(c[p.fi][q.se]=='.') quake.pb(pi(p.fi,q.se));
                if(c[q.fi][p.se]=='.') quake.pb(pi(q.fi,p.se));
            }

            // 実際に試す
            int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
            #define IN(x,y) (0<=x && x<n && 0<=y && y<m)
            for(const auto &P:quake)
            {
                string touch="....";
                rep(j,4)
                {
                    for(int k=1; k<=max(n,m); ++k)
                    {
                        int nx=P.se+k*dx[j], ny=P.fi+k*dy[j];
                        if(!IN(nx,ny)) break;

                        if(c[ny][nx]!='.')
                        {
                            touch[j]=c[ny][nx];
                            break;
                        }
                    }
                }
                int ct=0;
                rep(j,4) if(touch[j]=='A'+i) ++ct;
                if(ct==2)
                {
                    exist[i]=0;
                    c[p.fi][p.se]='.';
                    c[q.fi][q.se]='.';
                    erased=true;
                    break;
                }
            }

            if(erased) break;
        }

        if(!erased) break;
        ans+=2;
    }

    printf("%d\n", ans);
    return 0;
}
