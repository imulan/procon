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

    int a=0;
    rep(i,n){
        string s;
        cin >>s;
        int sz = s.size();

        int t = 1;
        rep(j,sz-1){
            if(s[j]=='C' && s[j+1]=='D') t = 0;
        }
        a += t;
    }
    cout << a << endl;

    return 0;
}


