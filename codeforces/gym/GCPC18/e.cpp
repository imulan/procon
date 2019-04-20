#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N = 10000010;
bool p[N];
const double EPS = 1e-8;

int READ(){
    string s;
    cin >>s;

    int x = 0;

    bool dot = false;
    int ct = 0;

    for(char c:s){
        if(c=='.') dot = true;
        else{
            x = 10*x + c-'0';
            if(dot) ++ct;
        }
    }

    rep(i,5-ct) x *= 10;
    return x;
}

void solve(){
    int x = READ(), y = READ();
    int g = __gcd(x,y);

//    printf(" x y %d %d  g %d\n",x,y,g);
    x /= g;
    y /= g;

    if(x==1 && y==1){
        x = 2;
        y = 2;
    }

    if(p[x] && p[y]) printf("%d %d\n",x,y);
    else printf("impossible\n");
}

int main(){
    fill(p,p+N,true);
    p[0] = p[1] = false;
    for(int i=2; i<N; ++i){
        if(p[i]) for(int j=2*i; j<N; j+=i) p[j] = false;
    }

    int n;
    scanf(" %d", &n);
    rep(i,n) solve();
    return 0;
}

