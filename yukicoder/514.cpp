#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll N=1000000000;

int main()
{
    ll P,Q;

    cout << 0 << " " << 0 << endl;
    cin >>P;

    cout << N << " " << 0 << endl;
    cin >>Q;

    cout << (P-Q+N)/2 << " " << (P+Q-N)/2 << endl;
    return 0;
}
