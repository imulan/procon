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

    vector<bool> c(n);
    rep(i,m){
        int a,l;
        cin >>a >>l;
        rep(j,l){
            int k = (a+j)%n;
            c[k] = true;
        }
    }

    map<int,int> ct;
    vector<bool> vis(n);
    rep(i,n)if(c[i]){
        if(vis[i]) continue;
        queue<int> que({i});
        vis[i] = true;
        int cc = 1;
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int j:{n-1,1}){
                int nx = (v+j)%n;
                if(c[nx] && !vis[nx]){
                    que.push(nx);
                    vis[nx] = true;
                    ++cc;
                }
            }
        }

        ++ct[cc];
    }

    vector<pair<int,int>> ans;
    for(auto &p:ct) ans.pb(p);
    reverse(all(ans));
    for(const auto &p:ans) cout << p.fi << " " << p.se << "\n";
    return 0;
}
