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
    int ans=0;
    int m=-1;
    int n;
    cin >>n;
    rep(i,n)
    {
        int a;
        scanf(" %d",&a);
        if(m<a)
        {
            ans=i+1;
            m=a;
        }
    }
    cout << ans << endl;
    return 0;
}
