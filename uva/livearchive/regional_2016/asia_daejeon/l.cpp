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

const int N = 1<<20;
const int INF = 2*N;

int ch[N][2];
int num[N];
int d[N];

int solve(int n){
    memset(ch,-1,sizeof(ch));
    fill(d,d+n,INF);

    rep(i,n){
        num[i]=0;
        rep(j,2){
            scanf(" %d", &ch[i][j]);
            --ch[i][j];
            num[i] += (ch[i][j]!=-1);
        }
    }

    d[0] = 1;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front();
        que.pop();

        if(num[v]<2) return d[v];
        rep(j,2){
            int nx = ch[v][j];
            if(ch[v][j]!=-1){
                d[nx] = d[v]+1;
                que.push(nx);
            }
        }
    }
    assert(false);
}

int main(){
    int n;
    while(cin >>n) printf("%d\n",solve(n));
    return 0;
}
