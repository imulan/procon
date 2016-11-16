#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct Place{ int x,y; };
struct State
{
    Place h,g;
    int p;
};

const int INF=123456789;
int z[20][20][20][20][10];
inline void init()
{
    rep(a,20)rep(b,20)rep(c,20)rep(d,20)rep(e,10) z[a][b][c][d][e]=INF;
}

int dx[5]={1,-1,0,0,0}, dy[5]={0,0,1,-1,0};

int main()
{
    int h,w;
    while(cin >>h >>w,h)
    {
        vector<string> s(h);
        rep(i,h) cin >>s[i];

        string pattern;
        cin >>pattern;
        int P=pattern.size();
        vector<int> pat(P);
        rep(i,P)
        {
            if(pattern[i]=='6') pat[i]=0;
            else if(pattern[i]=='4') pat[i]=1;
            else if(pattern[i]=='2') pat[i]=2;
            else if(pattern[i]=='8') pat[i]=3;
            else if(pattern[i]=='5') pat[i]=4;
        }

        Place a,b;
        rep(i,h)rep(j,w)
        {
            if(s[i][j]=='A') a=Place{j,i};
            if(s[i][j]=='B') b=Place{j,i};
        }

        init();
        z[a.y][a.x][b.y][b.x][0]=0;
        queue<State> que;
        que.push(State{a,b,0});
        #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
        while(!que.empty())
        {
            State now=que.front(); que.pop();
            a=now.h;
            b=now.g;
            int idx=now.p;
            int nowZ=z[a.y][a.x][b.y][b.x][idx];

            // 幽霊の位置
            int nbx=b.x+dx[pat[idx]], nby=b.y+dy[pat[idx]];
            if(!IN(nbx,nby))
            {
                nbx=b.x;
                nby=b.y;
            }
            Place nb=Place{nbx,nby};
            int nidx=(idx+1)%P;

            // 人の位置
            rep(i,5)
            {
                int nax=a.x+dx[i], nay=a.y+dy[i];
                if(IN(nax,nay) && s[nay][nax]!='#' && z[nay][nax][nby][nbx][nidx] > nowZ+1)
                {
                    z[nay][nax][nby][nbx][nidx] = nowZ+1;
                    Place na=Place{nax,nay};
                    que.push(State{na,nb,nidx});
                }
            }
        }

        int ans=INF,ax=-1,ay=-1;
        rep(i,h)rep(j,w)rep(k,P)
        {
            if(ans>z[i][j][i][j][k])
            {
                ans=z[i][j][i][j][k];
                ax=j;
                ay=i;
            }
        }

        if(ans==INF) printf("impossible\n");
        else printf("%d %d %d\n", ans,ay,ax);
    }
    return 0;
}
