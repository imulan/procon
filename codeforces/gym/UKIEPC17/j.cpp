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

    double a = 0;
    rep(i,n){
        int x;
        cin >>x;

        double p = x;
        if(x == 0) p = 0.5;
        a += 1.0/p;
    }
    printf("%.10f\n", a);
    return 0;
}