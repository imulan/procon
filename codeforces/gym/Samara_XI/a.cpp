#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main(){
    ll s,g;
    cin >>s >>g;

    if(s%g != 0){
        cout << -1 << endl;
        return 0;
    }

    s/=g;

    if(s<=1){
        cout << -1 << endl;
        return 0;
    }

    ll x=g, y=g*(s-1);
    cout << x << " " << y << endl;
    return 0;
}