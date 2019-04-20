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
    string a,b;
    cin >>n >>a >>b;

    ll x=0,y=0;

    int prev = 0;
    rep(i,n){
        if( (!prev && a[i]=='1') || (prev && a[i]=='0') ) {
            x |= (1LL << (n - 1 - i));
        }
        if(a[i]=='1') prev = !prev;
    }

    prev = 0;
    rep(i,n){
        if( (!prev && b[i]=='1') || (prev && b[i]=='0') ) {
            y |= (1LL << (n - 1 - i));
        }
        if(b[i]=='1') prev = !prev;
    }

//    printf(" xy %lld %lld\n",x,y);
    cout << abs(x-y)-1 << endl;
    return 0;
}