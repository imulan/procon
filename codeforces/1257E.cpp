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

int main(){
    int n = 0;
    int k[3];
    rep(i,3){
        cin >>k[i];
        n += k[i];
    }

    vector<vector<int>> ct(3, vector<int>(n+1));
    rep(i,3){
        rep(j,k[i]){
            int a;
            cin >>a;
            ct[i][a-1] = 1;
        }
    }

    int ans = n;
    int x=0, y=k[2];
    int f = 0, nf = 0;

    rep(r,n+1){
        int C = x - 2*y + k[2] + n - r;
        ans = min(ans, f+C);

        nf = nf + ct[1][r] - ct[0][r];
        f = min(f,nf);

        x += ct[0][r];
        y -= ct[2][r];
    }

    cout << ans << "\n";
    return 0;
}
