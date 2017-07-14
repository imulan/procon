#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define dbg(x) cout<<#x" = "<<((x))<<endl

const int INF = 191919;

int n,m;
string b[500];

// simple DFS
int dfs(int x, const vector<int> &s)
{
    if(x==n)
    {
        rep(i,m)if(s[i]==1) return -INF;
        return 0;
    }

    int ret = dfs(x+1,s);
    vector<int> ns(s);
    rep(i,m) ns[i] = (ns[i]+(b[x][i]-'0'))%2;
    ret = max(ret,dfs(x+1,ns)+1);

    return ret;
}

int solve1()
{
    vector<int> state(m,0);
    return dfs(0,state);
}

// bitDP
int solve2()
{
    assert(m<25);

    vector<int> meal(n);
    rep(i,n)
    {
        rep(j,m)
        {
            if(b[i][j]=='1') meal[i] |= 1<<j;
        }
        // dbg(bitset<6>(meal[i]));
    }

    vector<int> dp(1<<m,-INF);
    dp[0]=0;
    rep(i,n)
    {
        vector<int> nx(1<<m,-INF);
        rep(mask,1<<m)
        {
            nx[mask] = max(nx[mask],dp[mask]);

            int nmask = mask^meal[i];
            nx[nmask] = max(nx[nmask],dp[mask]+1);
        }

        dp = nx;
    }

    return dp[0];
}

int main(){
    while(cin >>n >>m,n)
    {
        rep(i,n) cin >>b[i];

        int ans1=INF, ans2=INF;

        if(n<m) ans1 = solve1();
        else ans2 = solve2();

        if(n<16 && m<16)
        {
            // dbg(solve1());
            // dbg(solve2());
            assert(solve1() == solve2());
        }

        cout << min(ans1,ans2) << endl;
    }
    return 0;
}
