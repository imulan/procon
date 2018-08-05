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

const int mod = 1e9+7;

int n;
string s;
int S;

const int N = 202;
int ny[N][2];
int dp[N][N][N][2];
// x文字目、開き括弧にb個余裕がある、sの先頭y文字と一致している、出現したフラグf
int dfs(int x, int b, int y, int f){
    if(x==2*n){
        if(b==0 && f==1) return 1;
        return 0;
    }
    if(dp[x][b][y][f]>=0) return dp[x][b][y][f];

    // insert (
    int ret = dfs(x+1, b+1, ny[y][0], f|(ny[y][0]==S));
    // insert )
    if(b>0) (ret += dfs(x+1, b-1, ny[y][1], f|(ny[y][1]==S))) %= mod;

    return dp[x][b][y][f] = ret;
}

int main(){
    cin >>n >>s;
    S = s.size();

    // calc ny
    rep(i,S){
        string b = s.substr(0,i);
        if(s[i]=='('){
            ny[i][0] = i+1;

            b += ')';
            int j=i;
            while(j>0){
                if(s.substr(0,j) == b.substr(i+1-j,j)) break;
                --j;
            }
            ny[i][1] = j;
        }
        else{
            ny[i][1] = i+1;

            b += '(';
            int j=i;
            while(j>0){
                if(s.substr(0,j) == b.substr(i+1-j,j)) break;
                --j;
            }
            ny[i][0] = j;
        }
    }

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0,0,0) << endl;
    return 0;
}
