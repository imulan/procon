#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main(){
    int n;
    cin >>n;

    int odd=0, four=0, two=0;
    rep(i,n){
        int a;
        cin >>a;

        if(a%4==0) ++four;
        else if(a%2==0) ++two;
        else ++odd;
    }
    // printf(" %d %d %d\n",odd,two,four);

    string ans = "No";
    if(two<=1){
        if(odd+two<=four+1) ans="Yes";
    }
    else{
        if(odd<=four) ans="Yes";
    }
    cout << ans << endl;
    return 0;
}
