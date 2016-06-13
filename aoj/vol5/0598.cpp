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

//左上が(i,j)の位置が紋章かどうか
int em[1000][1000]={0};

int main()
{
    int m,n;
    cin >>m >>n;

    vector<string> s(m);
    rep(i,m) cin >>s[i];

    vector<string> t(2);
    rep(i,2) cin >>t[i];

    //デフォルトで何個あるか
    int def=0;
    rep(i,m-1)rep(j,n-1)
    {
        int v=1;
        rep(y,2)rep(x,2)
        {
            if(s[i+y][j+x]!=t[y][x]) v=0;
        }
        em[i][j]=v;
        def+=v;
    }

    int ans=def;
    string joi="JOI";
    //変更位置
    rep(i,m)rep(j,n)rep(k,3)
    {
        if(s[i][j]==joi[k]) continue;

        int ct=0;
        //左上の位置
        for(int y=-1; y<=0; ++y)for(int x=-1; x<=0; ++x)
        {
            int sy=i+y, sx=j+x;
            if(0<=sy&&sy<m-1 && 0<=sx&&sx<n-1)
            {
                if(em[sy][sx]) --ct;
                else
                {
                    //紋章になったか調べる
                    char tmp=s[i][j];
                    s[i][j]=joi[k];

                    int v=1;
                    rep(p,2)rep(q,2)
                    {
                        if(s[sy+p][sx+q]!=t[p][q]) v=0;
                    }
                    ct+=v;

                    s[i][j]=tmp;
                }
            }
        }

        ans=max(ans,def+ct);
    }

    cout << ans << endl;
    return 0;
}
