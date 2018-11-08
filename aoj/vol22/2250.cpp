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

const int N = 1010;

int n,t;
int M[N],L[N],K[N];
int mod[N];

int c[N];
int ed[N];

const int INF = 191919;
inline bool check(int x){
    fill(c,c+N,INF);
    fill(ed,ed+N,0);
    int op = x;

    rep(i,t+1){
        // end operation
        op += ed[i];

        rep(j,n)if(c[j]==INF){
            if(i+M[j]>t) return false;

            int mt = i%mod[j];
            if(mt<=L[j] && op>0){
                --op;
                int et = i+M[j];
                c[j] = et;

                if(et<=t) ++ed[et];
            }
        }
    }

    rep(i,n)if(c[i]>t) return false;
    return true;
}

int main(){
    while(scanf(" %d %d", &n, &t),n){
        rep(i,n){
            scanf(" %d %d %d", &M[i], &L[i], &K[i]);
            mod[i] = (L[i]+K[i]);
        }

        int ok=1;
        while(ok<=n && !check(ok)) ++ok;
        printf("%d\n",ok);
    }
    return 0;
}
