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

vector<string> split(string s){
    int n = s.size();

    vector<string> ret;
    int i = 0;
    while(i<n){
        int nx = i;
        while(nx<n && s[nx]!=' ') ++nx;
        ret.pb(s.substr(i,nx-i));
        i = nx+1;
    }
    return ret;
}

ps cv_class(const string &s){
    vector<string> v = split(s);

    string ret = "";
    int V = v.size();
    for(int i=V-2; i>0; --i){
        if(v[i] == "upper") ret += 'a';
        else if(v[i] == "lower") ret += 'c';
        else ret += 'b';
    }

    string name = v[0].substr(0,v[0].size()-1);
    while(ret.size()<60) ret += 'b';
    return {ret,name};
}


int main(){
    int n;
    cin >>n;

    cin.ignore();

    vector<ps> v(n);
    rep(i,n){
        string s;
        getline(cin,s);
        v[i] = cv_class(s);
    }

    sort(all(v));
    rep(i,n) cout << v[i].se << "\n";
    return 0;
}
