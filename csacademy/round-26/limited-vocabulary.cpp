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
    int ans=-1;
    rep(i,n)
    {
        string s;
        cin >>s;
        int S=s.size();

        int ct[26]={};
        rep(j,S) ++ct[s[j]-'a'];

        int kind=0;
        rep(j,26) kind+=(ct[j]>0);

        if(kind<=k) ans=max(ans,S);
    }
    
    cout << ans << endl;
    return 0;
}
