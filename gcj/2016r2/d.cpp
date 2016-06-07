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

int n;
string s[25];
string t[25];

//worker,machine
bool dfs(int w, int m)
{
    bool ret=true;
    //次に出勤する人
    rep(i,n)
    {
        //既にいる
        if(w>>i&1) continue;

        //選択肢の数
        int ct=0;
        //動かすマシーン
        rep(j,n)
        {
            if((m>>j&1)==0 && t[i][j]=='1')
            {
                ret&=dfs(w+(1<<i),m+(1<<j));
                ++ct;
            }
        }

        if(ct==0) return false;
    }

    return ret;
}

int main()
{
    int T;
    cin >>T;
    rep(q,T)
    {
        cin >>n;
        rep(i,n) cin >>s[i];

        int ans=n*n;
        rep(mask,1<<(n*n))
        {
            rep(i,n) t[i]=s[i];

            int ct=0;
            int cost=0;
            rep(i,n)rep(j,n)
            {
                if(mask>>ct&1)
                {
                    t[i][j]='1';
                    ++cost;
                }
                ++ct;
            }

            if(dfs(0,0)) ans=min(ans,cost);
        }

        printf("Case #%d: ", q+1);
        printf("%d\n", ans);
    }
    return 0;
}
