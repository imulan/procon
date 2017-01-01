#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

char solve()
{
    int n;
    string s;
    cin >>n >>s;

    set<int> alive,D,R;
    rep(i,n)
    {
        alive.insert(i);
        if(s[i]=='D') D.insert(i);
        else R.insert(i);
    }

    int now=0;
    while(1)
    {
        if(D.size()==0) return 'R';
        if(R.size()==0) return 'D';

        if(s[now]=='D')
        {
            auto itr = R.lower_bound(now);
            if(itr==R.end()) itr=R.begin();

            R.erase(itr);
            alive.erase(*itr);
        }
        else
        {
            auto itr = D.lower_bound(now);
            if(itr==D.end()) itr=D.begin();

            D.erase(itr);
            alive.erase(*itr);
        }

        auto nx = alive.upper_bound(now);
        if(nx==alive.end()) now = *alive.begin();
        else now = *nx;
    }
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
