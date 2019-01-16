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

int main(){
    int n,m;
    cin >>n >>m;

    vector<vector<int>> d(n, vector<int>(n,-19191919));
    rep(i,m){
        int a,b,c;
        cin >>a >>b >>c;
        d[a][b] = c;
    }

    rep(k,n)rep(i,n)rep(j,n) d[i][j] = max(d[i][j], d[i][k]+d[k][j]);
    cout << d[0][n-1] << endl;
    return 0;
}
