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

using vi = vector<int>;
using P = pair<bool,vi>;

vi factorize(int x){
    x = abs(x);
    vi ret;

    int t = x;
    for(int i=2; i*i<=x; ++i){
        int ct = 0;
        while(t%i==0){
            ++ct;
            t/=i;
        }
        if(ct%2==1) ret.pb(i);
    }
    if(t>1) ret.pb(t);
    return ret;
}

int main(){
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<P> f(n);
    rep(i,n) f[i] = {(a[i]<0) ,factorize(a[i])};

    map<P,int> p2id;
    int pp = 0;
    vector<int> b(n);
    rep(i,n){
        if(!p2id.count(f[i])) p2id[f[i]] = pp++;
        b[i] = p2id[f[i]];
    }

    vector<int> ans(n+1);
    rep(i,n){
        vector<bool> ap(n);
        int sz = 0;
        for(int j=i; j<n; ++j){
            if(a[j]!=0 && !ap[b[j]]){
                ap[b[j]] = true;
                ++sz;
            }
            ++ans[max(1,sz)];
        }
    }

    for(int i=1; i<=n; ++i) printf("%d%c", ans[i], " \n"[i==n]);
    return 0;
}
