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

using pi = pair<int,int>;

const int N = 1010;
bool dp[N][2*N]={};
pi p[N][2*N];

int main()
{
    int n,k;
    string s;
    cin >>n >>k >>s;

    dp[0][N] = true;
    rep(i,n)rep(j,2*N)if(dp[i][j])
    {
        bool q = s[i]=='?';
        int d = j-N;

        // win
        if(q || s[i]=='W')
        {
            if(!(i+1<n && abs(d+1)==k))
            {
                dp[i+1][j+1] = true;
                p[i+1][j+1] = {i,j};
            }
        }
        // lose
        if(q || s[i]=='L')
        {
            if(!(i+1<n && abs(d-1)==k))
            {
                dp[i+1][j-1] = true;
                p[i+1][j-1] = {i,j};
            }
        }
        // draw
        if(q || s[i]=='D')
        {
            dp[i+1][j] = true;
            p[i+1][j] = {i,j};
        }
    }

    string ans = "NO";
    pi now(-1,-1);
    if(dp[n][N+k]) now = {n,N+k};
    if(dp[n][N-k]) now = {n,N-k};

    if(now.fi!=-1)
    {
        ans = s;
        rep(i,n)
        {
            pi nx = p[now.fi][now.se];

            int d = now.se - nx.se;
            char c = '?';
            if(d==1) c = 'W';
            else if(d==0) c = 'D';
            else c = 'L';

            ans[n-1-i] = c;
            now = nx;
        }
    }

    cout << ans << endl;
    return 0;
}
