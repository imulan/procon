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

int cv(char c){
    if(isdigit(c)) return c-'0';
    if(isupper(c)) return 10+c-'A';
    return 36+c-'a';
}

int READ(){
    int p;
    string m;
    cin >>p >>m;

    int ret = 0;
    for(char c:m) ret = ret*p + cv(c);
    return ret;
}

int main(){
    int n;
    cin >>n;

    int g = 0;
    rep(i,n) g ^= __builtin_popcount(READ());
    cout << (g==0?"lose":"win") << endl;
    return 0;
}
