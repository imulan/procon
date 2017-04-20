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
    int n,m;
    cin >>n >>m;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int ans=0;
    int start=0;
    while(1)
    {
        int p=0, q=123456789;
        rep(i,m)
        {
            p = max(p,a[(start+i)%n]);
            q = min(q,a[(start+i)%n]);
        }
        ans += p-q;

        (start+=m)%=n;
        if(start==0) break;
    }

    printf("%d\n", ans);
    return 0;
}
