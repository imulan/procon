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

const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

string ans(int r, int nr)
{
    if(r>0 && nr>0) return "Unknown";
    if(r==0 && nr>0) return "No";
    if(r>0 && nr==0) return "Yes";
    return "Broken";
}

int main()
{
    int h,w,d,n;
    cin >>h >>w >>d >>n;

    vector<string> t(h);
    rep(i,h) cin >>t[i];

    vector<int> r(d+1);
    rep(i,d) cin >>r[i];

    vector<int> x(n),y(n),s(n);
    rep(i,n) cin >>x[i] >>y[i] >>s[i];

    int px,py;
    rep(i,h)rep(j,w)if(t[i][j]=='D')
    {
        px = j;
        py = i;
    }

    #define IN(x,y) (0<=x && x<w && 0<=y && y<h)

    vector<vector<bool>> vis(h,vector<bool>(w,false));
    vis[py][px]=true;
    queue<pi> que;
    que.push({py,px});
    while(!que.empty())
    {
        pi p = que.front();
        que.pop();
        rep(i,4)
        {
            int nx = p.se+dx[i], ny = p.fi+dy[i];
            if(IN(nx,ny) && t[ny][nx]!='#' && !vis[ny][nx])
            {
                vis[ny][nx] = true;
                que.push({ny,nx});
            }
        }
    }

    vector<vector<int>> f(h,vector<int>(w));
    rep(i,n)
    {
        if(s[i]==0)
        {
            for(int Y=y[i]-r[0]; Y<=y[i]+r[0]; ++Y)for(int X=x[i]-r[0]; X<=x[i]+r[0]; ++X)
            {
                if(IN(X,Y)) ++f[Y][X];
            }
        }
        else if(s[i]==d)
        {
            rep(Y,h)rep(X,w) ++f[Y][X];
            for(int Y=y[i]-r[d-1]; Y<=y[i]+r[d-1]; ++Y)for(int X=x[i]-r[d-1]; X<=x[i]+r[d-1]; ++X)
            {
                if(IN(X,Y)) --f[Y][X];
            }
        }
        else
        {
            for(int Y=y[i]-r[s[i]]; Y<=y[i]+r[s[i]]; ++Y)for(int X=x[i]-r[s[i]]; X<=x[i]+r[s[i]]; ++X)
            {
                if(IN(X,Y)) ++f[Y][X];
            }
            for(int Y=y[i]-r[s[i]-1]; Y<=y[i]+r[s[i]-1]; ++Y)for(int X=x[i]-r[s[i]-1]; X<=x[i]+r[s[i]-1]; ++X)
            {
                if(IN(X,Y)) --f[Y][X];
            }
        }
    }

    // printf("------\n");
    // rep(i,h)
    // {
    //     rep(j,w) printf("%d", f[i][j]);
    //     printf("\n");
    // }

    int R=0, NR=0;
    rep(i,h)rep(j,w)
    {
        if(t[i][j]!='#' && f[i][j]==n)
        {
            if(vis[i][j]) ++R;
            else ++NR;
        }
    }

    cout << ans(R,NR) << endl;
    return 0;
}
