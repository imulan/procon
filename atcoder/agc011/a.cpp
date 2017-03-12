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
    int n,c,k;
    scanf(" %d %d %d", &n, &c, &k);
    vector<int> t(n);
    rep(i,n) scanf(" %d", &t[i]);
    sort(all(t));
    
    int ans=0;
    int idx=0;
    while(idx<n)
    {
        int start = t[idx];
        int s_idx=idx;
        ++ans;

        while(idx<n && start+k>=t[idx])
        {
            ++idx;
            if(idx-s_idx==c) break;
        }
    }

    printf("%d\n", ans);
    return 0;
}
