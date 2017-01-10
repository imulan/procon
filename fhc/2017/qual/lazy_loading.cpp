#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int solve()
{
    int n;
    cin >>n;
    vector<int> w(n);
    rep(i,n) cin >>w[i];

    sort(all(w),greater<int>());

    for(int i=n; i>=1; --i)
    {
        int rem = n-i;
        int need = 0;

        rep(j,i)
        {
            if(w[j]<50)
            {
                need += (50-w[j]+w[j]-1)/w[j];
            }
        }

        if(need<=rem) return i;
    }

    return 0;
}

int main()
{
    int T;
    cin >>T;
    rep(cases,T)
    {
        printf("Case #%d: %d\n", cases+1, solve());
    }
    return 0;
}
