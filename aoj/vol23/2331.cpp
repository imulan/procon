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
    int n;
    cin >>n;

    int r[100003]={0};
    rep(i,n)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        ++r[a];
        --r[b+1];
    }

    rep(i,100002) r[i+1]+=r[i];

    //number of people to invite
    int ans=0;

    for(int i=n; i>0; --i)
    {
        if(r[i+1]>=i)
        {
            ans=i;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}
