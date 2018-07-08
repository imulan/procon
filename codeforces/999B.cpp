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
    string t;
    cin >>n >>t;

    vector<int> x(n);
    iota(all(x),0);
    for(int i=n; i>=1; --i)if(n%i==0){
        reverse(x.begin(), x.begin()+i);
    }

    string s(n,' ');
    rep(i,n) s[x[i]] = t[i];
    cout << s << endl;
    return 0;
}
