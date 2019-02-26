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

const int N = 61;
ll C[N][N];

int main(){
    C[0][0] = 1;
    for(int i=1; i<N; ++i){
        C[i][0] = C[i][i] = 1;
        for(int j=1; j<i; ++j){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            // printf(" %d %d :: %lld\n",i,j,C[i][j]);
        }
    }

    ll n,m;
    while(cin >>n >>m,n){
        --m;
        int b = 0;
        ll now = 0;
        while(b<n){
            if(now + C[n][b] > m) break;

            now += C[n][b];
            ++b;
        }

        m -= now;

        int rem = n;
        string ans(n,' ');
        rep(i,n-1){
            // check set this bit to 1?
            bool ok = false;
            if(b>0 && m - C[rem-1][b] >= 0) ok = true;

            if(ok){
                ans[i] = '1';
                m -= C[rem-1][b];
                --b;
            }
            else{
                ans[i] = '0';
            }
            --rem;
        }
        assert(b<=1);
        ans[n-1] = '0'+b;
        cout << ans << "\n";
    }
    return 0;
}
