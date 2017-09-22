#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define rrep(i,n) for(int i=(int)n-1; i>=0; --i)
#define inf 1e9

int lis(vector<int>& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> dp(n + 1, INF);
    rep(i, n) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    
}
