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
    int n,m;
    cin >>n >>m;
    vector<int> ct(n);
    rep(i,m)
    {
        int a,b;
        cin >>a >>b;
        ++ct[a-1];
        ++ct[b-1];
    }
    rep(i,n) printf("%d\n", ct[i]);
    return 0;
}
