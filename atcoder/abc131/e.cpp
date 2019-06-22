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

int C2(int x){
    return x*(x-1)/2;
}

int main(){
    int n,k;
    cin >>n >>k;

    int lim = C2(n-1);
    if(lim<k){
        cout << -1 << "\n";
        return 0;
    }

    vector<pair<int,int>> e;
    if(k == 0) rep(i,n)rep(j,i) e.pb({j,i});
    else{
        int v = 3;
        while(C2(v-1)<k) ++v;

        rep(i,v-1) e.pb({i,v-1});
        for(int i=v; i<n; ++i)rep(j,i) e.pb({i,j});

        int num = C2(v-1);
        rep(i,num-k) e.pb({i,(i+1)%(v-1)});
    }

    int m = e.size();
    cout << m << "\n";
    rep(i,m) cout << e[i].fi+1 << " " << e[i].se+1 << "\n";
    return 0;
}
