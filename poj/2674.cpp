#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=32000;

char name[N][300];
int d[N];
double p[N];

int main()
{
    int n;
    while(scanf(" %d", &n),n)
    {
        double L,V;
        scanf(" %lf %lf", &L, &V);

        rep(i,n)
        {
            char dir;
            double pos;
            scanf(" %c %lf %s", &dir, &pos, name[i]);

            p[i]=pos;
            if(dir=='p' || dir=='P') d[i]=1;
            else d[i]=0;
        }

        int p_idx=-1, n_idx=-1;
        rep(i,n)
        {
            if(d[i]==1)
            {
                p_idx=i;
                break;
            }
        }
        for(int i=n-1; i>=0; --i)
        {
            if(d[i]==0)
            {
                n_idx=i;
                break;
            }
        }

        double T;
        int a_idx;
        bool positive;
        if(n_idx==-1) positive=true;
        else if(p_idx==-1) positive=false;
        else
        {
            if(L-p[p_idx]>p[n_idx]) positive=true;
            else positive=false;
        }

        if(positive)
        {
            T=(L-p[p_idx])/V;
            a_idx=p_idx;
            for(int i=p_idx+1; i<n; ++i)
            {
                if(d[i]==0) ++a_idx;
            }
        }
        else
        {
            T=p[n_idx]/V;
            a_idx=n_idx;
            rep(i,n_idx)
            {
                if(d[i]==1) --a_idx;
            }
        }

        printf("%13.2f %s\n", floor(100*T)/100, name[a_idx]);
    }
    return 0;
}
