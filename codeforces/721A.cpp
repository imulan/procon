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
    string s;
    cin >>n >>s;

    vector<int> ans;

    int st=-1;
    rep(i,n)
    {
        if(s[i]=='B')
        {
            if(st==-1) st=i;
        }
        else
        {
            if(st!=-1)
            {
                ans.pb(i-st);
                st=-1;
            }
        }
    }
    if(st!=-1) ans.pb(n-st);

    cout << ans.size() << endl;
    rep(i,ans.size())
    {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
