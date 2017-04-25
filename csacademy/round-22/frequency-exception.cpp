#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int solve()
{
    int n;
    cin >>n;

    vector<int> a(n);
    map<int,int> ct;
    rep(i,n)
    {
        cin >>a[i];
        ++ct[a[i]];
    }

    map<int,int> freq;
    for(const auto &p:ct) ++freq[p.se];

    for(const auto &p:ct)
    {
        if(freq[p.se]==1) return p.fi;
    }

    assert(false);
}

int main()
{
    cout << solve() << endl;
    return 0;
}
