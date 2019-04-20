#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int solve(){
    int n;
    cin >>n;

    vector<int> h(n),v(n);
    rep(i,n) cin >>h[i];
    rep(i,n) cin >>v[i];

    const int L = 1001;
    rep(i,L){
        vector<int> x(n);
        rep(j,n) x[j] = h[j]+i;

        if(x >= v) return i;
    }
    return L;
}

int main(){
    cout << solve() << "\n";
    return 0;
}

