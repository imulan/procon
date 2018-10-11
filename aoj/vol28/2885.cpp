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
    while(cin >>n >>m,n){
        vector<vector<int>> G(n);
        rep(i,m){
            int u,v;
            cin >>u >>v;
            --u;
            --v;
            G[u].pb(v);
            G[v].pb(u);
        }

        vector<int> d(n,1234567);
        d[0] = 0;
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v]){
                if(d[e] > d[v]+1){
                    d[e] = d[v]+1;
                    que.push(e);
                }
            }
        }

        bool bi = true;
        int ct[2]={};
        rep(i,n){
            for(int e:G[i]){
                if(d[i]%2 == d[e]%2) bi = false;
            }
            ++ct[d[i]%2];
        }

        set<int> ans;
        if(bi){
            rep(i,2){
                if(ct[i]%2==0) ans.insert(ct[i]/2);
            }
        }

        cout << ans.size() << endl;
        for(int i:ans) cout << i << endl;
    }
    return 0;
}
