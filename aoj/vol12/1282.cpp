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

using P = pair<char,int>;

bool err;
map<char,int> sz;
map<P,int> val;

int numb(const string &s){
    int ret = 0;
    rep(i,s.size()) ret = ret*10 + (s[i]-'0');
    return ret;
}

int expr(const string &s){
    if(isdigit(s[0])) return numb(s);

    int S = s.size();
    char ar_name = s[0];
    int idx = expr(s.substr(2,S-3));

    if(sz.count(ar_name) && 0<=idx && idx<sz[ar_name] && val.count({ar_name,idx})){
        return val[{ar_name,idx}];
    }
    else{
        err = true;
        return -1;
    }
}

void assi(const string &s){
    char ar_name = s[0];
    int e_pos = s.find('=');

    int idx = expr(s.substr(2,e_pos-3));
    int t = expr(s.substr(e_pos+1));

    if(sz.count(ar_name) && 0<=idx && idx<sz[ar_name]) val[{ar_name, idx}] = t;
    else err = true;
}

void decl(const string &s){
    char ar_name = s[0];

    int S = s.size();
    int num = numb(s.substr(2,S-3));
    assert(!sz.count(ar_name));
    sz[ar_name] = num;
}

void prog(const string &s){
    if(find(all(s), '=') == s.end()) decl(s);
    else assi(s);
}

int main(){
    while(1){
        vector<string> v;
        string tt;
        while(1){
            cin >>tt;
            if(tt == ".") break;
            v.pb(tt);
        }
        int n = v.size();

        if(n == 0) break;

        sz.clear();
        val.clear();
        err = false;

        int ans = 0;
        rep(i,n){
            prog(v[i]);
            if(err){
                ans = i+1;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
