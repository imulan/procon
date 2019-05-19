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

const int N = 100010;
vector<int> G[N];

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);
    rep(i,m){
        int x,y,z;
        scanf(" %d %d %d", &x, &y, &z);
        --x;
        --y;
        G[x].pb(y);
        G[y].pb(x);
    }

    int c = 0;
    vector<bool> vis(n);
    rep(i,n)if(!vis[i]){
        ++c;
        vis[i]=true;
        queue<int> que({i});
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v]){
                if(!vis[e]){
                    vis[e] = true;
                    que.push(e);
                }
            }
        }
    }
    printf("%d\n", c);
    return 0;
}
