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

//約数列挙
vi div_list(int x)
{
    vi v;
    for(int i=1; i*i<=x; ++i)
    {
        if(x%i==0)
        {
            v.pb(i);
            if(i!=x/i) v.pb(x/i);
        }
    }
    sort(all(v));
    return v;
}

int main()
{
    int n;
    cin >>n;

    vector<int> x(n);
    rep(i,n) scanf(" %d", &x[i]);
    sort(all(x));

    //それぞれの値のindexを保存
    map<int,int> idx;
    rep(i,n) idx[x[i]]=i;

    vi dp(n,1);

    rep(i,n)
    {
        //printf("now= %d\n", x[i]);
        vi d=div_list(x[i]);
        rep(j,d.size())
        {
            //約数
            int y=d[j];
            if(idx.find(y)!=idx.end() && y<x[i])
            {
                //printf("  y=%d\n", y);
                dp[i]=max(dp[i],dp[idx[y]]+1);
            }
        }
    }

    int ans=1;
    rep(i,n) ans=max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
