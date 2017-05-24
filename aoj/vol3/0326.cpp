#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using ps = pair<string,string>;

int main()
{
    int n,f;
    cin >>n >>f;

    vector<string> name;
    map<ps,int> ct;
    rep(i,n)
    {
        int m;
        cin >>m;

        vector<string> s(m);
        rep(j,m)
        {
            cin >>s[j];
            name.pb(s[j]);
        }
        sort(all(s));

        rep(k,m)rep(j,k) ++ct[ps(s[j],s[k])];
    }

    sort(all(name));
    name.erase(unique(all(name)),name.end());

    int N = name.size();

    set<ps> ans;
    rep(j,N)rep(i,j)
    {
        ps p(name[i],name[j]);
        if(ct[p]>=f) ans.insert(p);
    }

    cout << ans.size() << endl;
    for(const auto &p:ans) cout << p.fi << " " << p.se << endl;
    return 0;
}
