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

int w,h,n;
int x[30],y[30];
set<pi> machine, m; // 圧縮前,圧縮後

ll f[65][65];
int X=0,Y=0;

void make_field()
{
    vector<int> p,q;
    // x方向
    p.pb(1);
    rep(i,n)
    {
        p.pb(x[i]);
        if(x[i]+1<=w) p.pb(x[i]+1);
    }
    sort(all(p));
    p.erase(unique(all(p)), p.end());

    // y方向
    q.pb(1);
    rep(i,n)
    {
        q.pb(y[i]);
        if(y[i]+1<=h) q.pb(y[i]+1);
    }
    sort(all(q));
    q.erase(unique(all(q)), q.end());

    X=p.size();
    Y=q.size();

    // rep(i,p.size()) printf(" p[%d]=%d\n", i,p[i]);
    // rep(i,q.size()) printf(" q[%d]=%d\n", i,q[i]);

    rep(i,Y-1)
    {
        rep(j,X-1)
        {
            f[i][j]=(ll)(q[i+1]-q[i])*(p[j+1]-p[j]);
            if(machine.find(pi(p[j],q[i])) != machine.end()) m.insert(pi(i,j));
        }
        f[i][X-1]=(ll)(q[i+1]-q[i])*(w-p[X-1]+1);
        if(machine.find(pi(p[X-1],q[i])) != machine.end()) m.insert(pi(i,X-1));
    }
    rep(j,X-1)
    {
        f[Y-1][j]=(ll)(h-q[Y-1]+1)*(p[j+1]-p[j]);
        if(machine.find(pi(p[j],q[Y-1])) != machine.end()) m.insert(pi(Y-1,j));
    }
    f[Y-1][X-1]=(ll)(h-q[Y-1]+1)*(w-p[X-1]+1);
    if(machine.find(pi(p[X-1],q[Y-1])) != machine.end()) m.insert(pi(Y-1,X-1));

    // confirm
    // for(int i=Y-1; i>=0; --i)
    // {
    //     rep(j,X) printf("%4lld", f[i][j]);
    //     printf("\n");
    // }
    // for(const pi &pp:m) printf(" %d, %d\n", pp.fi,pp.se);
}

ll dp[65][65][65][65];
ll dfs(int lx, int rx, int ly, int ry)
{
    if(lx>rx || ly>ry) return 0;
    if(dp[lx][rx][ly][ry]>=0) return dp[lx][rx][ly][ry];

    ll ret=0;
    for(const pi &pp:m)
    {
        if(lx<=pp.se && pp.se<=rx && ly<=pp.fi && pp.fi<=ry)
        {
            ll v=0;
            for(int i=lx; i<=rx; ++i) v+=f[pp.fi][i];
            for(int i=ly; i<=ry; ++i) v+=f[i][pp.se];
            v-=f[pp.fi][pp.se];

            v+=dfs(lx,pp.se-1,ly,pp.fi-1);
            v+=dfs(lx,pp.se-1,pp.fi+1,ry);
            v+=dfs(pp.se+1,rx,ly,pp.fi-1);
            v+=dfs(pp.se+1,rx,pp.fi+1,ry);

            ret=max(ret, v);
        }
    }

    return dp[lx][rx][ly][ry]=ret;
}

int main()
{
    cin >>w >>h >>n;
    rep(i,n)
    {
        cin >>x[i] >>y[i];
        machine.insert(pi(x[i],y[i]));
    }
    sort(x,x+n);
    sort(y,y+n);

    make_field();

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,X-1,0,Y-1) <<endl;
    return 0;
}
