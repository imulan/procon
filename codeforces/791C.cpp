#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

string nx(string s)
{
    if(s=="Z") return "Aa";

    int i=s.size()-1;
    s[i]++;
    return s;
}

vector<string> solve()
{
    int n,k;
    cin >>n >>k;

    vector<bool> ef(n-k+1);
    rep(i,n-k+1)
    {
        string s;
        cin >>s;
        ef[i] = (s=="YES");
    }

    vector<string> ret;

    string s = "A";

    int st = 0;
    if(!ef[0])
    {
        ret.pb(s);
        ret.pb(s);
        s = nx(s);
        st = 2;
    }
    for(int i=st; i<k; ++i)
    {
        ret.pb(s);
        s = nx(s);
    }

    rep(i,n-k)
    {
        if(ef[i+1])
        {
            ret.pb(s);
            s = nx(s);
        }
        else ret.pb(ret[i+1]);
    }

    return ret;
}

int main()
{
    vector<string> ans = solve();
    rep(i,ans.size())
    {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
