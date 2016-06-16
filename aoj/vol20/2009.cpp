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

const double eps=1e-10;

struct point
{
    double x,y;
};

struct line
{
    point a,b;
};

double dist(point p, point q)
{
    return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
}

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<line> v(n);
        rep(i,n) cin >>v[i].a.x >>v[i].a.y >>v[i].b.x >>v[i].b.y;

        int ans=1;
        rep(i,n)
        {
            vector<point> q;
            rep(j,i)
            {
                //交点が存在するか
                bool exist=true;
                //交点
                point t;

                //直線iと直線jの交点を求める

                //直線iがy軸に並行な直線
                if(v[i].a.x==v[i].b.x)
                {   //直線jもy軸に平行
                    if(v[j].a.x==v[j].b.x) exist=false;
                    else
                    {
                        //直線jの傾きと切片
                        double mj=(v[j].a.y-v[j].b.y)/(v[j].a.x-v[j].b.x);
                        double nj=v[j].a.y-mj*v[j].a.x;

                        //交点計算
                        t.x=v[i].a.x;
                        t.y=mj*t.x+nj;
                    }
                }
                else
                {
                    //直線iの傾きと切片
                    double mi=(v[i].a.y-v[i].b.y)/(v[i].a.x-v[i].b.x);
                    double ni=v[i].a.y-mi*v[i].a.x;

                    //直線jがy軸に平行
                    if(v[j].a.x==v[j].b.x)
                    {
                        //交点計算
                        t.x=v[j].a.x;
                        t.y=mi*t.x+ni;
                    }
                    else
                    {
                        //直線jの傾きと切片
                        double mj=(v[j].a.y-v[j].b.y)/(v[j].a.x-v[j].b.x);
                        double nj=v[j].a.y-mj*v[j].a.x;

                        //平行なので交点無し
                        if(fabs(mi-mj)<eps) exist=false;
                        else
                        {
                            //交点計算
                            t.x=(nj-ni)/(mi-mj);
                            t.y=mi*t.x+ni;
                        }
                    }
                }

                //交点が存在しない
                if(!exist) continue;

                //交点がエリア外なので考慮しない
                if(fabs(t.x)>100-eps || fabs(t.y)>100-eps) continue;

                //printf("%d,%d  -> %lf,%lf\n",i,j,t.x,t.y);

                bool dif=true;
                //すでにある交点と異なるものかどうか調べる
                rep(k,q.size())
                {
                    if(dist(t,q[k])<eps) dif=false;
                }

                if(dif) q.pb(t);
            }

            ans+=1+q.size();
        }

        cout << ans << endl;
    }
    return 0;
}
