#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,m;
    cin >>n >>m;

    vector<int> a(m);

    rep(i,m)
    {
        scanf(" %d", &a[i]);
        --a[i];
    }

    vector<int> s(n,0);

    rep(i,m)
    {
        int ct=0;

        rep(j,n)
        {
            int b;
            scanf(" %d", &b);
            --b;

            if(b==a[i])
            {
                ++s[j];
                ++ct;
            }
        }
        s[a[i]]+=n-ct;
    }

    rep(i,n) printf("%d\n", s[i]);
    return 0;
}
