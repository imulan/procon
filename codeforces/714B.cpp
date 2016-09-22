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
    scanf(" %d", &n);

    set<int> s;
    rep(i,n)
    {
        int a;
        scanf(" %d", &a);
        s.insert(a);
    }

    string ans="YES";

    if(s.size()>3) ans="NO";
    else if(s.size()==3)
    {
        vector<int> z;
        for(const int &i:s) z.pb(i);
        sort(all(z));

        if(z[1]-z[0] != z[2]-z[1]) ans="NO";
    }

    cout << ans << endl;
    return 0;
}
