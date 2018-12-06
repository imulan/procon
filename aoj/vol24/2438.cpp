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
    // READ
    string pat;
    getline(cin,pat);

    vector<string> y;
    string tttt;
    while(getline(cin,tttt)){
        y.pb(tttt);
    }
    int n = y.size();

    // SOLVE
    map<string,string> m;
    vector<string> property(n);
    vector<int> indent(n);
    rep(i,n){
        int ct = 0;
        while(y[i][ct]==' ') ++ct;
        indent[i] = ct;

        string t = y[i].substr(ct);
        int cl = 0;
        while(t[cl]!=':') ++cl;

        string p = t.substr(0,cl);
        string parent = "";
        if(ct>0){
            int par = i;
            while(par>=0 && indent[i]<=indent[par]) --par;
            assert(par>=0);
            parent = property[par];
        }
        property[i] = parent+"."+p;

        // object
        if(cl != t.size()-1){
            string name = t.substr(cl+2);
            m[property[i]] = ("string \"" + name + "\"");
        }
        else m[property[i]] = "object";
    }

    string ans = "no such property";
    if(m.count(pat)) ans = m[pat];
    cout << ans << endl;
    return 0;
}
