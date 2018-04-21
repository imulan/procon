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

int n,L;
string s;

vector<int> merge(const vector<int> &f, const vector<int> &g){
    vector<int> h(n*n);
    rep(i,n*n) h[i] = g[f[i]];
    return h;
}

vector<int> pow(const vector<int> &f, int p){
    vector<int> g(f);

    vector<int> ret(n*n);
    iota(all(ret),0);

    while(p){
        if(p&1) ret = merge(ret, g);
        g = merge(g,g);
        p >>= 1;
    }
    return ret;
}

int number(int &idx){
    int ret = 0;
    while(idx<L && isdigit(s[idx])){
        ret = ret*10 + (s[idx]-'0');
        ++idx;
    }
    return ret;
}

vector<int> sequence(int &idx);
vector<int> repetition(int &idx);
vector<int> operation(int &idx);

vector<int> sequence(int &idx){
    vector<int> f(n*n);
    iota(all(f), 0);

    if(idx < L && s[idx] != ')'){
        if(s[idx] == '(') f = merge(f, repetition(idx));
        else f = merge(f, operation(idx));
    }

    return f;
}

vector<int> repetition(int &idx){
    ++idx;
    vector<int> f = sequence(idx);

    assert(s[idx]==')');
    ++idx;

    int num = number(idx);
    return merge(pow(f, num), sequence(idx));
}

vector<int> operation(int &idx){
    char op = s[idx];
    ++idx;
    int num = number(idx);
    --num;

    vector<int> f(n*n);
    iota(all(f), 0);

    if(op == 'R'){
        int v = f[num*n];
        for(int i=1; i<n; ++i) f[num*n + i-1] = f[num*n + i];
        f[num*n + n-1] = v;
    }
    else if(op == 'L'){
        int v = f[num*n + n-1];
        for(int i=n-1; i>0; --i) f[num*n + i] = f[num*n + i-1];
        f[num*n] = v;
    }
    else if(op == 'D'){
        int v = f[num];
        rep(i,n-1) f[i*n + num] = f[(i+1)*n + num];
        f[(n-1)*n + num] = v;
    }
    else if(op == 'U'){
        int v = f[(n-1)*n + num];
        for(int i=n-1; i>0; --i) f[i*n + num] = f[(i-1)*n + num];
        f[num] = v;
    }
    else assert(false);

    return merge(f, sequence(idx));
}

int main(){
    cin >>n >>L >>s;

    int idx = 0;
    vector<int> f = sequence(idx);

    vector<vector<int>> a(n, vector<int>(n));
    rep(i,n*n){
        int pos = f[i];
        a[pos/n][pos%n] = i+1;
    }

    rep(i,n){
        rep(j,n) printf("%d%c", a[i][j], " \n"[j==n-1]);
    }

    return 0;
}
