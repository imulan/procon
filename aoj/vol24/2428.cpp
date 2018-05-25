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

string s;
int n;
vector<int> dot;
int D;

ll ans = -1;
const ll LIM = 1<<10;

bool err;

ll E(int l, int r);

ll N(int l, int r){
    if(l>r){
        err = true;
        return 0;
    }

    ll ret = 0;
    for(int i=l; i<=r; ++i){
        if(ret>=LIM || (s[i]!='0' && s[i]!='1')){
            err = true;
            return 0;
        }
        ret = ret*2 + s[i]-'0';
    }
    return ret;
}

// <expression> <operation> <expression>
ll O(int l, int r){
    char op = '?';
    int pos = -1;

    int b = 0;
    for(int i=r; i>=l; --i){
        b += (s[i]=='(');
        b -= (s[i]==')');

        if(b==0){
            if(s[i]=='+' || s[i]=='-'){
                op = s[i];
                pos = i;
                break;
            }
        }
    }

    if(pos == -1){
        b = 0;
        for(int i=r; i>=l; --i){
            b += (s[i]=='(');
            b -= (s[i]==')');

            if(b==0){
                if(s[i]=='*'){
                    op = s[i];
                    pos = i;
                    break;
                }
            }
        }
    }

    if(op == '?'){
        err = true;
        return 0;
    }

    ll x = E(l,pos-1), y = E(pos+1,r);
    ll ret;
    if(op == '+') ret = x+y;
    else if(op == '-') ret = x-y;
    else if(op == '*') ret = x*y;

    if(ret<0 || ret>=LIM) err = true;
    return ret;

}

ll E(int l, int r){
    // printf(" E %d %d\n", l, r);
    if(l>r){
        err = true;
        return 0;
    }

    if(s[l]=='('){
        int b = 0;
        for(int i=l; i<=r; ++i){
            b += (s[i]=='(');
            b -= (s[i]==')');

            if(b==0){
                if(s[i]=='+' || s[i]=='-' || s[i]=='*') return O(l,r);
            }
        }

        if(s[r]!=')'){
            err = true;
            return 0;
        }
        return O(l+1, r-1);
    }

    bool found = false;
    for(int i=l; i<=r; ++i){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*') found = true;
    }

    ll ret;
    if(found) ret = O(l,r);
    else ret = N(l,r);
    if(ret<0 || ret>=LIM) err = true;
    return ret;
}

const string cand = "01+-*()";
void dfs(int dep){
    if(dep == D){
        err = false;
        ll res = E(0,n-1);
        if(!err) ans = max(ans, res);
        return;
    }

    int idx = dot[dep];
    rep(i,cand.size()){
        s[idx] = cand[i];
        dfs(dep+1);
        s[idx] = '.';
    }
}

int main(){
    cin >>s;
    n = s.size();

    rep(i,n)if(s[i] == '.') dot.pb(i);
    D = dot.size();

    dfs(0);
    cout << ans << endl;
    return 0;
}
