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

const ll INF = LLONG_MAX/3;

bool valid;

inline bool isoperator(char c){
    return c=='*' || c=='+' || c=='-' || c=='&' || c=='^' || c=='|';
}

inline int priority(char c){
    if(c=='*') return 1;
    if(c=='&') return 3;
    if(c=='^') return 4;
    if(c=='|') return 5;
    return 2;
}

ll E(string e);

ll T(string e){
    int n = e.size();

    if(n==0){
        valid = false;
        return 0;
    }

    ll ret = 0;
    if(e[0]=='('){
        if(e[n-1]!=')') valid = false;
        ret = E(e.substr(1,n-2));
    }
    else{
        rep(i,n){
            if(!isdigit(e[i])) valid = false;
            ret = 10*ret + (e[i]-'0');
        }

        if(e[0]=='0') valid = false;
    }
    return ret;
}

ll E(string e){
    int par = 0;
    int n = e.size();

    int h = 0;
    vector<ll> val;
    vector<char> op;
    rep(i,n){
        if(e[i]=='(') ++par;
        if(e[i]==')') --par;

        if(par==0 && isoperator(e[i])){
            val.pb(T(e.substr(h,i-h)));
            op.pb(e[i]);
            h = i+1;
        }
    }
    val.pb(T(e.substr(h,n-h)));

    // dbg(e);
    // dbg(val);
    // dbg(op);

    while(op.size()>0){
        int sz = op.size();
        int idx = sz-1;
        for(int i=sz-1; i>=0; --i){
            if(priority(op[i]) <= priority(op[idx])) idx = i;
        }

        ll l = val[idx], r = val[idx+1];
        char O = op[idx];
        if(O=='*') val[idx] = l*r;
        else if(O=='+') val[idx] = l+r;
        else if(O=='-') val[idx] = l-r;
        else if(O=='&') val[idx] = l&r;
        else if(O=='^') val[idx] = l^r;
        else if(O=='|') val[idx] = l|r;
        else valid = false;

        val.erase(val.begin()+idx+1);
        op.erase(op.begin()+idx);
    }

    return val[0];
}

ll Parse(string e){
    valid = true;
    return E(e);
}

string a = "*+-&^|0123456789";
int lim;
ll dfs(int t, string e){
    // cout << " t = " <<t<<" , e = "<<e<<endl;

    if(t==lim){
        return Parse(e);
    }

    ll ret = -INF;
    if(t==1) ret = INF;

    int n = e.size();

    // insert
    rep(i,n+1){
        string x = e.substr(0,i);
        string y = e.substr(i);
        // dbg(x);dbg(y);
        rep(j,a.size()){
            string nx = x + string(1,a[j]) + y;
            // dbg(nx);
            Parse(nx);
            if(valid){
                if(t==0) ret = max(ret, dfs(t+1, nx));
                else if(t==1) ret = min(ret, dfs(t+1, nx));
            }
        }
    }

    // delete
    rep(i,n){
        string x = e.substr(0,i);
        string y = e.substr(i+1);
        string nx = x+y;
        // dbg(nx);
        Parse(nx);
        if(valid){
            if(t==0) ret = max(ret, dfs(t+1, nx));
            else if(t==1) ret = min(ret, dfs(t+1, nx));
        }
    }

    return ret;
}

int main(){
    int n;
    string e;
    while(cin >>n >>e,n){
        lim = (n+1)%2 +1;
        cout << dfs(0, e) << endl;
    }
    return 0;
}
