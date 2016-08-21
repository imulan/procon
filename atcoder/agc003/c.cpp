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

    //value -> index
    map<int,int> m;
    vector<int> a(n);
    rep(i,n)
    {
        scanf(" %d", &a[i]);
        m[a[i]]=i;
    }

    //sorted_a
    vector<int> b(a);
    sort(all(b));

    int ans=0;
    rep(i,n)
    {
        // printf("%d %d\n",i,m[b[i]]);
        if(i%2 != m[b[i]]%2) ++ans;
    }
    cout << ans/2 << endl;
    return 0;
}
