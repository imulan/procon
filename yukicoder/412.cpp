#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    vector<int> s(3);
    rep(i,3) cin >>s[i];
    sort(all(s));
    int n;
    cin >>n;
    vector<int> e(n);
    rep(i,n) cin >>e[i];
    sort(all(e));

    ll pw[31];
    pw[0]=1;
    for(int i=1; i<31; ++i) pw[i]=pw[i-1]*2;

    ll ans=0;
    // k<j<i
    rep(i,n)rep(j,i)rep(k,j)
    {
        if(s[0]<=e[k] && s[1]<=e[j] && s[2]<=e[i]) ans+=pw[k];
    }
    cout << ans << endl;
    return 0;
}
