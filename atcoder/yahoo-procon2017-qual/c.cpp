#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

string solve()
{
    // cin.tie(0);ios::sync_with_stdio(false);

    int n,k;
    cin >>n >>k;

    vector<int> a(k);
    vector<bool> na(n,true);

    rep(i,k)
    {
        cin >>a[i];
        --a[i];

        na[a[i]]=false;
    }

    set<int> S;
    rep(i,n)
    {
        if(na[i]) S.insert(i);
    }

    vector<string> s(n);
    rep(i,n) cin >>s[i];

    int max_len = 1234567;
    rep(i,k) max_len = min(max_len, (int)s[a[i]].size());

    string ret="";
    rep(i,max_len)
    {
        if(S.size()==0) break;


        char add = s[a[0]][i];
        bool ok = true;
        for(int j=1; j<k; ++j)
        {
            if(s[a[j]][i] != add) ok = false;
        }

        if(ok) ret+=add;
        else return "-1";

        vector<int> rm;
        for(const auto &x:S)
        {
            if(s[x].size() == i) rm.pb(x);
            else
            {
                if(s[x][i]!=add) rm.pb(x);
            }
        }

        rep(j,rm.size()) S.erase(rm[j]);
    }

    if(S.size()==0) return ret;
    return "-1";
}

int main()
{
    cout << solve() << endl;
    return 0;
}
