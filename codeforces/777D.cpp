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
    cin.tie(0);ios::sync_with_stdio(false);

    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    for(int i=n-2; i>=0; --i)
    {
        if(s[i]<=s[i+1]) continue;

        int l=1,r=s[i].size();
        while(r-l>1)
        {
            int m=(l+r)/2;
            string t=s[i].substr(0,m);
            if(t<=s[i+1]) l=m;
            else r=m;
        }
        s[i] = s[i].substr(0,l);
    }

    rep(i,n) cout << s[i] << endl;
    return 0;
}
