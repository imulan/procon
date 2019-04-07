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
    string s;
    cin >>s;

    int n = s.size();

    int fidx = n-1;
    string a = s, b = s;
    for(int i=n-1; i>=0; --i){
        if(s[i]=='4'){
            a[i] = '3';
            b[i] = '1';
            fidx = i;
        }
        else b[i] = '0';
    }

    b = b.substr(fidx);
    cout << a << " " << b << "\n";
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(i,T){
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
