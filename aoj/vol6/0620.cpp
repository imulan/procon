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
    vector<int> a(n+1);
    rep(i,n) cin >>a[i+1];

    for(int k=1; k<=m; ++k)
    {
        int b=1;
        while(1)
        {
            if(b==n) break;

            if(a[b]%k > a[b+1]%k) swap(a[b],a[b+1]);
            ++b;
        }
    }

    rep(i,n) printf("%d\n", a[i+1]);
    return 0;
}
