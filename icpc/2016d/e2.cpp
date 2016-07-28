#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define dbg(x) cout<<#x"="<<x<<endl
#define rep1(i,n) for(int (i)=1;(i)<=(int)(n);++(i))

const int INF=123456789;

struct edge{int to,cost;};
vector<edge> G[2000];

int x[2000],y[2000],z[2000];

int main()
{
    int n,k,s;
    while(cin >>n >>k >>s,n)
    {
        rep(i,2000) G[i].clear();

        rep(i,n) scanf("%d %d %d",&x[i],&y[i],&z[i]);

        if(k==1)
        {
            printf("%d\n", 6*s*s);
            continue;
        }

        rep(i,n)rep(j,i)
        {
            int dx=abs(x[i]-x[j]);
            int dy=abs(y[i]-y[j]);
            int dz=abs(z[i]-z[j]);

            //立方体iと立方体jはつながっている
            if(dx<s && dy<s && dz<s){
                dx = s-dx;
                dy = s-dy;
                dz = s-dz;
                int weight = 2*(dx*dy+dy*dz+dz*dx);
                //printf("%d - %d connect %d\n", i,j,weight);

                G[i].pb(edge{j,weight});
                G[j].pb(edge{i,weight});
            }
        }

        //rep(i,n) printf("%d size = %d\n", i,(int)G[i].size());

        vector<int> vis(n,0);

        int maxw=-1;

        rep(i,n)
        {
            if(vis[i]) continue;
            //printf(" i=%d\n", i);

            if(G[i].size()==0)
            {
                vis[i]=1;
                continue;
            }

            vector<int> tvis(n,0);
            tvis[i]=1;
            queue<int> que;
            que.push(i);
            while(!que.empty())
            {
                int now=que.front();
                que.pop();
                rep(j,G[now].size())
                {
                    int nx=G[now][j].to;
                    if(!tvis[nx])
                    {
                        tvis[nx]=1;
                        que.push(nx);
                    }
                }
            }

            //連結成分の頂点数
            int V=0;
            rep(j,n) V+=tvis[j];

            //printf("V= %d\n",V );

            vector<int> one,two;
            rep(j,n)
            {
                if(tvis[j])
                {
                    if(G[j].size()==1) one.pb(j);
                    else if(G[j].size()==2) two.pb(j);
                    else printf("!!!!!!!!!!error\n");
                }
            }

            if(two.size()==V)
            {
                //printf("circle\n");
                //円が構成されている
                if(V<k);
                else if(V==k)
                {
                    //printf("equal\n");
                    vector<int> ttvis(n,0);
                    int start=i;

                    int now=i;
                    int tmpw=0;
                    int ct=0;
                    while(ct<k)
                    {
                        //printf("now= %d\n", now);
                        if(ttvis[now]) break;
                        ttvis[now]=1;
                        rep(j,G[now].size())
                        {
                            int nx=G[now][j].to;
                            if(!ttvis[nx])
                            {
                                ++ct;
                                tmpw+=G[now][j].cost;
                                now=nx;
                                break;
                            }
                        }
                    }

                    if(G[now][0].to==start) tmpw+=G[now][0].cost;
                    else tmpw+=G[now][1].cost;

                    maxw=max(maxw,tmpw);
                }
                else
                {
                    vector<int> ttvis(n,0);
                    int now=i;
                    int tmpw=0;
                    while(1)
                    {
                        if(ttvis[now]) break;
                        ttvis[now]=1;
                        //printf("now =%d\n",now);

                        int start=now;

                        //2通り試す
                        int tw;
                        int ct;
                        vector<int> zero(n,0);
                        vector<int> VIS;

                        //1個目
                        now=start;
                        tw=0;
                        ct=1;
                        VIS=zero;
                        VIS[now]=1;
                        tw+=G[now][0].cost;
                        now=G[now][0].to;
                        VIS[now]=1;
                        //printf("first attempt to %d\n",now );
                        while(ct<k-1)
                        {
                            //printf(" now=%d\n", now);
                            rep(j,G[now].size())
                            {
                                if(!VIS[G[now][j].to])
                                {
                                    //printf(" go %d\n", G[now][j].to);
                                    VIS[G[now][j].to]=1;
                                    tw+=G[now][j].cost;
                                    now=G[now][j].to;
                                    ++ct;
                                    break;
                                }
                            }
                        }
                        //printf("tw=%d\n", tw);
                        tmpw=max(tmpw,tw);

                        //2個目
                        now=start;
                        tw=0;
                        ct=1;
                        VIS=zero;
                        VIS[now]=1;
                        tw+=G[now][1].cost;
                        now=G[now][1].to;
                        VIS[now]=1;
                        //printf("second attempt to %d\n",now );
                        while(ct<k-1)
                        {
                            rep(j,G[now].size())
                            {
                                if(!VIS[G[now][j].to])
                                {
                                    //printf(" go %d\n", G[now][j].to);
                                    VIS[G[now][j].to]=1;
                                    tw+=G[now][j].cost;
                                    now=G[now][j].to;
                                    ++ct;
                                    break;
                                }
                            }
                        }
                        //printf("tw=%d\n", tw);
                        tmpw=max(tmpw,tw);

                        //次の頂点へ
                        if(ttvis[G[start][0].to]) now=G[start][1].to;
                        else now=G[start][0].to;
                    }

                    maxw=max(maxw,tmpw);
                }
            }
            else
            {
                //printf("line\n");
                //直線が構成されている
                int start=one[0];

                if(V>=k)
                {
                    vector<int> ttvis(n,0);
                    while(1)
                    {
                        bool end=false;
                        ttvis[start]=1;

                        //printf("start = %d\n", start);

                        vector<int> VIS(n,0);
                        int now=start;
                        int ct=0;
                        int tmpw=0;
                        while(ct<k-1)
                        {
                            if(VIS[now]) break;
                            VIS[now]=1;

                            bool found=false;
                            rep(j,G[now].size())
                            {
                                int nx=G[now][j].to;
                                if(!ttvis[nx] && !VIS[nx])
                                {
                                    found=true;
                                    ++ct;
                                    tmpw+=G[now][j].cost;
                                    now=nx;
                                    //printf(" now=%d\n", now);
                                    break;
                                }
                            }

                            if(!found)
                            {
                                end=true;
                                break;
                            }
                        }
                        if(end) break;
                        maxw=max(maxw,tmpw);

                        if(G[start].size()==1) start=G[start][0].to;
                        else
                        {
                            if(ttvis[G[start][0].to]) start=G[start][1].to;
                            else start=G[start][0].to;
                        }
                    }
                }
            }

            rep(j,n) vis[j]|=tvis[j];
        }

        //output
        int ans=6*s*s*k - maxw;
        if(maxw==-1) ans=-1;
        printf("%d\n", ans);
    }

    return 0;
}
