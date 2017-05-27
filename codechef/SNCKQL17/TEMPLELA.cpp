#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const string OK="yes", NG="no";

string solve()
{
    int n;
    cin >>n;
    vector<int> h(n);
    rep(i,n) cin >>h[i];

    if(n%2==0) return NG;

    int c=n/2;
    int ct=1;
    rep(i,c+1)
    {
        if(h[i]!=ct) return NG;
        ++ct;
    }

    ct=1;
    for(int i=n-1; i>=c; --i)
    {
        if(h[i]!=ct) return NG;
        ++ct;
    }

    return OK;
}

int main()
{
    int Q;
    cin >>Q;
    while(Q--) cout << solve() << endl;
    return 0;
}
