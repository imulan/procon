#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N = 100000;
const int INF = 19191919;

vector<int> G[N],rG[N];

int ds[N],di[N],dc[N];
bool iron[N], coal[N];

int main(){
    int n,I,C;
    scanf(" %d %d %d", &n, &I, &C);

    rep(i,I){
        int x;
        scanf(" %d", &x);
        --x;
        iron[x] = true;
    }
    rep(i,C){
        int x;
        scanf(" %d", &x);
        --x;
        coal[x] = true;
    }

    rep(i,n){
        int a;
        scanf(" %d", &a);
        while(a--){
            int v;
            scanf(" %d", &v);
            --v;
            G[i].pb(v);
            rG[v].pb(i);
        }
    }

    fill(ds,ds+N,INF);
    ds[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int e:G[v]){
            if(ds[e] > ds[v]+1){
                ds[e] = ds[v]+1;
                que.push(e);
            }
        }
    }

    fill(di,di+N,INF);
    rep(i,n){
        if(iron[i]){
            di[i] = 0;
            que.push(i);
        }
    }
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int e:rG[v]){
            if(di[e] > di[v]+1){
                di[e] = di[v]+1;
                que.push(e);
            }
        }
    }

    fill(dc,dc+N,INF);
    rep(i,n){
        if(coal[i]){
            dc[i] = 0;
            que.push(i);
        }
    }
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int e:rG[v]){
            if(dc[e] > dc[v]+1){
                dc[e] = dc[v]+1;
                que.push(e);
            }
        }
    }

    int ans = INF;
    rep(i,n){
//        printf(" %d :: %d %d %d\n",i,ds[i],di[i],dc[i]);
        if(iron[i]){
            ans = min(ans, ds[i]+dc[i]);
        }
        else if(coal[i]){
            ans = min(ans, ds[i]+di[i]);
        }
        else{
            ans = min(ans, ds[i]+di[i]+dc[i]);
        }
    }

    if(ans == INF) printf("impossible\n");
    else printf("%d\n", ans);
    return 0;
}