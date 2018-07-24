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

using vi = vector<int>;
using P = pair<int,vi>;

const int N = 1000001;
vector<int> G[N];
int ans[N];

void merge(P &a, P &b){
    int A = a.se.size(), B = b.se.size();
    if(A<B){
        swap(a,b);
        swap(A,B);
    }
    int aval = a.se[a.fi];
    rep(i,B){
        a.se[A-1-i] += b.se[B-1-i];
        if(a.se[A-1-i]>aval || (a.se[A-1-i]==aval && a.fi<A-1-i)){
            aval = a.se[A-1-i];
            a.fi = A-1-i;
        }
    }
}

P dfs(int x, int p){
    P ret(-1,vi());
    for(int c:G[x])if(c!=p){
        P res = dfs(c,x);
        merge(ret,res);
    }

    ret.se.pb(1);
    if(ret.fi==-1) ret.fi=0;
    else{
        if(ret.se[ret.fi]==1) ret.fi = ret.se.size()-1;
    }

    ans[x] = ret.se.size()-1-ret.fi;
    return ret;
}

int main(){
    int n;
    scanf(" %d", &n);
    rep(i,n-1){
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        G[x].pb(y);
        G[y].pb(x);
    }
    dfs(0,-1);

    rep(i,n) printf("%d\n", ans[i]);
    return 0;
}
