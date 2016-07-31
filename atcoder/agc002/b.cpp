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

int main()
{
    int n,m;
    cin >>n >>m;

    //赤玉がある可能性がある:1/ない:0
    vector<int> r(n,0);
    r[0]=1;
    //箱iの玉の数
    vector<int> ct(n,1);

    rep(i,m)
    {
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;

        if(ct[x]==1)
        {
            if(r[x]==1)
            {
                //確実に赤玉が移動する
                r[x]=0;
                r[y]=1;
            }
            --ct[x];
            ++ct[y];
        }
        else
        {
            if(r[x]==1)
            {
                //赤玉が移動するかもしれない
                r[y]=1;
            }
            --ct[x];
            ++ct[y];
        }
    }

    int ans=0;
    rep(i,n) ans+=r[i];
    cout << ans << endl;
    return 0;
}
