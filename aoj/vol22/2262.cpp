#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

struct State{
    int Y,X,M,D;
};

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
bool vis[20][20][16][4]={};

int main()
{
    int R,C;
    cin >>R >>C;
    vector<string> s(R);
    rep(i,R) cin >>s[i];

    queue<State> que;
    que.push({0,0,0,0});
    vis[0][0][0][0]=true;
    while(!que.empty())
    {
        State S = que.front(); que.pop();
        int y = S.Y, x = S.X, m = S.M, d = S.D;
        // printf("%d %d %d %d\n", y,x,m,d);

        vis[y][x][m][d] = true;

        char c = s[y][x];
        if(c=='@') break;

        if(c=='?')
        {
            rep(i,4)
            {
                // move
                int ny = (y+dy[i]+R)%R;
                int nx = (x+dx[i]+C)%C;
                if(!vis[ny][nx][m][i])
                {
                    vis[ny][nx][m][i] = true;
                    que.push({ny,nx,m,i});
                }
            }
        }
        else
        {
            if(c=='<' || c=='>' || c=='v' || c=='^')
            {
                if(c=='<') d = 2;
                if(c=='>') d = 0;
                if(c=='v') d = 1;
                if(c=='^') d = 3;
            }
            else if(c=='_')
            {
                if(m==0) d = 0;
                else d = 2;
            }
            else if(c=='|')
            {
                if(m==0) d = 1;
                else d = 3;
            }
            else if('0'<=c && c<='9') m = c-'0';
            else if(c=='+') m = (m+1)%16;
            else if(c=='-') m = (m+15)%16;

            // move
            int ny = (y+dy[d]+R)%R;
            int nx = (x+dx[d]+C)%C;
            if(!vis[ny][nx][m][d])
            {
                vis[ny][nx][m][d] = true;
                que.push({ny,nx,m,d});
            }
        }
    }

    string ans = "NO";
    rep(i,R)rep(j,C)if(s[i][j]=='@')
    {
        rep(k,16)rep(l,4)if(vis[i][j][k][l]) ans = "YES";
    }
    cout << ans << endl;
    return 0;
}
