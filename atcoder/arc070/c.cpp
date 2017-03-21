#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll solve(int x)
{
    ll n=1;
    while(n*(n+1)/2<x) ++n;
    return n;
}

int main()
{
    int x;
    cin >>x;
    cout << solve(x) << endl;
    return 0;
}
