#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl;

const string NG = "Impossible";

string solve(){
    string s;
    cin >>s;

    int n = s.size();
    if(n%2==1) return NG;

    int l=0,r=0;
    rep(i,n){
        if(s[i]=='(') ++l;
        if(s[i]==')') ++r;
    }

    if(l>n/2 || r>n/2) return NG;

    rep(i,n){
        if(s[i]=='?'){
            if(l<n/2){
                s[i]='(';
                ++l;
            }
            else{
                s[i]=')';
                ++r;
            }
        }
    }

    int d = 0;
    rep(i,n){
        if(s[i]=='(') ++d;
        else --d;
        if(d<0) return NG;
    }
    return s;
}

int main(){
    cout << solve() << endl;
    return 0;
}