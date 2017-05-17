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
    int n;
    ll L;
    scanf(" %d %lld", &n, &L);
    vector<int> a(n),b(n);
    rep(i,n) scanf(" %d %d", &a[i], &b[i]);

    vector<int> w(n);
    ll s;

    int l=0,r=1000000000;
    while(r-l>1)
    {
        int m = (l+r)/2;

        s = 0;
        rep(i,n)
        {
            int water;
            if(a[i] >= m) water = a[i];
            else water = min(m,b[i]);

            s += water;
            w[i] = water;
        }

        if(s<=L) l=m;
        else r=m;
    }

    s = 0;
    rep(i,n)
    {
        int water;
        if(a[i] >= l) water = a[i];
        else water = min(l,b[i]);

        s += water;
        w[i] = water;
    }

    ll rem = L-s;
    rep(i,n)
    {
        if(rem>0 && w[i]<b[i])
        {
            ++w[i];
            --rem;
        }
    }

    printf("%d\n", *max_element(all(w)) - *min_element(all(w)));
    return 0;
}
