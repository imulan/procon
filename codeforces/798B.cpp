#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=123456789;

int solve()
{
    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    if(n==1) return 0;

    int ret=INF;
    int R=s[0].size();

    rep(i,R)
    {
        string a = s[0].substr(i) + s[0].substr(0,i);

        bool valid=true;
        int ct=i;
        for(int j=1; j<n; ++j)
        {
            bool found=false;
            rep(k,R)
            {
                string b = s[j].substr(k) + s[j].substr(0,k);
                if(a == b)
                {
                    ct += k;
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                valid=false;
                break;
            }
        }

        if(valid) ret=min(ret,ct);
    }

    if(ret==INF) ret=-1;
    return ret;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
