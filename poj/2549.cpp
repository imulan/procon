#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<int,pi> P;

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<int> v(n);
        rep(i,n) scanf(" %d", &v[i]);

        sort(all(v),greater<int>());

        vector<P> sum2(n*(n-1)/2);
        int s_idx=0;
        rep(i,n)rep(j,i) sum2[s_idx++]=P(v[i]+v[j],pi(i,j));
        sort(all(sum2));

        int ans=-1;
        rep(i,n)rep(j,n)
        {
            if(i==j) continue;
            int val=v[i]-v[j];
            P cmp=P(val,pi(-1,-1));
            P cmp2=P(val,pi(n,n));
            int lidx=lower_bound(all(sum2),cmp)-sum2.begin();
            int ridx=upper_bound(all(sum2),cmp2)-sum2.begin();

            bool found=false;
            for(int k=lidx; k<ridx; ++k)
            {
                int x=sum2[k].se.fi, y=sum2[k].se.se;
                if(x!=i && x!=j && y!=i && y!=j)
                {
                    found=true;
                    ans=v[i];
                    break;
                }
            }

            if(found) i=j=n;
        }

        if(ans==-1) printf("no solution\n");
        else printf("%d\n", ans);
    }
    return 0;
}
