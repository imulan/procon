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

using ps = pair<string,string>;
using pi = pair<int,int>;

const pi I(-1,-1);

int main(){
    int n;
    string t;
    cin >>n >>t;

    vector<string> s(n);
    rep(i,n) cin >>s[i];

    sort(all(s), [](const string &l, const string &r){ return l.size() > r.size(); });

    map<pi,pi> par;

    vector<pi> v({I});
    rep(i,n){
        vector<pi> nv;
        for(pi p:v){
            int x = p.fi, y = p.se;


        }


        if(nv.empty()){
            cout << "impossible" << "\n";
            return 0;
        }
    }

    vector<int> a,b;



    cout << a.size() << " " << b.size() << "\n";
    for(int i:a) cout << s[i] << "\n";
    for(int i:b) cout << s[i] << "\n";
    return 0;
}
