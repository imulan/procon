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
    int y,x,dir;
};

using pi = pair<int,int>;
using ps = pair<State,State>;

const int dx[4]={1,0,-1,0}, dy[4]={0,-1,0,1};
const string ng = "He cannot bring tea to his master.";
const string half = "He cannot return to the kitchen.";
const string ok = "He can accomplish his mission.";

const int H=16, W=64;

int w,h;
string s[H];

bool dp[H][W][4][H][W][4];

inline bool IN(int y, int x)
{
    return 0<=y && y<h && 0<=x && x<w;
}

int main()
{
    while(cin >>w >>h,w)
    {
        rep(i,h) cin >>s[i];

        State start,goal;
        rep(i,h)rep(j,w)
        {
            if(s[i][j]=='K')
            {
                rep(k,4)if(s[i+dy[k]][j+dx[k]]=='.') start = {i,j,k};
            }
            if(s[i][j]=='M')
            {
                rep(k,4)if(s[i+dy[k]][j+dx[k]]=='.') goal = {i,j,k};
            }
        }

        bool forward = false, backward = false;
        memset(dp,0,sizeof(dp));
        queue<ps> que;
        rep(i,4)
        {
            dp[start.y][start.x][start.dir][start.y][start.x][(start.dir+i)%4]=true;
            que.push({start,{start.y,start.x,(start.dir+i)%4}});
        }
        while(!que.empty())
        {
            ps now=que.front();
            que.pop();

            State p=now.fi, q=now.se;
            // printf(" (%d %d %d) (%d %d %d)\n", p.y,p.x,p.dir,q.y,q.x,q.dir);
            while(s[p.y+dy[p.dir]][p.x+dx[p.dir]]!='#')
            {
                p.y += dy[p.dir];
                p.x += dx[p.dir];
            }
            if(p.x==goal.x && p.y==goal.y) forward = true;

            for(int dd:vector<int>({1,3}))
            {
                if(!dp[p.y][p.x][(p.dir+dd)%4][0][0][0])
                {
                    dp[p.y][p.x][(p.dir+dd)%4][0][0][0] = true;
                    que.push({{p.y,p.x,(p.dir+dd)%4},{0,0,0}});
                }
            }

            if(q.x!=0)
            {
                while(s[q.y][q.x]!='#')
                {
                    for(int dd:vector<int>({1,3}))
                    {
                        if(s[q.y+dy[(q.dir+dd)%4]][q.x+dx[(q.dir+dd)%4]]=='#')
                        {
                            if(!dp[p.y][p.x][(p.dir+dd)%4][q.y][q.x][(q.dir+dd)%4])
                            {
                                dp[p.y][p.x][(p.dir+dd)%4][q.y][q.x][(q.dir+dd)%4] = true;
                                que.push({{p.y,p.x,(p.dir+dd)%4},{q.y,q.x,(q.dir+dd)%4}});
                            }
                        }
                    }

                    q.y -= dy[q.dir];
                    q.x -= dx[q.dir];
                    if(p.x==goal.x && p.y==goal.y && q.x==goal.x && q.y==goal.y && q.dir==goal.dir) backward = true;
                }
            }
        }

        string ans = ng;
        if(forward && backward) ans = ok;
        else if(forward) ans = half;
        cout << ans << endl;
    }
    return 0;
}
