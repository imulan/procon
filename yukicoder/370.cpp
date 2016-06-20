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

    vector<int> a,b;
    rep(i,m)
    {
        int d;
        scanf(" %d", &d);

        if(d>0) a.pb(d);
        else if(d<0) b.pb(-d);
        else --n;
    }

    sort(all(a));
    sort(all(b));

    int lim=min(n,(int)a.size());

    int ans=12345678;

    //正方向からi個取ってくる
    rep(i,lim+1)
    {
        //負方向からj個取ってくる
        int j=n-i;
        if(j>b.size()) continue;

        int di=0;
        if(i>0) di=a[i-1];

        int dj=0;
        if(j>0) dj=b[j-1];

        int tmp=min(di*2+dj,di+dj*2);
        ans=min(ans,tmp);
    }

    cout << ans << endl;
    return 0;
}
