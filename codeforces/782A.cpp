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
    int n;
    scanf(" %d", &n);

    int ans = 1;
    int ct = 0;

    vector<bool> table(n,false);
    rep(i,2*n)
    {
        int x;
        scanf(" %d", &x);
        --x;

        if(table[x])
        {
            table[x] = false;
            --ct;
        }
        else
        {
            table[x] = true;
            ++ct;
        }
        ans = max(ans,ct);
    }

    printf("%d\n", ans);
    return 0;
}
