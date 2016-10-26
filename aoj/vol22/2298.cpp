#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,k,t,u,v,L;
    scanf(" %d %d %d %d %d %d", &n, &k, &t, &u, &v, &L);
    vector<int> d(n);
    rep(i,n) scanf(" %d", &d[i]);

    int idx=0;
    int st=-1;
    int stock=0;
    double ans=0;

    bool boost=false;

    rep(i,L)
    {
        if(idx<n && d[idx]==i)
        {
            if(stock<k) ++stock;
            else st=i;

            ++idx;
        }

        if(st+t*v==i)
        {
            st=false;
            boost=false;
        }

        if(!boost && stock>0)
        {
            boost=true;
            --stock;
            st=i;
        }

        if(boost) ans+=1.0/v;
        else ans+=1.0/u;
    }

    printf("%.10f\n", ans);
    return 0;
}
