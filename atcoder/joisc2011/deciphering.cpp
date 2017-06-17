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

const int mod=10000000;
int dp[26]={};

int ng[26][26]={};

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int S;
    string s;
    cin >>S >>s;

    int m;
    cin >>m;
    rep(i,m)
    {
        char a,b;
        cin >>a >>b;
        ng[a-'A'][b-'A']=1;
    }

    rep(i,S)
    {
        int sum = 1;
        rep(j,26)if(!ng[j][s[i]-'A']) (sum+=dp[j])%=mod;
        dp[s[i]-'A']=sum;
    }

    int ans = 0;
    rep(i,26) (ans+=dp[i])%=mod;
    cout << ans << endl;
    return 0;
}
