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
    int n,m;
    cin >>n >>m;

    vector<vector<int>> G(n);
    rep(i,m){
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    int ans = 0;
    vector<bool> vis(n);
    rep(i,n)if(!vis[i]){
        int cc = 0;
        queue<int> que;
        que.push(i);
        vis[i] = true;
        ++cc;
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v]){
                if(!vis[e]){
                    que.push(e);
                    vis[e] = true;
                    ++cc;
                }
            }
        }

        if(cc==1) ++ans;
        else --ans;
    }
    cout << abs(ans) << endl;
    return 0;
}
