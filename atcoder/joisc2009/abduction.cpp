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

const int mod = 10000000;
const int N=10001;
int dp[N][1001];

int calc(const string &z, int B)
{
    int Z=z.size();

    fill(dp[0],dp[N],0);
    dp[0][0]=1;

    rep(i,Z)
    {
        int s=0;
        // 現在位置
        if(z[i]=='+')
        {
            rep(j,B+1)
            {
                if(j>0) (s+=dp[i][j-1])%=mod;
                dp[i+1][j] = s;
            }
        }
        else
        {
            for(int j=B; j>=0; --j)
            {
                if(j+1<=B) (s+=dp[i][j+1])%=mod;
                dp[i+1][j] = s;
            }
        }
    }

    return dp[Z][B];
}

int main()
{
    int W,H,S;
    string s;

    cin >>W >>H >>S >>s;

    string x="",y="";

    int d;
    if(s[0]=='L')
    {
        d=1;
        x += "+";
    }
    else
    {
        d=0;
        y += "+";
    }

    rep(i,S)
    {
        if(s[i]=='L') d = (d+3)%4;
        else d = (d+1)%4;

        if(d%2==0) y += (d==0)?"+":"-";
        else x += (d==1)?"+":"-";
    }

    ll ans = (ll)calc(x,W)*calc(y,H);
    cout << ans%mod << endl;
    return 0;
}
