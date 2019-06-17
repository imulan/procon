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

bool isop(char c){
    return (c=='|' || c=='&' || c=='^');
}

string e;
int n;
int x;

int E(int l, int r){
    if(l==r){
        if(e[l] == 'x') return x;
        if(e[l] == 'X') return !x;
        return e[l]-'0';
    }

    assert(e[l]=='(' && e[r]==')');

    bool found = false;
    int o = l+1;
    int b = 0;
    while(o<r){
        if(isop(e[o]) && b==0){
            found = true;
            break;
        }
        if(e[o]=='(') ++b;
        if(e[o]==')') --b;
        ++o;
    }
    assert(found);

    char op = e[o];
    int lv = E(l+1,o-1), rv = E(o+1,r-1);
    if(op == '|') return lv|rv;
    if(op == '&') return lv&rv;
    if(op == '^') return lv^rv;
    assert(false);
}

bool check(){
    set<int> s;
    rep(i,2){
        x = i;
        s.insert(E(0,n-1));
    }
    return s.size()==1;
}

int solve(){
    cin >>e;
    n = e.size();
    if(check()) return 0;
    return 1;
}

int main(){
    int T;
    cin >>T;
    rep(i,T) printf("Case #%d: %d\n",i+1, solve());
    return 0;
}
