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

const int N = 334;
int dp[N][3];

const int INF = 10101010;

int main(){
    int n;
    cin >>n;
    vector<string> w(n);
    rep(i,n) cin >>w[i];

    vector<int> x(n);

    int L = 0;
    map<string,int> w2id;
    vector<int> l;

    rep(i,n){
        if(!w2id.count(w[i])){
            w2id[w[i]] = L++;
            l.pb(w[i].size());
        }

        x[i] = w2id[w[i]];
    }

    int ans = n-1;
    rep(i,n) ans += w[i].size();

    for(int a=1; a<=n/2; ++a){
        int M = 0;
        map<vector<int>,int> m;
        vector<int> ID(n,-1);
        for(int i=0; i+a-1<n; ++i){
            vector<int> tmp;
            rep(j,a) tmp.pb(x[i+j]);

            if(!m.count(tmp)) m[tmp] = M++;
            ID[i] = m[tmp];
        }

        rep(mid,M){
            rep(i,N)rep(j,3) dp[i][j]=INF;
            dp[0][0] = 0;
            rep(i,n)rep(j,3){
                // printf(" (%d %d)\n",i,j);
                if(ID[i]==mid){
                    int ni = min(i+a,n), nj = min(j+1,2);
                    dp[ni][nj] = min(dp[ni][nj], dp[i][j]+a+1);
                }
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+l[x[i]]+1);
            }

            ans = min(ans, dp[n][2]-1);
        }
    }

    cout << ans << endl;
    return 0;
}
