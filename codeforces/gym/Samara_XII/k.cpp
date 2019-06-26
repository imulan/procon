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

using vl = vector<ll>;

const int N = 1010;
bool dp[N][3][3];

bool solve(){
    string s;
    cin >>s;
    int n = s.size();

    string col = "BGR";
    do{
        auto f = [&](char c){
            rep(i,3)if(col[i]==c) return i;
        };

        rep(i,N)rep(j,3)rep(k,3) dp[i][j][k] = false;
        dp[0][0][0] = true;
        rep(i,n){
            int x = f(s[i]);
            rep(j,3)rep(k,3)if(dp[i][j][k]){
                if(j<=x) dp[i+1][x][k] = true;
                if(k<=x) dp[i+1][j][x] = true;
            }
        }

        rep(i,3)rep(j,i)if(dp[n][i][j]) return true;
    }while(next_permutation(all(col)));

    return false;
}

int main(){
    cout << (solve()?"YES":"NO") << endl;
}
