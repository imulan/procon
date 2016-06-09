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

typedef pair<int,int> pi;

inline bool in(int x, int y)
{
    return (0<=x&&x<=5000 && 0<=y&&y<=5000);
}

int main()
{
    int n;
    while(cin >>n,n)
    {
        set<pi> p;

        vector<pi> v(n);
        rep(i,n)
        {
            scanf(" %d %d", &v[i].fi, &v[i].se);
            p.insert(v[i]);
        }

        sort(all(v));

        int ans=0;

        //2点を選ぶ
        rep(i,n)rep(j,i)
        {
            int dx=v[i].fi-v[j].fi;
            int dy=v[i].se-v[j].se;

            int p1x=v[j].fi-dy,p1y=v[j].se+dx;
            int p2x=v[i].fi-dy,p2y=v[i].se+dx;
            if(in(p1x,p1y) && in(p2x,p2y))
            {
                if(p.find(pi(p1x,p1y))!=p.end() && p.find(pi(p2x,p2y))!=p.end()) ans=max(ans,dx*dx+dy*dy);
            }

            int q1x=v[j].fi+dy,q1y=v[j].se-dx;
            int q2x=v[i].fi+dy,q2y=v[i].se-dx;
            if(in(q1x,q1y) && in(q2x,q2y))
            {
                if(p.find(pi(q1x,q1y))!=p.end() && p.find(pi(q2x,q2y))!=p.end()) ans=max(ans,dx*dx+dy*dy);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
