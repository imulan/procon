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

vi in(){
    int w;
    cin >>w;

    vi p(3);
    iota(all(p),0);

    rep(i,w){
        int a;
        cin >>a;
        swap(p[a],p[a+1]);
    }

    return p;
}

bool solve(){
    vi p(3);
    iota(all(p),0);

    vector<vi> v;
    map<vi,int> m;
    do{
        m[p] = v.size();
        v.pb(p);
    }while(next_permutation(all(p)));

    int n;
    cin >>n;

    int ct[6]={};
    int loop[6]={1,2,2,3,3,2};
    rep(i,n){
        vi amida = in();
        ++ct[m[amida]];
    }

    rep(i,6){
        if(ct[i]>=loop[i]) return true;
    }

    vi x;
    rep(i,6)rep(j,ct[i]) x.pb(i);
    int X = x.size();

    vi E(3);
    iota(all(E),0);

    do{
        vi t(3);
        iota(all(t),0);

        rep(i,X){
            vi nt(3);
            vi f = v[x[i]];
            rep(j,3) nt[j] = t[f[j]];
            t = nt;
            if(t==E) return true;
        }
    }while(next_permutation(all(x)));

    return false;
}

int main(){
    cout << (solve()?"yes":"no") << endl;
    return 0;
}
