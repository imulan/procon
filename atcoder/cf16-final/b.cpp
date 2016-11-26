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
    cin >>n;

    vector<int> ans;
    int lim=1;
    while(lim*(lim+1)/2 < n) ++lim;

    // printf("lim %d\n", lim);
    for(int i=lim; i>=1; --i)
    {
        if(n-i>=0)
        {
            printf("%d\n", i);
            n-=i;
        }
    }
    return 0;
}
