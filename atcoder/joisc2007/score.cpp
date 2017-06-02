#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

int main()
{
    int n;
    cin >>n;

    int ct[101]={};
    vector<int> a(n);
    rep(i,n)
    {
        cin >>a[i];
        ++ct[a[i]];
    }

    int sum[101]={};
    for(int i=99; i>=0; --i) sum[i]=sum[i+1]+ct[i+1];

    rep(i,n) cout << 1+sum[a[i]] << endl;
    return 0;
}
