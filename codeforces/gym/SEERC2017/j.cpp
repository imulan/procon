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

const int N = 100001;
bool vis[3][N][3];
bool dp[3][N][3];

bool dfs(int turn, int two, int one){
    if(two<0 || one<0) return false;
    one %= 3;

    // printf(" %d %d %d\n", turn,two,one);
    if(vis[turn][two][one]) return dp[turn][two][one];

    if(two == 0 && one == 0){
        return turn != 0;
    }

    bool res;
    if(turn == 0){
        res = false;
        if(two>0){
            res |= dfs((turn+1)%3, two-1, one);
            res |= dfs((turn+1)%3, two-1, one+1);
        }
        if(one>0){
            res |= dfs((turn+1)%3, two, one-1);
        }
    }
    else{
        res = true;
        if(two>0){
            res &= dfs((turn+1)%3, two-1, one);
            res &= dfs((turn+1)%3, two-1, one+1);
        }
        if(one>0){
            res &= dfs((turn+1)%3, two, one-1);
        }
    }

    vis[turn][two][one] = true;
    return dp[turn][two][one] = res;
}

bool solve(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int o=0, t=0, l=0;
    rep(i,n){
        if(a[i]==1) ++o;
        else if(a[i]==2) ++t;
        else ++l;
    }

    if(l>=2) return false;

    if(l==1) return dfs(1,t,o) || dfs(1,t+l,o) || dfs(1,t,l+o);
    else return dfs(1,t-1,o) || dfs(1,t,o-1) || dfs(1,t-1,o+1);
}

int main(){
    cout << (solve()?"Win":"Lose") << endl;
    return 0;
}
