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
    int n,k;
    string s;
    cin >>n >>k >>s;

    int x = n-1;
    while(x>0){
        string f = s.substr(0,x);
        string t = s.substr(n-x);
        if(f==t) break;
        --x;
    }

    string ans = s;
    string add = s.substr(x);
    rep(i,k-1) ans += add;
    cout << ans << endl;
    return 0;
}
