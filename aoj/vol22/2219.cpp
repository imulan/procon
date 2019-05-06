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
    int n;
    while(cin >>n){
        int m;
        cin >>m;

        vector<int> c(n);
        vector<vector<int>> p(n);
        rep(i,n){
            cin.ignore();
            string s;
            getline(cin, s);

            cin >>c[i];
            vector<int> tt(3);
            rep(j,3) cin >>tt[j];
            p[i] = tt;
        }

        int ans = 0;
        rep(x,3){
            vector<int> dp(m+1);
            rep(i,n)rep(j,m+1){
                int nj = j+c[i];
                if(nj>m) continue;
                dp[nj] = max(dp[nj], dp[j]+p[i][x]);
            }
            ans = max(ans, *max_element(all(dp)));
        }
        cout << ans << endl;
    }
    return 0;
}
