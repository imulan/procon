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

bool solve(){
    int n,m,x,k;
    string s;
    cin >>n >>m >>x >>k >>s;

    int E=0, O=0;
    rep(i,k){
        if(s[i]=='E') ++E;
        else ++O;
    }

    ll ct=0;
    for(int i=1; i<=m; ++i){
        if(i%2==1){
            int a = min(x,O);
            ct += a;
            O -= a;
        }
        else{
            int a = min(x,E);
            ct += a;
            E -= a;
        }
    }

    return ct>=n;
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << (solve()?"yes":"no") << endl;
    return 0;
}
