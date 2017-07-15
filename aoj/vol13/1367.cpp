#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> e(m);
    rep(i,m) scanf(" %d", &e[i]);

    vector<bool> ap(n+1);
    for(int i=m-1; i>=0; --i)if(!ap[e[i]])
    {
        printf("%d\n", e[i]);
        ap[e[i]]=true;
    }

    for(int i=1; i<=n; ++i)if(!ap[i]) printf("%d\n", i);
    return 0;
}
