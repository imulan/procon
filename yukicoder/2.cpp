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

//素因数リスト作成
vector<int> pf(int x)
{
    int now=x;
    vector<int> ret;
    for(int i=2; i*i<=x; ++i)
    {
        if(now%i==0)
        {
            ret.pb(i);
            while(now%i==0) now/=i;
        }
    }

    if(now>1) ret.pb(now);

    return ret;
}

vector<int> p;
map<int,bool> dp;

bool dfs(int x)
{
    if(dp.find(x)!=dp.end()) return dp[x];

    bool ret=false;

    //素因数に対して
    for(const auto &d:p)
    {
        //割り切れるなら
        if(x%d==0)
        {
            int nx=x;
            while(nx%d==0)
            {
                nx/=d;
                ret|=!dfs(nx);
            }
        }
    }

    return dp[x]=ret;
}

int main()
{
    ll n;
    cin >>n;

    p=pf(n);

    string ans="Bob";
    if(dfs(n)) ans="Alice";
    cout << ans << endl;
    return 0;
}
