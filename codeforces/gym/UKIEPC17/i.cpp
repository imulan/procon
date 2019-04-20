#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main(){
    int n;
    cin >>n;
    vector<int> h(n);
    rep(i,n) cin >>h[i];
    int T;
    cin >>T;

    int ans = h[0];
    int rem = T;
    rep(i,n){
        if(T%h[i] < rem){
            rem = T%h[i];
            ans = h[i];
        }
    }
    cout << ans << endl;
    return 0;
}