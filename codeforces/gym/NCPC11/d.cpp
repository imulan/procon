#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF = 19191919;

int main(){
    int f,s,g,u,d;
    cin >>f >>s >>g >>u >>d;
    --s;
    --g;

    vector<int> dp(f,INF);
    dp[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int a:{u,-d}){
            int nx = v+a;
//            printf(" nx %d\n",nx);
            if(0<=nx && nx<f){
                if(dp[nx] > dp[v]+1){
                    dp[nx] = dp[v]+1;
                    que.push(nx);
                }
            }
        }
    }

    int ans = dp[g];
    if(ans == INF) cout << "use the stairs" << endl;
    else cout << ans << endl;
    return 0;
}


