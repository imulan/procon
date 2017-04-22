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
    vector<int> a(n),b(n);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,n) scanf(" %d", &b[i]);

    int k=n/2+1;
    ll A=0,B=0;
    rep(i,n)
    {
        A += a[i];
        B += b[i];
    }

    vector<int> p(n);
    iota(all(p),0);
    while(1)
    {
        ll sa=0,sb=0;
        rep(i,k)
        {
            sa += a[p[i]];
            sb += b[p[i]];
        }

        if(sa*2>A && sb*2>B) break;
        shuffle(all(p),mt19937(time(0)));
    }

    // output
    printf("%d\n", k);
    rep(i,k)
    {
        if(i) printf(" ");
        printf("%d", p[i]+1);
    }
    printf("\n");
    return 0;
}
