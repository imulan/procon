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
    vector<int> x(n);
    rep(i,n) cin >>x[i];
    sort(all(x));

    int l=0, r=1000000001;
    while(r-l>1)
    {
        int m=(l+r)/2;
        int ct=0;

        int st=0,idx=0;
        while(st<n)
        {
            ++ct;
            while(idx<n-1 && x[idx+1]-x[st]<=m) ++idx;
            while(st<n && abs(x[idx]-x[st])<=m) ++st;
        }

        if(ct<=k) r=m;
        else l=m;
    }

    cout << r << endl;
    return 0;
}
