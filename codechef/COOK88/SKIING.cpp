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
using P = pair<int,pi>;
using vi = vector<int>;

int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int solve()
{
    int n,m;
    cin >>n >>m;

    vector<vi> f(n,vi(m));
    vector<P> v;

    rep(i,n)rep(j,m)
    {
        cin >>f[i][j];
        v.pb({f[i][j],pi(i,j)});
    }

    sort(all(v));
    reverse(all(v));

    #define IN(x,y) (0<=x && x<m && 0<=y && y<n)

    int ans = 0;
    vector<vector<bool>> vis(n,vector<bool>(m));
    for(const auto &p:v)
    {
        pi s = p.se;
        if(vis[s.fi][s.se]) continue;

        ++ans;

        queue<pi> que;
        que.push(s);
        vis[s.fi][s.se] = true;
        while(!que.empty())
        {
            pi now = que.front();
            que.pop();
            rep(i,4)
            {
                int nx = now.se+dx[i], ny = now.fi+dy[i];
                if(IN(nx,ny) && !vis[ny][nx] && f[ny][nx]<=f[now.fi][now.se])
                {
                    vis[ny][nx] = true;
                    que.push({ny,nx});
                }
            }
        }
    }

    return ans;
}

int main()
{
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
