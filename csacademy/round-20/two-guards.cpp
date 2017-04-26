#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=100000;

int main()
{
    int a[N+1]={};
    for(int i=1; i<=N; i+=2) a[i]=1;
    for(int i=1; i<=N; i+=3) a[i]=1;

    int A,B;
    cin >>A >>B;

    int ans=0;
    for(int i=A; i<=B; ++i) ans += !a[i];
    cout << ans << endl;
    return 0;
}
