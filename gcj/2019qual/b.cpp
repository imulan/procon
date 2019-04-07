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

void solve(){
    int n;
    string s;
    cin >>n >>s;

    rep(i,2*(n-1)){
        if(s[i] == 'S') s[i]='E';
        else s[i]='S';
    }

    cout << s << "\n";
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
