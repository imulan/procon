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

using pi = pair<int,int>;
const int INF = 19191919;

string c[6]={"UL", "UR", "R", "LR", "LL", "L"};
int dx[6]={-1,1,2,1,-1,-2};
int dy[6]={-2,-2,0,2,2,0};

int main()
{
    int n;
    cin >>n;
    pi s,g;
    cin >>s.fi >>s.se >>g.fi >>g.se;

    #define IN(y,x) (0<=x && x<n && 0<=y && y<n)

    vector<vector<int>> d(n,vector<int>(n,INF));
    d[s.fi][s.se]=0;
    queue<pi> que;
    que.push(s);
    while(!que.empty())
    {
        pi now = que.front();
        que.pop();
        rep(i,6)
        {
            int ny=now.fi+dy[i], nx=now.se+dx[i];
            if(IN(ny,nx) && d[ny][nx]>d[now.fi][now.se]+1)
            {
                d[ny][nx]=d[now.fi][now.se]+1;
                que.push({ny,nx});
            }
        }
    }

    int ans = d[g.fi][g.se];
    if(ans==INF) cout << "Impossible" << endl;
    else
    {
        vector<vector<bool>> ok(n,vector<bool>(n));
        ok[g.fi][g.se] = true;
        que.push(g);
        while(!que.empty())
        {
            pi now = que.front();
            que.pop();
            rep(i,6)
            {
                int ny=now.fi+dy[i], nx=now.se+dx[i];
                if(IN(ny,nx) && d[ny][nx]==d[now.fi][now.se]-1 && !ok[ny][nx])
                {
                    // dbg(pi(ny,nx));
                    ok[ny][nx]=true;
                    que.push({ny,nx});
                }
            }
        }

        vector<string> commands;
        pi p = s;
        while(p!=g)
        {
            // dbg(p);
            rep(i,6)
            {
                pi nx = {p.fi+dy[i], p.se+dx[i]};
                if(IN(nx.fi,nx.se) && ok[nx.fi][nx.se] && d[nx.fi][nx.se]==d[p.fi][p.se]+1)
                {
                    commands.pb(c[i]);
                    p = nx;
                    break;
                }
            }
        }

        cout << ans << endl;
        rep(i,ans) cout << commands[i] << " \n"[i==ans-1];
    }
    return 0;
}
