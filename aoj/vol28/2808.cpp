#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=100000;
const string INF="zzzzzzzz";

set<string> ban[5];
string ans=INF;

void dfs(int d, string s)
{
    if(d==4) return;

    rep(i,26)
    {
        char add='a'+i;
        string nx = s+string{add};
        if(!ban[d+1].count(nx))
        {
            if(nx.size()<ans.size()) ans=nx;
            else if(nx.size()==ans.size()) ans=min(ans,nx);
        }
        dfs(d+1,nx);
    }
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int n;
    cin >>n;
    rep(i,n)
    {
        string s;
        cin >>s;

        int S=s.size();
        for(int j=1; j<=4; ++j)
        {
            rep(k,S-j+1) ban[j].insert(s.substr(k,j));
        }
    }

    dfs(0,"");

    assert(ans!=INF);
    cout << ans << endl;
    return 0;
}
