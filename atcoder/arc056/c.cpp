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

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> P;

int main()
{
    int n,k,w[17][17];
    cin >>n >>k;
    rep(i,n)rep(j,n) cin >>w[i][j];

    int ans=k;

    vector<vi> g;
    rep(i,n) g.pb(vi(1,i));

    /*
    rep(i,g.size())
    {
        printf("g[%d]:", i);
        rep(j,g[i].size()) printf(" %d", g[i][j]);
        printf("\n");
    }
    */

    while(g.size()>1)
    {
        //現状態のスコアを計算
        int t=k*g.size();
        rep(i,g.size())rep(j,i)
        {
            rep(a,g[i].size())rep(b,g[j].size())
            {
                t-=w[g[i][a]][g[j][b]];
            }
        }
        //printf("t=%d\n", t);
        ans=max(ans,t);

        //グループ結合
        vector<P> score;
        //iとjを結合する時
        rep(i,g.size())rep(j,i)
        {
            int cw=0;
            rep(a,g[i].size())rep(b,g[j].size())
            {
                cw+=w[g[i][a]][g[j][b]];
            }

            score.pb(P(cw,pi(i,j)));
        }

        sort(all(score),greater<P>());

        pi con=score[0].se;
        //xとyをつなぐ
        int x=con.fi,y=con.se;
        rep(i,g[y].size()) g[x].pb(g[y][i]);
        g.erase(g.begin()+y);
    }

    cout << ans << endl;
    return 0;
}
