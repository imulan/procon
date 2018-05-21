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

const int P = 11;
int p[P] = {2,3,5,7,11,13,17,19,23,29,31};

int DIV[33][P]={};
int f[33][P]={};

int D,H;
set<ll> s;

int x[33];
int sum_x = 0;

void dfs(int d, int px){
    if(d==D){
        if(sum_x != H-1) return;

        // printf("x = {");
        // rep(i,D) printf(" %d,",x[i]);
        // printf("}\n");

        int ct[P] = {};
        rep(i,D)rep(j,P) ct[j] += f[x[i]][j];

        ll v = 1;
        rep(i,P)rep(j,f[sum_x][i]-ct[i]) v*=p[i];
        s.insert(v);
        // dbg(sum_x);
        // dbg(v);
        return;
    }

    int rem = D-d;
    for(int i=px; i<=H-1; ++i){
        if(H-1 - sum_x < i*rem) break;

        x[d] = i;
        sum_x += i;
        dfs(d+1,i);
        x[d] = -1;
        sum_x -= i;
    }
}

int main(){
    cin >>D >>H;

    for(int i=1; i<33; ++i){
        int t = i;
        rep(j,P){
            while(t%p[j]==0){
                t/=p[j];
                ++DIV[i][j];
            }
        }

        // printf("DIV %d:" ,i);
        // rep(j,P) printf(" %d",DIV[i][j]);
        // printf("\n");
    }

    for(int ff=1; ff<H; ++ff){
        for(int i=1; i<=ff; ++i){
            rep(j,P) f[ff][j] += DIV[i][j];
        }
    }

    dfs(0,0);

    for(ll i:s) cout << i << "\n";
    return 0;
}
