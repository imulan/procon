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

using P = pair<int,string>;

int main(){
    int n;
    cin >>n;
    
    map<string,int> p;
    rep(i,n){
        int no,m,s;
        cin >>no >>m >>s;
        while(m--){
            string t;
            cin >>t;
            p[t] += s;
        }
    }

    vector<P> v;
    for(const auto &x:p) v.pb({-x.se,x.fi});
    sort(all(v));

    int V=v.size();
    rep(i,min(10,V)) cout << v[i].se << " " << -v[i].fi << endl;
    return 0;
}
