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
    ll n;
    cin >>n;
    int ans=0;
    while(n>1)
    {
        if(n%2==0) n/=2;
        else ++n;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
