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

const int A=40000;
const int B=80000;

int dp[2][B+1]={};

string solve()
{
    int n;
    cin >>n;
    vector<int> k(n),d(n);
    rep(i,n) cin >>k[i] >>d[i];

    int K=0,D=0;
    rep(i,n)
    {
        K+=k[i];
        D+=d[i];
    }

    if(K!=D) return "invalid";

    dp[0][A]=1;
    auto pre = dp[0], now = dp[1];
    rep(i,n)
    {
        fill(now,now+B+1,0);
        rep(j,B+1)
        {
            if(pre[j]) now[j+k[i]] = now[j-d[i]] = 1;
        }
        swap(pre,now);
    }

    return (pre[A]?"valid":"invalid");
}

int main()
{
    cout << solve() << endl;
    return 0;
}
