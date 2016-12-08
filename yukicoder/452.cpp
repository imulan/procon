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
    int c[200][100][100];

    scanf(" %d %d", &n, &m);
    rep(i,m)rep(j,n)rep(k,n) scanf(" %d", &c[i][j][k]);

    vector<vector<int>> bingo[200];
    rep(i,m)
    {
        vector<int> tmp(n);

        // 縦
        rep(j,n)
        {
            rep(k,n) tmp[k]=c[i][k][j];
            sort(all(tmp));
            bingo[i].pb(tmp);
        }
        // 横
        rep(j,n)
        {
            rep(k,n) tmp[k]=c[i][j][k];
            sort(all(tmp));
            bingo[i].pb(tmp);
        }
        //斜め
        rep(j,n) tmp[j]=c[i][j][j];
        sort(all(tmp));
        bingo[i].pb(tmp);
        rep(j,n) tmp[j]=c[i][n-1-j][j];
        sort(all(tmp));
        bingo[i].pb(tmp);
    }

    int ans=123456;
    rep(i,m)rep(j,i)
    {
        rep(a,bingo[i].size())rep(b,bingo[j].size())
        {
            int S=0;
            int x=0,y=0;

            while(x<n && y<n)
            {
                if(bingo[i][a][x] < bingo[j][b][y]) ++x;
                else if(bingo[i][a][x] > bingo[j][b][y]) ++y;
                else
                {
                    ++x;
                    ++y;
                }
                ++S;
            }
            S+=n-x+n-y;
            
            ans=min(ans,S-1);
        }
    }

    if(ans<1) ans=1;
    printf("%d\n", ans);
    return 0;
}
