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
    string s;
    int m;
    cin >>s >>m;

    int S=s.size();
    unordered_map<string,int> ct;
    rep(i,S)
    {
        for(int j=1; j<=10; ++j)
        {
            if(i+j-1>=S) break;

            string t=s.substr(i,j);
            if(ct.find(t) == ct.end()) ct[t]=1;
            else ++ct[t];
        }
    }

    ll ans=0;
    rep(i,m)
    {
        string c;
        cin >>c;
        ans+=ct[c];
    }
    cout << ans << endl;
    return 0;
}
