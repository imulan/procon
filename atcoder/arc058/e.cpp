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

const ll mod=1e9+7;

int N,X,Y,Z;
int S;

bool nx[1<<16][11];
ll dp[41][1<<16];

ll dfs(int now, int state)
{
    if(dp[now][state]>=0) return dp[now][state];
    if(now==N) return 1;

    ll ret=0;
    //次に選ぶ数
    for(int i=1; i<=10; ++i)
    {
        if(nx[state][i])
        {
            ret+=dfs(now+1, ((state<<i)+(1<<(i-1)))%(1<<S));
            ret%=mod;
        }
    }

    return dp[now][state]=ret;
}

int main()
{
    cin >>N >>X >>Y >>Z;
    S=X+Y+Z-1;

    //状態maskの時に，次の数iが来ていいかチェックしておく
    rep(mask,1<<S)
    {
        //直前の状態を復元
        vector<int> b;
        int st=0;
        rep(i,S)
        {
            if(mask>>i&1)
            {
                b.pb(i-st+1);
                st=i+1;
            }
        }

        int B=b.size();
        //jを次に選んだ時にXYZを含まないかチェック
        for(int i=1; i<=10; ++i)
        {
            bool ok=true;
            //直前から順番に見ていき貪欲に足していく
            int x=0,y=0,z=i;
            int bidx=0;
            while(bidx<B && z<Z) z+=b[bidx++];
            while(bidx<B && y<Y) y+=b[bidx++];
            while(bidx<B && x<X) x+=b[bidx++];
            if(x==X && y==Y && z==Z) ok=false;

            nx[mask][i]=ok;
        }
    }

    //全体は10^N通り
    ll p10=1;
    rep(i,N) p10=(p10*10)%mod;

    memset(dp,-1,sizeof(dp));
    //XYZを含まない数列の個数
    ll r=dfs(0,0);
    //全体から引く
    ll ans=(p10-r+mod)%mod;
    cout << ans << endl;
    return 0;
}
