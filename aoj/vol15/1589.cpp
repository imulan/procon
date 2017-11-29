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

// i限から空いている,j個科目を取った
int dp[50][50]={};

int main()
{
    int n,m,l;
    cin >>n >>m >>l;

    vector<int> s(m),g(m),w(m);
    rep(i,m)
    {
        int d,a,k;
        cin >>d >>a >>k >>w[i];

        s[i] = d*n+a-1;
        g[i] = s[i]+k;
    }

    rep(i,5*n)rep(j,l)rep(k,m)
    {
        if(i<=s[k]) dp[g[k]][j+1] = max(dp[g[k]][j+1], dp[i][j]+w[k]);
    }

    int ans = 0;
    rep(i,50)rep(j,l+1) ans = max(ans,dp[i][j]);
    cout << ans << endl;
    return 0;
}
