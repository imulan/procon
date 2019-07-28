#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main(){
    string s;
    int k;
    cin >>s >>k;

    int n = s.size();

    vector<string> v;
    rep(i,n){
        for(int j=1; j<=5; ++j){
            if(i+j>n) break;
            v.pb(s.substr(i,j));
        }
    }

    sort(all(v));
    v.erase(unique(all(v)), v.end());
    cout << v[k-1] << endl;
    return 0;
}
