#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using P = pair<ll,string>;

int main(){
    int n,d,k;
    cin >>n >>d >>k;

    vector<P> v(n);
    rep(i,n){
        string s;
        int c;
        cin >>s >>c;
        v[i] = {c,s};
    }

    sort(all(v));
    reverse(all(v));

    ll sum = 0;
    rep(i,k) sum += v[i].fi;

    if(sum>=d){
        cout << k << endl;
        rep(i,k){
            cout << v[i].se << ", YOU ARE FIRED!" << endl;
        }
    }
    else{
        cout << "impossible" << endl;
    }
    return 0;
}