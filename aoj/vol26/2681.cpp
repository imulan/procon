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

using pi = pair<int,int>;

pi calc(const string &s){
    int mn = 0;
    int c = 0;
    rep(i,s.size()){
        if(s[i]=='(') ++c;
        else --c;
        mn = min(mn, c);
    }

    return {c,mn};
}

string rev(const string &s){
    string t = s;
    int n = s.size();
    rep(i,n) t[n-1-i] = (s[i]=='('?')':'(');
    return t;
}

int dep(const vector<pi> &v){
    multiset<pi> ms;

    int n = v.size();
    rep(i,n) ms.insert({-v[i].fi, v[i].se});

    int ret = 0;
    while(!ms.empty()){
        auto itr = ms.begin();
        while(itr != ms.end()){
            if(ret + itr->se >= 0) break;
            ++itr;
        }

        if(itr == ms.end()) return -1;

        ret += -itr->fi;
        ms.erase(itr);
    }

    return ret;
}

bool solve(){
    int n;
    cin >>n;

    vector<pi> l,r;
    rep(i,n){
        string s;
        cin >>s;

        pi v = calc(s);
        if(v.fi>=0) l.pb(v);
        else r.pb(calc(rev(s)));
    }

    int ld = dep(l), rd = dep(r);
    return (ld!=-1 && rd!=-1 && ld==rd);
}

int main(){
    cout << (solve()?"Yes":"No") << endl;
    return 0;
}
