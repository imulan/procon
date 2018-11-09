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

    map<string,set<int>> den;
    rep(i,n){
        string c;
        int d;
        cin >>c >>d;
        den[c].insert(d);
    }

    int m;
    cin >>m;
    vector<string> o(m);
    rep(i,m) cin >>o[i];

    bool ok = true;
    int x = 0;
    rep(i,m){
        if(!den.count(o[i])){
            ok = false;
            break;
        }

        auto itr = den[o[i]].upper_bound(x);
        if(itr == den[o[i]].end()){
            ok = false;
            break;
        }

        x = *itr;
    }

    cout << (ok?"Yes":"No") << endl;
    return 0;
}
