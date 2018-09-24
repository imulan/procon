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

const int N = 10000010;

bool p[N];

int main(){
    fill(p,p+N,true);
    p[0] = p[1] = false;
    for(int i=2; i<N; ++i){
        if(p[i]) for(int j=2*i; j<N; j+=i) p[j] = false;
    }

    int n;
    cin >>n;

    int ans = 0;
    for(int q=3; q<=n; ++q){
        if(p[q] && p[q+2]) ans += 2;
    }
    cout << ans << endl;
    return 0;
}
