#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

// largest rectangle in histogram
ll calc(const vector<int> &h)
{
    int n = h.size();
    vector<int> L(n),R(n),st(n);

    int t=0;
    rep(i,n)
    {
        while(t>0 && h[st[t-1]]>=h[i]) --t;
        L[i] = (t==0?0:st[t-1]+1);
        st[t++] = i;
    }

    t = 0;
    for(int i=n-1; i>=0; --i)
    {
        while(t>0 && h[st[t-1]]>=h[i]) --t;
        R[i] = (t==0?n:st[t-1]);
        st[t++] = i;
    }

    ll ret = 0;
    rep(i,n) ret = max(ret, (ll)h[i]*(R[i]-L[i]));
    return ret;
}

int main()
{
    int n;
    while(scanf(" %d", &n),n)
    {
        vector<int> h(n);
        rep(i,n) scanf(" %d", &h[i]);
        printf("%lld\n", calc(h));
    }
    return 0;
}
