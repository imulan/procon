#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)n;++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int solve(){
    int m,n;
    cin >>m >>n;

    int ct[10]={};
    rep(i,m){
        int v;
        cin >>v;
        ++ct[v];
    }
    rep(i,n){
        int v;
        cin >>v;
        ++ct[v];
    }

    int p=0,q=0;
    rep(i,10){
        if(ct[i]==2) ++p;
        if(ct[i]>0) ++q;
    }

    return (2*p > q);
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
