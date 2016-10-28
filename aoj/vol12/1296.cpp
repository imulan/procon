#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=123456789;

int n;
string a[10],b[10];
string s,g;

map<string,int> dp;
int dfs(string now)
{
    if(now.size()>g.size()) return INF;
    if(now.size()==g.size())
    {
        if(now==g) return 0;
        else return INF;
    }

    if(dp.find(now)!=dp.end()) return dp[now];

    int ret=INF;

    int N=now.size();
    rep(i,n)
    {
        int A=a[i].size();

        string nx="";
        int idx=0;
        while(idx<N)
        {
            if(idx+A<=N && now.substr(idx,A)==a[i])
            {
                nx+=b[i];
                idx+=A;
            }
            else nx+=now[idx++];
        }

        if(now==nx) continue;
        // cout <<"now= "<<now<<" ,nx= "<<nx<<endl;
        ret=min(ret,dfs(nx)+1);
    }

    return dp[now]=ret;
}

int main()
{
    while(cin >>n,n)
    {
        rep(i,n) cin >>a[i] >>b[i];
        cin >>s >>g;

        dp.clear();

        int ans=dfs(s);
        if(ans==INF) ans=-1;
        cout << ans << endl;
    }
    return 0;
}
