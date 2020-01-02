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

const int N = 1000010;
char s[N],buf[N];
int ans[N];

const int INF = 19191919;
using pi = pair<int,int>;

const int n = 1<<20;
int mx[2*n-1] = {};
int mn[2*n-1] = {};
int lazy[2*n-1] = {};


void setLazy(int k, int v){
    lazy[k] += v;
    mx[k] += v;
    mn[k] += v;
}
void push(int k, int l, int r){
    if(lazy[k]!=0){
        setLazy(2*k+1,lazy[k]);
        setLazy(2*k+2,lazy[k]);
    }
    lazy[k]=0;
}
void fix(int k, int l, int r){
    mx[k] = max(mx[2*k+1], mx[2*k+2]);
    mn[k] = min(mn[2*k+1], mn[2*k+2]);
}
pi merge(pi x, pi y){
    return {max(x.fi,y.fi), min(x.se,y.se)};
}
//内部的に投げられるクエリ
void _add(int a, int b, int x, int k, int l, int r){
    if(r<=a || b<=l) return;
    if(a<=l && r<=b){
        setLazy(k,x);
        return;
    }

    push(k,l,r);
    _add(a,b,x,2*k+1,l,(l+r)/2);
    _add(a,b,x,2*k+2,(l+r)/2,r);

    fix(k,l,r);
}
//[a,b)に+x
void add(int a, int b, int x){
    return _add(a,b,x,0,0,n);
}
//内部的に投げられるクエリ
pi _query(int a, int b, int k, int l, int r){
    if(r<=a || b<=l) return {-INF,INF};
    if(a<=l && r<=b) return {mx[k],mn[k]};

    push(k,l,r);
    pi vl=_query(a,b,2*k+1,l,(l+r)/2);
    pi vr=_query(a,b,2*k+2,(l+r)/2,r);
    return merge(vl,vr);
}
//[a,b)
pi query(int a, int b){
    return _query(a,b,0,0,n);
}

int main(){
    int S;
    scanf(" %d", &S);
    scanf(" %s", s);

    rep(i,N) buf[i] = ' ';

    int pos = 0;
    int ct = 0;
    rep(i,S){
        if(s[i]=='L') pos = max(0, pos-1);
        else if(s[i]=='R') ++pos;
        else{
            char c = s[i];
            if(buf[pos] == '('){
                add(pos,n+1,-1);
                --ct;
            }
            else if(buf[pos] == ')'){
                add(pos,n+1,1);
                ++ct;
            }
            buf[pos] = c;

            if(buf[pos] == '('){
                add(pos,n+1,1);
                ++ct;
            }
            else if(buf[pos] == ')'){
                add(pos,n+1,-1);
                --ct;
            }
        }

        pi p = query(0,n+1);
        // rep(j,10) printf("%c",buf[j]);
        // dbg(p);
        if(ct != 0 || p.se != 0) ans[i] = -1;
        else ans[i] = p.fi;
    }

    rep(i,S) printf("%d%c", ans[i], " \n"[i==S-1]);
    return 0;
}
