#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    auto check = [&](int num){
        int rem = num;
        int ct = 0;

        rep(i,n){
            if(a[i]<=ct){
                ++ct;
            }
            else{
                if(rem>0){
                    --rem;
                    ++ct;
                }
            }
        }
        return ct >= m;
    };

    int ng=-1,ok=m;
    while(ok-ng>1){
        int mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    printf("%d\n", ok);
    return 0;
}