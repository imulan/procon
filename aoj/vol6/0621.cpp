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
    vector<string> f(n);
    rep(i,n) cin >>f[i];

    int ans=n*m;

    //0~i:W, i+1~j:B, j+1~n-1:R で塗る
    rep(i,n-2)for(int j=i+1; j<n-1; ++j)
    {
        int ct=0;
        //W
        for(int y=0; y<=i; ++y)rep(x,m)
        {
            if(f[y][x]!='W') ++ct;
        }
        //B
        for(int y=i+1; y<=j; ++y)rep(x,m)
        {
            if(f[y][x]!='B') ++ct;
        }
        //R
        for(int y=j+1; y<n; ++y)rep(x,m)
        {
            if(f[y][x]!='R') ++ct;
        }

        ans=min(ans,ct);
    }

    cout << ans << endl;
    return 0;
}
