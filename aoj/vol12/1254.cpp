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

using pi = pair<int,int>;

struct Polygon{
    int id;
    int V;
    vector<pi> v;
};

map<string,int> name2id;
int C;
Polygon read_p(){
    Polygon ret;

    string name;
    cin >>name;

    if(!name2id.count(name)) name2id[name] = C++;
    ret.id = name2id[name];

    int x,y;
    while(1){
        cin >>x;
        if(x==-1) break;

        cin >>y;
        ret.v.pb({x,y});
    }
    ret.V = ret.v.size();
    return ret;
}

bool share_edge(pi p1, pi p2, pi q1, pi q2){
    if(p1>p2) swap(p1,p2);
    if(q1>q2) swap(q1,q2);

    int px = p2.fi-p1.fi, py = p2.se-p1.se;
    int pg = __gcd(abs(px), abs(py));
    px /= pg;
    py /= pg;

    int qx = q2.fi-q1.fi, qy = q2.se-q1.se;
    int qg = __gcd(abs(qx), abs(qy));
    qx /= qg;
    qy /= qg;

    if(px!=qx || py!=qy) return false;

    if(px == 0){
        if(p1.fi != q1.fi) return false;
        return (p1<=q1 && q1<p2) || (q1<=p1 && p1<q2) ;
    }
    else{
        pi tp(p1);
        int D = p1.fi/px;
        tp.fi -= px*D;
        tp.se -= py*D;

        pi tq(q1);
        D = q1.fi/qx;
        tq.fi -= qx*D;
        tq.se -= qy*D;
        if(tp != tq) return false;

        // cout << p1 << " " << p2 << " " <<q1 <<" " <<q2<<endl;
        return (p1<=q1 && q1<p2) || (q1<=p1 && p1<q2) ;
    }
}

bool check(const Polygon &p, const Polygon &q){
    rep(i,p.V)rep(j,q.V){
        if(share_edge(p.v[i], p.v[(i+1)%p.V], q.v[j], q.v[(j+1)%q.V])) return true;
    }
    return false;
}

vector<vector<bool>> adj;
int ans;
int col[10];
void dfs(int d, int new_color){
    if(d==C){
        ans = min(ans,new_color);
        return;
    }

    rep(i,new_color){
        col[d] = i;

        bool ok = true;
        rep(j,d){
            if(adj[d][j] && col[j]==col[d]) ok = false;
        }
        if(ok) dfs(d+1,new_color);

        col[d] = -1;
    }

    col[d] = new_color;
    dfs(d+1,new_color+1);
    col[d] = -1;
}

int main(){
    int n;
    while(cin >>n,n){
        name2id.clear();
        C = 0;

        vector<Polygon> p(n);
        rep(i,n) p[i] = read_p();

        adj = vector<vector<bool>>(C,vector<bool>(C));
        rep(i,n)rep(j,i){
            if(check(p[i],p[j])){
                adj[p[i].id][p[j].id] = true;
                adj[p[j].id][p[i].id] = true;
            }
        }

        ans = C;
        rep(i,C) col[i] = -1;
        dfs(0,0);
        cout << ans << endl;
    }
    return 0;
}
