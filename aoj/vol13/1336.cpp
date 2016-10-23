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

int main()
{
    int n,l;
    while(cin >>n >>l,n)
    {
        vector<pi> ant(n);
        rep(i,n)
        {
            char c;
            int p;
            scanf(" %c %d", &c, &p);

            if(c=='L') ant[i]=pi(-1,p);
            else ant[i]=pi(1,p);
        }

        int t=0;
        int last=-1;

        while(1)
        {
            int alive=n;
            rep(i,n) if(ant[i].se==0 || ant[i].se==l) --alive;

            if(alive==0) break;
            else if(alive==1)
            {
                rep(i,n) if(0<ant[i].se && ant[i].se<l) last=i+1;
            }
            else if(alive==2)
            {
                rep(i,n) if(ant[i].se==1) last=i+1;
            }

            // printf(" t= %d, last= %d\n", t,last);
            // rep(i,n) printf("  %d : pos %d, %c\n", i,ant[i].se,(ant[i].fi==-1)?'L':'R');

            int nf[100];
            fill(nf,nf+100,-1);
            rep(i,n)
            {
                int nx=ant[i].se+ant[i].fi;

                if(nx==0 || nx==l) ant[i]=pi(0,nx);
                else
                {
                    ant[i].se+=ant[i].fi;
                    if(nf[ant[i].se]==-1) nf[ant[i].se]=i;
                    else
                    {
                        int idx=nf[ant[i].se];
                        ant[i].fi = -ant[i].fi;
                        ant[idx].fi = -ant[idx].fi;
                        // printf(" swap %d, %d\n", idx,i);

                    }
                }
            }

            ++t;
        }

        printf("%d %d\n", t, last);
    }
    return 0;
}
