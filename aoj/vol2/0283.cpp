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

const int INF=1010101010;

int main()
{
    int n,Q;
    scanf(" %d %d", &n, &Q);

    vector<pi> s(n);
    rep(i,n)
    {
        int tmp;
        scanf(" %d", &tmp);
        s[i]=pi(tmp,i);
    }
    sort(all(s));

    vector<int> x(n);
    rep(i,n) x[i]=s[i].fi;

    vector<int> f(n);
    rep(i,n) f[s[i].se]=i;

    set<int> leader;
    while(Q--)
    {
        char q[10];
        int a;
        scanf(" %s %d", q, &a);

        if(q[0]=='A') leader.insert(f[a-1]);
        else if(q[0]=='R') leader.erase(f[a-1]);
        else
        {
            int ng=-1, ok=INF;
            while(ok-ng>1)
            {
                int mid=(ok+ng)/2;

                int ct=0,cr=-1;
                for(const int &idx:leader)
                {
                    int lidx=lower_bound(all(x),x[idx]-mid)-x.begin();
                    int ridx=upper_bound(all(x),x[idx])-x.begin()-1;

                    if(lidx<=cr) lidx=cr+1;
                    ct+=ridx-lidx+1;

                    cr=ridx;
                }

                if(n-ct<=a) ok=mid;
                else ng=mid;
            }

            if(ok==INF) printf("NA\n");
            else printf("%d\n", ok);
        }
    }

    return 0;
}
