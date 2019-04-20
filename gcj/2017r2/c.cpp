#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

void solve()
{
    int r,c;
    cin >>r >>c;
    vector<string> s(r);
    rep(i,r) cin >>s[i];

    int d[50][50]={};
    vector<pi> b;
    rep(i,r)rep(j,c)
    {
        if(s[i][j] == '-' || s[i][j] == '|')
        {
            b.pb(pi(i,j));
            d[i][j]=-1; // not yet
        }
    }

    bool valid=true;
    // ビームごとにみる
    for(const auto &p:b)
    {
        int x=p.se, y=p.fi;
        // どっちかに向けたらまずい？

        // 横
        bool yoko=true;
        int i=x-1;
        while(i>=0 && s[y][i]!='#')
        {
            if(s[y][i]=='-' || s[y][i]=='|') yoko=false;
            --i;
        }
        i=x+1;
        while(i<c && s[y][i]!='#')
        {
            if(s[y][i]=='-' || s[y][i]=='|') yoko=false;
            ++i;
        }

        // 縦
        bool tate=true;
        i=y-1;
        while(i>=0 && s[i][x]!='#')
        {
            if(s[i][x]=='-' || s[i][x]=='|') tate=false;
            --i;
        }
        i=y+1;
        while(i<r && s[i][x]!='#')
        {
            if(s[i][x]=='-' || s[i][x]=='|') tate=false;
            ++i;
        }

        if(!tate && !yoko)
        {
            valid=false;
            break;
        }
        else if(!yoko)
        {
            // 絶対縦
            d[y][x]=1;
            s[y][x]='|';
        }
        else if(!tate)
        {
            // 絶対横
            d[y][x]=2;
            s[y][x]='-';
        }
    }

    if(!valid)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    // マスごとにみる
    rep(i,r)rep(j,c)
    {
        if(s[i][j]=='.')
        {
            // 上下左右みて、カバーできる個数
            int Y=0,X=0;
            int x=j;
            int y=i-1;
            while(y>=0 && s[y][x]!='#')
            {
                if(s[y][x]=='-' || s[y][x]=='|')
                {
                    if(d[y][x]!=2)
                    {
                        ++Y;
                        break;
                    }
                }
                --y;
            }
            y=i+1;
            while(y<r && s[y][x]!='#')
            {
                if(s[y][x]=='-' || s[y][x]=='|')
                {
                    if(d[y][x]!=2)
                    {
                        ++Y;
                        break;
                    }
                }
                ++y;
            }

            y=i;
            x=j-1;
            while(x>=0 && s[y][x]!='#')
            {
                if(s[y][x]=='-' || s[y][x]=='|')
                {
                    if(d[y][x]!=1)
                    {
                        ++X;
                        break;
                    }
                }
                --x;
            }
            x=j+1;
            while(x<c && s[y][x]!='#')
            {
                if(s[y][x]=='-' || s[y][x]=='|')
                {
                    if(d[y][x]!=1)
                    {
                        ++X;
                        break;
                    }
                }
                ++x;
            }

            if(Y==0 && X==0)
            {
                i=r;
                j=c;
                valid=false;
                break;
            }
            else if(Y==0)
            {
                // 横を採用
                x=j-1;
                while(x>=0 && s[y][x]!='#')
                {
                    if(s[y][x]=='-' || s[y][x]=='|')
                    {
                        if(d[y][x]!=1) break;
                    }
                    --x;
                }
                if(x!=-1)
                {
                    s[y][x]='-';
                    d[y][x]=2;
                }

                x=j+1;
                while(x<c && s[y][x]!='#')
                {
                    if(s[y][x]=='-' || s[y][x]=='|')
                    {
                        if(d[y][x]!=1) break;
                    }
                    ++x;
                }
                if(x!=c)
                {
                    s[y][x]='-';
                    d[y][x]=2;
                }
            }
            else if(X==0)
            {
                // 縦を採用
                y=i-1;
                while(y>=0 && s[y][x]!='#')
                {
                    if(s[y][x]=='-' || s[y][x]=='|')
                    {
                        if(d[y][x]!=2) break;
                    }
                    --y;
                }
                if(y!=-1)
                {
                    d[y][x]=1;
                    s[y][x]='|';
                }

                y=i+1;
                while(y<r && s[y][x]!='#')
                {
                    if(s[y][x]=='-' || s[y][x]=='|')
                    {
                        if(d[y][x]!=2) break;
                    }
                    ++y;
                }
                if(y!=r)
                {
                    d[y][x]=1;
                    s[y][x]='|';
                }
            }
        }
    }

    if(!valid)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    // 未定
    #define IN(x,y) (0<=x && x<c && 0<=y && y<r)
    int dx[4]={-1,1,0,0}, dy[4]={0,0,1,-1};
    vector<pi> nb;
    for(const auto &p:b)
    {
        if(d[p.fi][p.se]==-1)
        {
            bool blank=false;
            rep(dir,4)
            {
                int nx=p.se+dx[dir], ny=p.fi+dy[dir];
                if(IN(nx,ny) && s[ny][nx]=='.') blank=true;
            }

            if(blank) nb.pb(p);
        }
    }

    int N=nb.size();
    bool found=false;
    rep(mask,1<<N)
    {
        rep(i,N)
        {
            int x=nb[i].se, y=nb[i].fi;
            if(mask>>i&1) s[y][x] = '|';
            else s[y][x] = '-';
        }

        vector<string> f(s);
        for(const auto &p:b)
        {
            int y=p.fi-1;
            while(y>=0 && f[y][p.se]!='#') f[y--][p.se]='o';
            y=p.fi+1;
            while(y<r && f[y][p.se]!='#') f[y++][p.se]='o';
            int x=p.se-1;
            while(x>=0 && f[p.fi][x]!='#') f[p.fi][x--]='o';
            x=p.se+1;
            while(x<c && f[p.fi][x]!='#') f[p.fi][x++]='o';
        }

        bool ok=true;
        rep(i,r)rep(j,c){
            if(f[i][j]=='.')
            {
                ok=false;
                i=r;
                j=c;
                break;
            }
        }
        if(ok)
        {
            found=true;
            break;
        }
    }

    if(found)
    {
        cout << "POSSIBLE" << endl;
        rep(i,r) cout << s[i] <<endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

}

int main()
{
    int T;
    cin >>T;
    rep(t,T)
    {
        printf("Case #%d: ", t+1);
        solve();
    }
    return 0;
}
