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

const ll mod = 1e9+7;
ll dp[52][3][3]={};
int main()
{
    int n;
    cin >>n;
    string s[2];
    rep(i,2) cin >>s[i];

    int p = 0;
    if(s[0][0]==s[1][0])
    {
        rep(i,3) dp[0][i][i]=1;
        ++p;
    }
    else
    {
        rep(i,3)rep(j,3)if(i!=j)
        {
            dp[0][i][j]=1;
            dp[1][i][j]=1;
        }
        p+=2;
    }

    while(p<n)
    {
        bool yoko = true;
        if(p==n-1) yoko=false;
        else
        {
            if(s[0][p]!=s[0][p+1]) yoko=false;
        }

        if(yoko)
        {
            rep(i,3)rep(j,3)if(i!=j)
            {
                rep(k,3)if(k!=i && k!=j) (dp[p][i][j]+=dp[p-1][k][k])%=mod;

                rep(k,3)rep(l,3)if(k!=l && k!=i && l!=j) (dp[p][i][j]+=dp[p-1][k][l])%=mod;

                dp[p+1][i][j] = dp[p][i][j];
            }
            p+=2;
        }
        else
        {
            rep(i,3)
            {
                rep(k,3)if(k!=i) (dp[p][i][i]+=dp[p-1][k][k])%=mod;

                rep(k,3)rep(l,3)if(k!=l && k!=i && l!=i) (dp[p][i][i]+=dp[p-1][k][l]%=mod);
            }
            ++p;
        }
    }

    ll ans = 0;
    rep(i,3)rep(j,3) (ans+=dp[n-1][i][j])%=mod;
    cout << ans << endl;
    return 0;
}
