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

int main()
{
    int T;
    cin >>T;
    rep(t,T)
    {
        int n;
        string s;
        cin >>n >>s;

        vector<int> x(n);
        rep(i,n) scanf(" %d", &x[i]);
        sort(all(x));

        //発電所がある位置
        vector<int> e;
        rep(i,n)
        {
            if(s[i]=='1') e.pb(x[i]);
        }

        int E=e.size();

        int ans=0;

        //両端
        ans+=e[0]-x[0];
        ans+=x[n-1]-e[E-1];

        rep(i,E-1)
        {
            int lidx=lower_bound(all(x),e[i])-x.begin();
            int ridx=lower_bound(all(x),e[i+1])-x.begin();

            //printf("%d - %d\n",lidx,ridx );

            int add=e[i+1]-e[i];

            for(int j=lidx; j<ridx; ++j)
            {
                int tmp=0;
                tmp+=x[j]-e[i];
                tmp+=e[i+1]-x[j+1];

                add=min(add,tmp);
            }

            ans+=add;
        }

        cout << ans << endl;
    }
    return 0;
}
