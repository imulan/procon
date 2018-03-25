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

const int N = 110;
char f[N][N];

int main(){
    int a,b;
    cin >>a >>b;
    --a; --b;

    for(int i=0; i<50; ++i){
        rep(j,100) f[i][j] = '.';
    }
    for(int i=50; i<100; ++i){
        rep(j,100) f[i][j] = '#';
    }

    for(int i=1; i<49; i+=2){
        for(int j=1; j<100; j+=2){
            if(b==0) break;
            f[i][j] = '#';
            --b;
        }
        if(b==0) break;
    }

    for(int i=51; i<100; i+=2){
        for(int j=1; j<100; j+=2){
            if(a==0) break;
            f[i][j] = '.';
            --a;
        }
        if(a==0) break;
    }

    printf("100 100\n");
    rep(i,100){
        rep(j,100) printf("%c",f[i][j]);
        printf("\n");
    }
    return 0;
}
