#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back

const string ok = "yes", ng = "no";

string solve()
{
    string t,p;
    cin >>t >>p;
    int T = t.size(), P = p.size();

    vector<int> head,tail;

    // head
    int idx = 0;
    rep(i,T)
    {
        if(idx<P && p[idx]==t[i])
        {
            head.pb(i);
            ++idx;
        }
    }

    // tail
    idx = P-1;
    for(int i=T-1; i>=0; --i)
    {
        if(idx>=0 && p[idx]==t[i])
        {
            tail.pb(i);
            --idx;
        }
    }
    reverse(tail.begin(),tail.end());

    if(P != head.size() || head.size() != tail.size()) return ng;

    rep(i,P)if(head[i]!=tail[i]) return ng;

    return ok;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
