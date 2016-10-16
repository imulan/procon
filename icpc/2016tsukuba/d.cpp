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
    string s,t;
    cin >>s >>t;

    int S=s.size(), T=t.size();

    int ans=0;
    for(int L=min(S,T); L>=1; --L)
    {
        set<vector<int>> h;

        vector<int> ct(26,0);
        rep(i,L) ++ct[t[i]-'a'];

        h.insert(ct);
        for(int i=1; i<=T-L; ++i)
        {
            --ct[t[i-1]-'a'];
            ++ct[t[i-1+L]-'a'];
            h.insert(ct);
        }

        bool found=false;

        ct=vector<int>(26,0);
        rep(i,L) ++ct[s[i]-'a'];

        if(h.find(ct) != h.end())
        {
            ans=L;
            break;
        }

        for(int i=1; i<=S-L; ++i)
        {
            --ct[s[i-1]-'a'];
            ++ct[s[i-1+L]-'a'];
            if(h.find(ct) != h.end())
            {
                found=true;
                ans=L;
                break;
            }
        }

        if(found) break;
    }

    printf("%d\n", ans);
    return 0;
}
