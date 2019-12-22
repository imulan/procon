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

int main(){
    int n;
    cin >>n;

    vector<int> line;
    queue<int> leaf;
    vector<int> a(n);
    rep(i,n){
        cin >>a[i];
        if(a[i] == 1) leaf.push(i);
        else line.pb(i);
    }

    int L = line.size();
    if(L==0){
        cout << "NO\n";
        return 0;
    }

    vector<vector<int>> G(n);

    auto ADD = [&](int u, int v){
        --a[u];
        --a[v];
        G[u].pb(v);
        G[v].pb(u);
    };

    rep(i,L-1) ADD(line[i],line[i+1]);

    int dia = L-1;
    for(int lidx:{0,L-1}){
        if(!leaf.empty()){
            int u = leaf.front();
            leaf.pop();
            ADD(line[lidx], u);
            ++dia;
        }
    }

    int idx = 0;
    while(!leaf.empty()){
        int i = leaf.front();
        leaf.pop();
        while(idx<L && a[line[idx]]<=0) ++idx;
        if(idx==L){
            cout << "NO\n";
            return 0;
        }

        ADD(i,line[idx]);
    }

    vector<pair<int,int>> edge;
    rep(i,n)for(int j:G[i])if(i<j) edge.pb({i,j});

    cout << "YES " << dia << "\n";
    cout << edge.size() << "\n";
    for(const auto &e:edge) cout << e.fi+1 << " " << e.se+1 << "\n";
    return 0;
}
