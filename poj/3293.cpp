#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct Point
{
    ll x, y;
    int id;
};

bool cmp1(const Point &left, const Point &right)
{
    return left.x==right.x ? left.y<right.y : left.x<right.x;
}

bool cmp2(const Point &left, const Point &right)
{
    return left.y==right.y ? left.x<right.x : left.y<right.y;
}

const int N=100000;
Point p[N];
vector<int> G[N];

int vis[N];

typedef pair<ll,ll> pl;
typedef pair<pl,ll> edge1;
typedef pair<ll,pl> edge2;
typedef pair<pl,int> ep;

// horizontal, vertical
vector<edge1> hr;
vector<edge2> vr;

vector<ep> endpoint;


int main()
{
    int Q;
    scanf(" %d",&Q);
    while(Q--)
    {
        rep(i,N) G[i].clear();
        memset(vis,0,sizeof(vis));
        hr.clear();
        vr.clear();
        endpoint.clear();

        int n;
        scanf(" %d",&n);
        rep(i,n)
        {
            scanf(" %lld %lld", &p[i].x, &p[i].y);
            p[i].id=i;
        }

        if(n%2==1)
        {
            printf("-1\n");
            continue;
        }

        bool valid=true;
        ll ans=0;

        sort(p,p+n,cmp1);
        for(int i=0; i<n; i+=2)
        {
            if(p[i].x != p[i+1].x)
            {
                valid=false;
                break;
            }

            ans+=p[i+1].y-p[i].y;
            int a=p[i].id, b=p[i+1].id;
            G[a].pb(b);
            G[b].pb(a);
            // printf(" %d,%d\n", a,b);

            vr.pb(edge2(p[i].x,pl(p[i].y,p[i+1].y)));
        }

        sort(p,p+n,cmp2);
        for(int i=0; i<n; i+=2)
        {
            if(p[i].y != p[i+1].y)
            {
                valid=false;
                break;
            }
            ans+=p[i+1].x-p[i].x;
            int a=p[i].id, b=p[i+1].id;
            G[a].pb(b);
            G[b].pb(a);
            // printf(" %d,%d\n", a,b);

            hr.pb(edge1(pl(p[i].x,p[i+1].x),p[i].y));
        }

        int now=0, par=0;
        vis[0]=1;
        rep(loop,n)
        {
            // printf("now = %d, par = %d\n", now,par);
            rep(i,G[now].size())
            {
                int nx=G[now][i];
                if(nx!=par)
                {
                    vis[nx]=1;
                    par=now;
                    now=nx;
                    break;
                }
            }
        }

        if(now!=0) valid=false;
        rep(i,n) if(!vis[i]) valid=false;

        // intersection判定
        if(valid)
        {
            sort(all(hr));
            sort(all(vr));

            rep(i,hr.size())
            {
                edge1 e=hr[i];
                ll Y=e.se;

                // 始点
                endpoint.pb( ep( pl(e.fi.fi, Y),0) );
                // 終点
                endpoint.pb( ep( pl(e.fi.se, Y),1) );
            }
            sort(all(endpoint));

            // どのy座標の位置に線分が存在しているかを管理する
            set<ll> lines;

            int ep_idx=0;
            int VR=vr.size(), EP=endpoint.size();

            // rep(i,EP)
            // {
            //     printf("  ep[%d]= %lld, Y(%lld), :type: %d\n", i,endpoint[i].fi.fi,endpoint[i].fi.se,endpoint[i].se);
            // }

            rep(i,VR)
            {
                ll X=vr[i].fi;

                while(ep_idx<EP && endpoint[ep_idx].fi.fi<X)
                {
                    ll Y=endpoint[ep_idx].fi.se;
                    if(endpoint[ep_idx].se==0) lines.insert(Y);
                    else lines.erase(Y);

                    ++ep_idx;
                }
                while(ep_idx<EP && endpoint[ep_idx].fi.fi==X)
                {
                    ll Y=endpoint[ep_idx].fi.se;
                    if(endpoint[ep_idx].se==0) lines.insert(Y);
                    else break;

                    ++ep_idx;
                }

                // printf(" X= %lld\n", X);
                // cout << "  lines.size = "<<lines.size()<<endl;
                set<ll>::iterator itr=lines.upper_bound(vr[i].se.fi);

                // for(const ll &val:lines) printf("   %lld\n", val);
                // printf(" Yseg (%lld, %lld)\n", vr[i].se.fi, vr[i].se.se);

                if(itr!=lines.end())
                {
                    if(*itr < vr[i].se.se) valid=false;
                }

                if(!valid) break;

                // printf("ep_idx = %d\n", ep_idx);

                while(ep_idx<EP && endpoint[ep_idx].fi.fi==X)
                {
                    ll Y=endpoint[ep_idx].fi.se;
                    if(endpoint[ep_idx].se==1) lines.erase(Y);

                    ++ep_idx;
                }
            }
        }

        if(!valid) ans=-1;
        printf("%lld\n", ans);
    }
    return 0;
}
