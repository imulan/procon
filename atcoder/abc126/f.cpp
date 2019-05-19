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

bool check(vector<int> &v, int k){
    int V = v.size();
    const int M = V/2;

    vector<int> pos[M];
    rep(i,V) pos[v[i]].pb(i);
    rep(i,M){
        int val = 0;
        for(int j=pos[i][0]; j<=pos[i][1]; ++j) val ^= v[j];
        if(val != k) return false;
    }
    return true;
}

int main(){
    int m,k;
    cin >>m >>k;

    vector<int> v;
    if(m<=1){
        if(k==0) rep(i,1<<m)rep(j,2) v.pb(i);
    }
    else{
        int M = 1<<m;
        if(0<=k && k<M){
            v.pb(k);
            rep(i,M)if(i!=k) v.pb(i);
            v.pb(k);
            for(int i=M-1; i>=0; --i)if(i!=k) v.pb(i);
        }
    }

    // if(!v.empty()) assert(check(v,k));
    int V = v.size();
    if(V==0) cout << -1 << "\n";
    else rep(i,V) cout << v[i] << " \n"[i==V-1];
    return 0;
}
