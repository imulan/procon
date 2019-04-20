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

const int N = 1000010;
vector<int> G[N];

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    rep(i,k){
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    int cc = 0;
    vector<int> cmp(n,-1);
    rep(i,n){
        if(cmp[i]!=-1) continue;

        queue<int> que;
        que.push(i);
        cmp[i] = cc;
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v]){
                if(cmp[e] == -1){
                    que.push(e);
                    cmp[e] = cc;
                }
            }
        }

        ++cc;
    }

    bool ok = true;
    rep(i,n){
        if(cmp[i] != cmp[n-1-i]) ok = false;
    }
    cout << (ok?"Yes":"No") << "\n";
    return 0;
}
