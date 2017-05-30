#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int f(int x)
{
    int ct=0;
    for(int i=1; i<=x; ++i) ct+=(x%i==0);
    return ct;
}

int main()
{
    int a,b;
    cin >>a >>b;

    int ans = 0;
    for(int i=a; i<=b; ++i) ans+=f(i)%2;
    cout << ans << endl;
    return 0;
}
