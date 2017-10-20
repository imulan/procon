#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const string ok = "Yes", ng = "No";

string s;
int n;

bool check()
{
    string t = "tiech";
    rep(i,n)
    {
        bool other = true;
        rep(j,5)if(s[i]==t[j]) other = false;
        if(other) return false;
    }

    int e=0,c=0;
    rep(i,n)
    {
        if(s[i]=='e') ++e;
        else if(s[i]=='c')
        {
            --e;
            ++c;
        }
        else if(s[i]=='h') --c;

        if(e<0 || c<0) return false;
    }
    return true;
}

int dp[101][17][17][17][17];
int dfs(int x, int t1, int i, int t2, int e)
{
    if(dp[x][t1][i][t2][e]>=0) return dp[x][t1][i][t2][e];
    if(x==n)
    {
        if(t1+i+t2+e == 0) return 1;
        return 0;
    }

    int ret = 0;
    if(s[x]=='t')
    {
        if(t1>0) ret |= dfs(x+1,t1-1,i+1,t2,e);
        if(t2>0) ret |= dfs(x+1,t1,i,t2-1,e+1);
    }
    else if(s[x]=='i')
    {
        if(i>0) ret |= dfs(x+1,t1,i-1,t2+1,e);
    }
    else if(s[x]=='e')
    {
        if(e>0) ret |= dfs(x+1,t1,i,t2,e-1);
    }
    else ret |= dfs(x+1,t1,i,t2,e);

    return dp[x][t1][i][t2][e] = ret;
}

string solve()
{
    if(n%6!=0) return ng;
    if(!check()) return ng;

    memset(dp,-1,sizeof(dp));
    return (dfs(0,n/6,0,0,0)?ok:ng);
}

int main()
{
    cin >>s;
    n = s.size();
    cout << solve() << endl;
    return 0;
}
