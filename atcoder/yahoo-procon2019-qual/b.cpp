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

bool G[4][4]={};

bool solve(){
    rep(i,3){
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        G[a][b] = G[b][a] = true;
    }

    vector<int> v(4);
    rep(i,4) v[i] = i;
    do{
        bool ok = true;
        rep(i,3){
            int s = v[i], d = v[i+1];
            if(!G[s][d]) ok = false;
        }
        if(ok) return true;
    }while(next_permutation(all(v)));
    return false;
}

int main(){
    cout << (solve()?"YES":"NO") << endl;
    return 0;
}
