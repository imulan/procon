#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,k;
    cin >>n >>k;

    multiset<int> s;
    rep(i,n)
    {
        int a;
        cin >>a;
        s.insert(a);
    }

    int ans=0;
    for(int i=30; i>=0; --i)
    {
        multiset<int> ns;
        for(const auto &x:s)
        {
            if(x>>i&1) ns.insert(x);
        }

        if(ns.size()>=k)
        {
            s=ns;
            ans+=1<<i;
        }
    }

    cout << ans << endl;
    return 0;
}
