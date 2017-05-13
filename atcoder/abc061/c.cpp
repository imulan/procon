#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=101010;
ll ct[N]={};

int main()
{
    int n;
    ll k;
    scanf(" %d %lld", &n, &k);

    rep(i,n)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        ct[a] += b;
    }

    int ans=1;
    ll s=0;
    while(1)
    {
        if(s+ct[ans]>=k) break;
        s += ct[ans];
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
