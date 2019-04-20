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

    map<int,int> ct;
    while(n--){
        int a;
        cin >>a;
        ++ct[a];
    }

    ll x = 0;
    for(const auto &p:ct){
        x += p.se/2;
    }
    cout << x/2 << endl;
    return 0;
}