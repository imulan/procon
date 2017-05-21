#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--)
    {
        int n;
        scanf(" %d", &n);
        vector<int> a(n);
        rep(i,n) scanf(" %d", &a[i]);

        int m=0;
        rep(i,n) m=max(m,a[i]);
        printf("%d\n", n-m);
    }
    return 0;
}
