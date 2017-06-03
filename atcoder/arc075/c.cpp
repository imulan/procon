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

int dp[10101]={};

int main()
{
    int n;
    cin >>n;
    vector<int> s(n);
    rep(i,n) cin >>s[i];

    dp[0]=1;
    rep(i,n)
    {
        for(int j=10000; j>=0; --j)
        {
            if(dp[j]) dp[j+s[i]]=1;
        }
    }

    int ans=0;
    rep(i,10001)if(dp[i] && i%10!=0) ans=i;
    cout << ans << endl;
    return 0;
}
