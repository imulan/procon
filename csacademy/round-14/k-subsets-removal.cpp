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
    int ct[1000]={};

    int n,k;
    cin >>n >>k;
    rep(i,n)
    {
        int a;
        cin >>a;
        ++ct[a-1];
    }

    int ans=0;
    rep(i,1000)if(ct[i]>0) ans = max(ans,ct[i]%k);

    cout << ans << endl;
    return 0;
}
