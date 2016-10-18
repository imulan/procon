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
    int T;
    scanf(" %d", &T);
    while(T--)
    {
        vector<int> n(9);
        vector<char> c(9);

        rep(i,9) scanf(" %d", &n[i]);
        rep(i,9) scanf(" %c", &c[i]);

        vector<int> x[3];
        rep(i,9)
        {
            if(c[i]=='R') x[0].pb(n[i]);
            if(c[i]=='G') x[1].pb(n[i]);
            if(c[i]=='B') x[2].pb(n[i]);
        }
        rep(i,3) sort(all(x[i]));

        int ans=1;

        rep(i,3)
        {
            if(x[i].size()%3!=0) ans=0;
        }

        if(ans)
        {
            rep(i,3)
            {
                if(x[i].size()==0) continue;

                int ct[10]={0};
                rep(j,x[i].size()) ct[x[i][j]]++;

                int now=1;
                while(ct[now]==0) ++now;

                rep(j,x[i].size()/3)
                {
                    if(ct[now]<3)
                    {
                        if(now<=7 && ct[now+1]>0 && ct[now+2]>0)
                        {
                            --ct[now];
                            --ct[now+1];
                            --ct[now+2];
                        }
                        else
                        {
                            ans=0;
                            break;
                        }
                    }
                    else
                    {
                        ct[now]-=3;
                    }

                    while(ct[now]==0) ++now;
                }

                if(ans==0) break;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
