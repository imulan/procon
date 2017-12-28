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
using vi = vector<int>;

const int N = 50;
const int INF = 19191919;

int r,c,m;
string s[N];
int comp[N][N], on[N][N], off[N][N];
pi task[1000];

vi t[N][N];

vector<pi> route(pi start, pi goal)
{
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
    #define IN(y,x) (0<=y && y<r && 0<=x && x<c)

    vector<vi> d(r,vi(c,INF));
    vector<vector<pi>> par(r,vector<pi>(c));
    queue<pi> que;

    d[start.fi][start.se]=0;
    que.push(start);

    while(!que.empty())
    {
        pi now = que.front();
        que.pop();
        rep(i,4)
        {
            int nx=now.se+dx[i], ny=now.fi+dy[i];
            if(IN(ny,nx) && s[ny][nx]=='.' && d[ny][nx]>d[now.fi][now.se]+1)
            {
                d[ny][nx] = d[now.fi][now.se]+1;
                par[ny][nx] = now;
                que.push({ny,nx});
            }
        }
    }

    vector<pi> ret;
    pi now=goal;
    while(now != start)
    {
        ret.pb(now);
        now = par[now.fi][now.se];
    }
    reverse(all(ret));
    return ret;
}

int main()
{
    cin >>r >>c >>m;
    rep(i,r) cin >>s[i];
    rep(i,r)rep(j,c) cin >>comp[i][j];
    rep(i,r)rep(j,c) cin >>on[i][j];
    rep(i,r)rep(j,c) cin >>off[i][j];
    rep(i,m) cin >>task[i].fi >>task[i].se;

    vector<pi> vis;
    vis.pb(task[0]);
    rep(i,m-1)for(const auto &p:route(task[i],task[i+1])) vis.pb(p);

    rep(i,vis.size())
    {
        int y=vis[i].fi, x=vis[i].se;
        t[y][x].pb(i);
    }

    ll ans = 0;
    rep(i,r)rep(j,c)if(t[i][j].size()>0)
    {
        ll add = on[i][j]+off[i][j];

        vi stamp = t[i][j];
        int S = stamp.size();
        rep(k,S-1) add += min(on[i][j]+off[i][j], comp[i][j]*(stamp[k+1]-stamp[k]));

        ans += add;
    }
    cout << ans << endl;
    return 0;
}
