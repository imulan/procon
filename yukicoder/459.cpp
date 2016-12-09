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
    cin.tie(0);ios::sync_with_stdio(false);

    int h,w,n;
    cin >>h >>w >>n;

    vector<string> s(h);
    rep(i,h) cin >>s[i];

    vector<pi> c(n);
    rep(i,n)
    {
        int x;
        cin >>x;
        c[i]=pi(x,i);
    }
    sort(all(c));


    // その列に積み上がっているブロックの個数
    vector<int> num(w);
    rep(x,w)
    {
        rep(y,h)
        {
            if(s[y][x]=='#')
            {
                num[x]=h-y;
                break;
            }
        }
    }

    // その列にブロックを落とせる回数
    vector<int> ct(w,0);
    rep(i,n)rep(j,3) ++ct[c[i].fi+j];

    vector<vector<string>> ans(n,vector<string>(3,string(3,'.')));

    rep(i,n)
    {
        int b[3]={};
        bool all_zero=true;
        rep(j,3)
        {
            if((ct[c[i].fi+j]-1)*3 < num[c[i].fi+j])
            {
                b[j] = num[c[i].fi+j]-(ct[c[i].fi+j]-1)*3;
                all_zero=false;
                assert(b[j]>0);
                assert(b[j]<=3);
            }
        }

        if(all_zero)
        {
            rep(j,3)
            {
                if(num[c[i].fi+j] > 0)
                {
                    b[j]=1;
                    break;
                }
            }
        }

        // output
        rep(j,3)rep(k,3)
        {
            if(j<b[k]) ans[c[i].se][j][k]='#';
        }

        rep(j,3) --ct[c[i].fi+j];
        rep(j,3) num[c[i].fi+j]-=b[j];
    }

    rep(i,n)rep(j,3) cout << ans[i][j] << '\n';

    return 0;
}
