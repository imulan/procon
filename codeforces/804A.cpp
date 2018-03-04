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

const int N = 100;
int c[N][N];

void test(int n){
    for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j) c[i][j] = (i+j)%(n+1);

    rep(i,n){
        rep(j,n) printf(" %2d", c[i+1][j+1]);
        printf("\n");
    }
}

int main(){
    int n;
    cin >>n;

    // test(n);
    cout << (n+1)/2-1 << endl;
    return 0;
}
