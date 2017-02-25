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
    int n,m;
    cin >>n >>m;

    int G[50][50]={};
    rep(i,m)
    {
        int a,b;
        cin >>a >>b;
        G[a][b]=G[b][a]=1;
    }

    int ans=0;
    int x[4];
    rep(i,n)rep(j,i)rep(k,j)rep(l,k)
    {
        x[0]=l;
        x[1]=k;
        x[2]=j;
        x[3]=i;

        do{
            int ok=1;
            rep(p,4)rep(q,4)
            {
                if((p-q+4)%4==1 || (p-q+4)%4==3)
                {
                    if(!G[x[p]][x[q]]) ok=0;
                }
                else
                {
                    if(G[x[p]][x[q]]) ok=0;
                }

                if(!ok) p=q=4;
            }
            if(ok)
            {
                ++ans;
                break;
            }
        }while(next_permutation(x,x+4));
    }
    cout << ans << endl;
    return 0;
}
