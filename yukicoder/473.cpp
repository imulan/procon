#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;
using P = pair<pi,int>;

int n;
ll x;

int D;
vector<int> d;

void factor()
{
    int X=x+1;
    d.pb(X);
    for(int i=2; i*i<=X; ++i)
    {
        if(X%i==0)
        {
            d.pb(i);
            d.pb(X/i);
        }
    }
    sort(all(d));
    d.erase(unique(all(d)),d.end());

    D = d.size();
}

map<P,int> dp;
int f(int rem, int didx, int val)
{
    if(didx==D) return (rem==0 && val==1);
    if(d[didx]>val)
    {
        if(rem==0) return (val==1);
        return 0;
    }

    ll min_val=1;
    rep(i,rem)
    {
        min_val*=d[didx];
        if(min_val>val) return 0;
    }

    P p = P(pi(rem,didx),val);
    if(dp.count(p)) return dp[p];

    int ret=0;
    ll div=1;
    for(int i=0; i<=rem; ++i)
    {
        if(val%div==0) ret += f(rem-i, didx+1, val/div);
        else break;

        div *= d[didx];
    }

    dp[p] = ret;
    return ret;
}

int main()
{
    cin >>n >>x;
    factor();

    cout << f(n,0,x+1) << endl;
    return 0;
}
