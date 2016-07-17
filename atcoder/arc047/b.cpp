#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define x first
#define y second

const int N=2000000000;

typedef pair<int,int> pi;

pi convert(pi p)
{
    return pi((p.y+p.x)/2,(p.y-p.x)/2);
}

int main()
{
    int n;
    cin >>n;

    vector<pi> p(n);

    int xmin=N,xmax=-N,ymin=N,ymax=-N;

    rep(i,n)
    {
        int tx,ty;
        scanf(" %d %d", &tx, &ty);
        //回転
        int X=tx-ty;
        int Y=tx+ty;
        p[i]=pi(X,Y);

        //printf(" convert %d %d\n", X,Y);

        xmin=min(xmin,X);
        xmax=max(xmax,X);
        ymin=min(ymin,Y);
        ymax=max(ymax,Y);
    }

    int d=max(xmax-xmin,ymax-ymin);
    
    //candidate
    vector<pi> c;
    c.pb(pi(xmin+d/2,ymin+d/2));
    c.pb(pi(xmin+d/2,ymax-d/2));
    c.pb(pi(xmax-d/2,ymin+d/2));
    c.pb(pi(xmax-d/2,ymin+d/2));

    pi ans(0,0);
    rep(i,c.size())
    {
        pi cp=convert(c[i]);

        pi p0=convert(p[0]);
        int dist=abs(p0.x-cp.x)+abs(p0.y-cp.y);

        bool ok=true;
        for(int j=1; j<n; ++j)
        {
            pi pt=convert(p[j]);
            int td=abs(pt.x-cp.x)+abs(pt.y-cp.y);

            if(td!=dist)
            {
                ok=false;
                break;
            }
        }

        if(ok)
        {
            ans=cp;
            break;
        }
    }

    printf("%d %d\n", ans.x, ans.y);
    return 0;
}
