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

using ps = pair<string,string>;

ps split(string s){
    int n = s.size();
    int idx = 0;
    while(idx<n && s[idx]!='-') ++idx;

    return {s.substr(0,idx), s.substr(idx+1)};
}

const int N = 202;
const int INF = 101010;

// 入力から分かる強さ関係
vector<int> G[N];
bool arr[N][N];

int d[N][N];

// 水準関係
int C[N][N];

int main(){
    int n;
    while(cin >>n,n){
        rep(i,N) G[i].clear();
        rep(i,N)rep(j,N) arr[i][j] = false;

        rep(i,N)rep(j,N) d[i][j]=INF;
        rep(i,N) d[i][i]=0;

        rep(i,N)rep(j,N) C[i][j]=INF;
        rep(i,N) C[i][i]=0;

        map<string,int> c2id;
        int V = 0;
        vector<string> names;
        rep(i,n){
            string s;
            cin >>s;
            ps cross = split(s);

            if(!c2id.count(cross.fi)){
                c2id[cross.fi] = V;
                ++V;
                names.pb(cross.fi);
            }
            if(!c2id.count(cross.se)){
                c2id[cross.se] = V;
                ++V;
                names.pb(cross.se);
            }
            int u = c2id[cross.fi], v = c2id[cross.se];
            G[u].pb(v);
            C[u][v] = 1;
            d[u][v] = d[v][u] = 1;
            arr[u][v] = true;
        }

        rep(k,V)rep(i,V)rep(j,V) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

        auto same_degree = [&](int a, int b){
            bool same = false;
            rep(i,V){
                if( (arr[a][i]||arr[i][a]) && (arr[b][i]||arr[i][b]) ) same = true;
            }
            if(!same) return false;

            rep(i,V){
                if(arr[i][a]&&arr[b][i]) return false;
                if(arr[a][i]&&arr[i][b]) return false;
            }
            return true;
        };

        rep(i,V)rep(j,i){
            if(same_degree(i,j)){
                // cout << "DEG :: " << names[i] << " " << names[j] << endl;
                C[i][j] = C[j][i] = 1;
            }
        }
        rep(k,V)rep(i,V)rep(j,V) C[i][j] = min(C[i][j], C[i][k]+C[k][j]);

        cout << V << endl;

        int Q;
        cin >>Q;
        while(Q--){
            string q;
            cin >>q;

            ps qc = split(q);

            bool ok = false;
            if(c2id.count(qc.fi) && c2id.count(qc.se)){
                int u = c2id[qc.fi], v = c2id[qc.se];
                // dbg(C[u][v]);

                if(d[u][v]%2==1 && C[u][v]<INF) ok = true;
            }
            cout << (ok?"YES":"NO") << endl;
        }
        // dbg(c2id.size());
        // dbg(names);
    }
    return 0;
}
