#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    cin >>n;

    int N=2*n;

    vector<int> L(N);
    rep(i,N) cin >>L[i];

    sort(all(L));

    int ans=0;
    for(int i=0; i<N; i+=2) ans+=L[i];

    cout << ans << endl;
    return 0;
}
