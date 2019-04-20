#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N = 10100;
bool prime[N];
vector<int> p;

//when i comes
int nx[N];

vector<int> dp[N];
bool vis[N];

const int INF = 191919;

vector<int> dfs(int x){
    if(vis[x]) return dp[x];
    vis[x] = true;

    vector<int> ret({x,x,x});
    if(prime[x]){
        ret = {1,INF,x};
    }
    else {
        if (x + 1 < N) {
            vector<int> res = dfs(x + 1);
            if ( min(x+1,res[2]) <= ret[0]){
                rep(i,3) ret[i] = res[(i+2)%3];
                ret[0] = min(x+1,res[2]);
            }
        }

        for(int pp:p) {
            if(pp>x) break;
            if (x % pp == 0) {
//                printf(" %d:: %d\n",x,pp);
                vector<int> res = dfs(x/pp);
                if ( min(x/pp,res[2]) <= ret[0]){
                    rep(i,3) ret[i] = res[(i+2)%3];
                    ret[0] = min(x/pp,res[2]);
                }
            }
        }
    }

//    printf(" x %d : ",x);
//    rep(i,3) printf(" %d", ret[i]);
//    printf("\n");
    return dp[x] = ret;
}

int main(){
    fill(prime,prime+N,true);
    prime[0] = prime[1] = false;
    for(int i=2; i<N; ++i){
        if(prime[i]){
            p.pb(i);
            for(int j=2*i; j<N; j+=i) prime[j] = false;
        }
    }

    int n;
    cin >>n;

    int ans[3]={};
    rep(i,n){
        char c;
        int X;
        scanf(" %c %d", &c, &X);

        vector<int> v = dfs(X);

        int a = 0;
        if(c=='I') a=1;
        if(c=='E') a=2;

        rep(j,3){
//            printf(" %d", v[j]);
            int add = v[(j+a)%3];
            add = min(add, X);
            ans[j] += add;
        }
//        printf("\n");
    }

    rep(i,3) printf("%d%c", ans[i], " \n"[i==2]);
    return 0;
}


