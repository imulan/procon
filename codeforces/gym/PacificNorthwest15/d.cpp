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

vector<int> READ(){
    vector<int> v;
    rep(i,3){
        int a;
        cin >>a;
        v.pb(a);
    }
    sort(all(v));
    return v;
}

int sq(int x){
    return x*x;
}

bool solve(){
    vector<int> a = READ(), b = READ();
    if(a != b) return false;

    return sq(a[0])+sq(a[1]) == sq(a[2]);
}

int main(){
    cout << (solve()?"YES":"NO") << "\n";
    return 0;
}
