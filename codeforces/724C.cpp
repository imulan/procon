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
const int N=300000;
const ll INF = LLONG_MAX/3;

vector<int> u[N],d[N];

int main()
{
    int X,Y,n;
    scanf(" %d %d %d", &X, &Y, &n);

    vector<int> px(n), py(n);
    rep(i,n)
    {
        scanf(" %d %d", &px[i], &py[i]);

        int cu = py[i]-px[i]+X-1;
        u[cu].pb(i);
        int cd = py[i]+px[i];
        d[cd].pb(i);
    }

    vector<ll> ans(n,INF);
    ll t=0;
    int x=0, y=0, dx=1, dy=1;
    while(1)
    {
        // printf("x,y = %d %d\n", x,y);
        if(dx*dy>0)
        {
            int u_idx = y-x+X-1;
            for(const auto &i:u[u_idx]) ans[i] = min(ans[i],t+abs(x-px[i]));
        }
        else
        {
            int d_idx = y+x;
            for(const auto &i:d[d_idx]) ans[i] = min(ans[i],t+abs(x-px[i]));
        }

        int tx,ty;
        if(dx==1) tx=X-x;
        else tx=x;
        if(dy==1) ty=Y-y;
        else ty=y;

        int time = min(tx,ty);
        x += dx*time;
        y += dy*time;
        t += time;

        if(tx<ty) dx = -dx;
        else dy = -dy;

        if((x==0&&y==0) || (x==X&&y==0) || (x==0&&y==Y) || (x==X&&y==Y)) break;
    }

    rep(i,n)
    {
        if(ans[i]==INF) ans[i]=-1;
        printf("%lld\n", ans[i]);
    }
    return 0;
}
