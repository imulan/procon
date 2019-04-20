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
    cin >>n;
    vector<string> u(n),t(n);
    rep(i,n) cin >>u[i] >>t[i];

    set<string> s;
    vector<int> idx;
    rep(i,n){
        if(!s.count(u[i])){
            idx.pb(i);
            s.insert(u[i]);
        }

        if(s.size()==12) break;
    }

    for(int i:idx) cout << u[i] << " " << t[i] << endl;
    return 0;
}
