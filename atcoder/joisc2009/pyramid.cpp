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

int w,h,n;
int f[3000][3000]={};

int main()
{
    scanf(" %d %d %d", &w, &h, &n);

    rep(i,n)
    {
        int x,y,H;
        scanf(" %d %d %d", &x, &y, &H);
        f[y][x]=max(f[y][x],H);
    }

    queue<pi> que;
    rep(i,h)rep(j,w)if(f[i][j]>0) que.push(pi(j,i));

    #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
    while(!que.empty())
    {
        pi now = que.front();
        que.pop();
        int x = now.fi, y = now.se;
        int H = f[y][x];

        for(int dy=-1; dy<=1; ++dy)for(int dx=-1; dx<=1; ++dx)
        {
            int nx = x+dx, ny = y+dy;
            if(IN(nx,ny) && f[ny][nx] < H-1)
            {
                f[ny][nx] = H-1;
                que.push(pi(nx,ny));
            }
        }
    }

    ll ans = 0;
    rep(i,h)rep(j,w) ans += f[i][j];
    printf("%lld\n", ans);
    return 0;
}
