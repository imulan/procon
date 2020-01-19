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

using P = pair<int,char>;
using ps = pair<string,string>;

const string v = "aeiou";
bool isV(char x){
    for(char c:v)if(c==x) return true;
    return false;
}

P f(const string &s){
    int ct = 0;
    char last = '?';
    for(char c:s){
        if(isV(c)){
            ++ct;
            last = c;
        }
    }
    return {ct,last};
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >>n;

    map<P,vector<string>> m;
    rep(i,n){
        string s;
        cin >>s;

        P p = f(s);
        m[p].pb(s);
    }

    queue<ps> S;
    map<int,vector<string>> rem;
    for(const auto &p:m){
        int sz = p.se.size();
        for(int i=0; i+1<sz; i+=2) S.push({p.se[i], p.se[i+1]});
        if(sz%2 == 1) rem[p.fi.fi].pb(p.se.back());
    }

    queue<ps> F;
    for(const auto &p:rem){
        int sz = p.se.size();
        for(int i=0; i+1<sz; i+=2) F.push({p.se[i], p.se[i+1]});
    }

    int fs = F.size(), ss = S.size();
    int ans = 0;

    if(fs > ss) ans = ss;
    else ans = (fs+ss)/2;
    cout << ans << "\n";
    rep(i,ans){
        ps b = S.front();
        S.pop();

        ps a;
        if(!F.empty()){
            a = F.front();
            F.pop();
        }
        else{
            a = S.front();
            S.pop();
        }

        cout << a.fi << " " << b.fi << "\n";
        cout << a.se << " " << b.se << "\n";
    }
    return 0;
}
