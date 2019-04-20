#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back

const int mod = 1e9+7;

unsigned int y=11451419;
inline int rand_int(int l=0,int r=11451419){
    y=y^(y<<13);
    y=y^(y>>17);
    y=y^(y<<5);
    return y%(r-l+1)+l;
}
int n;

const int N = 1000;
int m[3][N][N];

int v[N],r[N],a[N],b[N];

inline void mul(int x){
    memset(r,0,sizeof(r));
    rep(i,n)rep(j,n) (r[i] += ((ll)m[x][i][j]*v[j])%mod ) %= mod;
}

int main(){
    scanf(" %d", &n);
    rep(i,3){
        rep(j,n)rep(k,n) scanf(" %d", &m[i][j][k]);
    }

    rep(loop,30){
        rep(i,n) v[i] = rand_int();

        mul(2);
        rep(i,n) a[i] = r[i];

        mul(1);
        rep(i,n) v[i] = r[i];
        mul(0);
        rep(i,n) b[i] = r[i];

        rep(i,n){
            if(a[i]!=b[i]){
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
    return 0;
}
