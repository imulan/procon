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

const int N = 303;
bool vis[N][N][N];
double dp[N][N][N];

int n;

double E(int x, int y, int z){
    if(x+y+z == 0) return 0;
    if(vis[x][y][z]) return dp[x][y][z];

    int w = n-(x+y+z);

    double ret = 1;
    if(x>0) ret += E(x-1,y,z)*x/n;
    if(y>0) ret += E(x+1,y-1,z)*y/n;
    if(z>0) ret += E(x,y+1,z-1)*z/n;

    ret /= (double)(n-w)/n;
    vis[x][y][z] = true;
    return dp[x][y][z] = ret;
}

int main(){
    scanf(" %d", &n);

    int a[4]={};
    rep(i,n){
        int num;
        scanf(" %d", &num);
        ++a[num];
    }

    printf("%.15f\n", E(a[1],a[2],a[3]));
    return 0;
}
