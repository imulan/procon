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

const int N = 200002;
vector<int> ch[N];

vector<int> et;
int idx[N];
int sz[N];
void dfs(int x){
    et.pb(x);
    sz[x] = 1;
    for(int c:ch[x]){
        dfs(c);
        sz[x] += sz[c];
    }
}

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    for(int i=1; i<n; ++i){
        int p;
        scanf(" %d", &p);
        --p;
        ch[p].pb(i);
    }

    dfs(0);
    rep(i,n) idx[et[i]] = i;

    while(q--){
        int u,k;
        scanf(" %d %d", &u, &k);
        --u;

        int j = idx[u]+k-1;
        int ans = -1;
        if(k<=sz[u]) ans = et[j]+1;
        printf("%d\n", ans);
    }

    return 0;
}
