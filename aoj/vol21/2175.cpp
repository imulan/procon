#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

inline int to_value(char c)
{
    if(c=='A') return 14;
    if(c=='K') return 13;
    if(c=='Q') return 12;
    if(c=='J') return 11;
    if(c=='T') return 10;
    return c-'0';
}

int main()
{
    char trump;
    while(scanf(" %c", &trump),(trump!='#'))
    {
        string s[4][13];
        rep(i,4)rep(j,13) cin >>s[i][j];

        int ns=0,ew=0;
        int dealer=0;

        rep(game,13)
        {
            // printf(" GAME %d: dealer = %d\n",game,dealer);

            int v=to_value(s[dealer][game][0]);
            char lead=s[dealer][game][1];
            if(lead==trump) v+=100;

            int idx=dealer;

            for(int i=1; i<4; ++i)
            {
                int nx=(dealer+i)%4;
                if(s[nx][game][1]!=trump && s[nx][game][1]!=lead) continue;

                int tmp=to_value(s[nx][game][0]);
                if(s[nx][game][1]==trump) tmp+=100;

                // printf(" nx= %d, tmp= %d\n", nx,tmp);
                if(tmp>v)
                {
                    v=tmp;
                    idx=nx;
                }
            }
            
            dealer=idx;
            if(idx%2==0) ++ns;
            else ++ew;
        }

        if(ns<ew) printf("EW %d\n", ew-6);
        else printf("NS %d\n", ns-6);
    }
    return 0;
}
