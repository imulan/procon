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

const int N = 200002;
int ct[N];

int main(){
    int n;
    cin >>n;
    rep(i,n){
        int a;
        cin >>a;
        ++ct[a];
    }

    vector<int> v[2];
    rep(i,N){
        if(ct[i]>=3){
            cout << "NO" << "\n";
            return 0;
        }

        rep(j,ct[i]) v[j].pb(i);
    }

    cout << "YES" << "\n";
    rep(i,2){
        sort(all(v[i]));
        if(i) reverse(all(v[i]));

        int sz = v[i].size();
        cout << sz << "\n";
        rep(j,sz) cout << v[i][j] << " \n"[j==sz-1];
    }
    return 0;
}
