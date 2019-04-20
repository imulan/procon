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

const double EPS = 1e-2;

using pi = pair<int,int>;

int n,w,h;

int GET_P(){
    int x,y;
    scanf(" %d %d", &x, &y);

    if(x==0) return y;
    if(y==h) return h+x;
    if(x==w) return h+w+(h-y);
    return h+w+h+(w-x);
}

pi GET_S(){
    int a = GET_P();
    int b = GET_P();
    if(a > b) swap(a,b);

    // dbg((pi(b,a)));
    return {a,b};
}

void OUT_V(int v, int m){
    v %= 2*(w+h);

    double vx,vy;
    if(v<=h){
        vx = 0;
        vy = v - m*EPS;
    }
    else if(v<=h+w){
        vx = v-h- m*EPS;
        vy = h;
    }
    else if(v<=h+w+h){
        vx = w;
        vy = h - (v-h-w- m*EPS);
    }
    else{
        vx = w - (v-h-w-h-m*EPS);
        vy = 0;
    }

    printf("%.4f %.4f",vx,vy);
}

void PRINT(double ax, double ay, double bx, double by){
    printf("%.4f %.4f %.4f %.4f\n", ax, ay, bx, by);
}

int f(int v){
    v %= 2*(w+h);

    if(v<=h){
        return 0;
    }
    else if(v<=h+w){
        return 1;
    }
    else if(v<=h+w+h){
        return 2;
    }
    else{
        return 3;
    }
}

bool check(int pp, int qq){
    return f(pp) != f(qq);
}

int main(){
    scanf(" %d %d %d", &n, &w, &h);

    vector<pi> p(n);
    vector<pi> v;
    rep(i,n){
        p[i] = GET_S();
        for(int j:{p[i].fi, p[i].se}) v.pb({j,i});
        for(int j:{p[i].fi, p[i].se}) v.pb({j+2*(w+h),i});
    }
    sort(all(v));

    vector<int> ct(n);
    int ok = 0;
    rep(i,n){
        int idx = v[i].se;
        ++ct[idx];

        if(ct[idx] == 1) ++ok;
        else if(ct[idx] == 2) --ok;
    }
    if(ok==n && check(v[0].fi, v[n-1].fi)){
        printf("1\n");
        OUT_V(v[0].fi, 1);
        printf(" ");
        OUT_V(v[n-1].fi, -1);
        printf("\n");
        return 0;
    }

    for(int i=1; i<=2*n; ++i){
        int idx = v[i-1].se;
        if(ct[idx] == 1) --ok;
        else if(ct[idx] == 2) ++ok;
        --ct[idx];

        idx = v[n+i-1].se;
        ++ct[idx];
        if(ct[idx] == 1) ++ok;
        else if(ct[idx] == 2) --ok;

        if(ok==n && check(v[i].fi, v[i+n-1].fi)){
            printf("1\n");
            OUT_V(v[i].fi, 1);
            printf(" ");
            OUT_V(v[i+n-1].fi, -1);
            printf("\n");
            return 0;
        }
    }

    printf("2\n");
    PRINT(0, EPS, w, h-EPS);
    PRINT(0, h-EPS, w, EPS);
    return 0;
}
