#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back

int solve()
{
    int n;
    cin >>n;

    vector<int> v;
    rep(i,n)
    {
        int a;
        cin >>a;
        if(v.size()==0) v.pb(a);
        else
        {
            if(v[v.size()-1]!=a) v.pb(a);
        }
    }

    n = v.size();
    if(n==1) return 1;

    vector<long long> d(n-1);
    rep(i,n-1) d[i] = v[i+1]-v[i];

    // rep(i,n-1) printf(" d[ %d] %d\n", i,d[i]);

    int ans = 1;
    int st = 0;
    while(st<n-1)
    {
        // printf(" st %d\n", st);

        int idx = st;
        while(idx<n-1 && d[st]*d[idx]>0) ++idx;

        int diff = idx-st;
        // printf(" %d\n", diff);
        ans = max(ans,diff+1);
        st = idx;
    }

    return ans;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
