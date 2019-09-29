#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define L first
#define R second
using pi = pair<int,int>;

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    set<int> rem;
    map<int,int> pos;
    vector<int> a(n);
    rep(i,n){
        scanf(" %d", &a[i]);
        --a[i];
        pos[a[i]] = i;
        rem.insert(a[i]);
    }

    vector<pi> node(n,{-1,-1});
    rep(i,n){
        if(i-1>=0) node[a[i]].L = a[i-1];
        if(i+1<n) node[a[i]].R = a[i+1];
    }

    vector<int> ans(n,-1);
    int team = 0;
    while(!rem.empty()){
        int mx = *rem.rbegin();

        set<int> add;
        add.insert(mx);

        int l = mx;
        rep(i,k){
            l = node[l].L;
            if(l == -1) break;
            add.insert(l);
        }

        int r = mx;
        rep(i,k){
            r = node[r].R;
            if(r == -1) break;
            add.insert(r);
        }

        if(l!=-1) l = node[l].L;
        if(r!=-1) r = node[r].R;

        if(l!=-1) node[l].R = r;
        if(r!=-1) node[r].L = l;

        for(int i:add){
            ans[pos[i]] = team;
            rem.erase(i);
        }
        team = !team;
    }

    rep(i,n) printf("%d", ans[i]+1);
    printf("\n");
    return 0;
}
