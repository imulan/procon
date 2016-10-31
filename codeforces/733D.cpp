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
typedef pair<pi,pi> P;

map<pi,P> mp;

int main()
{
    int n;
    scanf(" %d", &n);

    int k=1;
    int ansx=-1,ansy=-1;
    int d=0;

    rep(i,n)
    {
        int x[3];
        int m=1234567890;
        rep(j,3)
        {
            scanf(" %d", &x[j]);
            m=min(m,x[j]);
        }

        if(d<m)
        {
            d=m;
            ansx=i+1;
        }

        rep(j,3)
        {
            int p=x[j], q=x[(j+1)%3];
            if(p>q) swap(p,q);
            int z=x[(j+2)%3];

            pi f=pi(p,q);
            if(mp.find(f)==mp.end()) mp[f]=P(pi(z,i),pi(-1,-1));
            else
            {
                pi F=mp[f].fi, S=mp[f].se;

                if(z>F.fi && F.se!=i) mp[f]=P(pi(z,i),F);
                else if(z>S.fi && F.se!=i) mp[f]=P(F,pi(z,i));
            }
        }
    }

    for(const auto &x:mp)
    {
        pi key=x.fi;
        P value=x.se;
        pi F=value.fi,S=value.se;

        if(S.fi==-1) continue;

        int p=key.fi,q=key.se, r=F.fi+S.fi;
        int m=min({p,q,r});
        if(d<m)
        {
            k=2;
            d=m;
            ansx=F.se+1;
            ansy=S.se+1;
            if(ansx>ansy) swap(ansx,ansy);
        }
    }

    printf("%d\n", k);
    if(k==1) printf("%d\n", ansx);
    else printf("%d %d\n", ansx, ansy);
    return 0;
}
