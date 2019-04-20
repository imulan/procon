#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define repl(i,a,b) for(int (i)=a;(i)<(int)(b);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x<<"="<<x<<endl

using F = ll;

const ll mod = 1e9+7;

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n>>=1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x,mod-2);
}

struct Point{
    ll X,Y;
    Point(){}
    Point(F _X, F _Y){
        X = _X;
        Y = _Y;
    }
};

F add_f(F p, F q, int sg){
    return (p+sg*q+mod)%mod;
}

F mul_f(F p, F q){
    return (p*q)%mod;
}

F dot(Point a, Point b){
    return add_f(mul_f(a.X,b.X), mul_f(a.Y,b.Y), 1);
}

F cross(Point a, Point b){
    return add_f(mul_f(a.X,b.Y), mul_f(a.Y,b.X), -1);
}

Point add_p(Point p, Point q, int sg){
    return Point(add_f(p.X,q.X,sg), add_f(p.Y,q.Y,sg));
}

Point crosspointLL(Point a1, Point a2, Point b1, Point b2){
    F d1 = cross( add_p(b2,b1,-1), add_p(b1,a1,-1) );
    F d2 = cross( add_p(b2,b1,-1), add_p(a2,a1,-1) );

    // return a1 + d1/d2*(a2-a1);
    Point ret = a1;

    Point ad = add_p(a2,a1,-1);

    F ff = mul_f(d1,mod_inv(d2));
    ad.X = mul_f(ad.X, ff);
    ad.Y = mul_f(ad.Y, ff);
    ret = add_p(ret,ad,1);

    return ret;
}

bool eq_f(F p, F q){
    return p==q;
}

bool eq(Point p, Point q){
    return eq_f(p.X,q.X) && eq_f(p.Y,q.Y);
}

bool parallel(Point a1, Point a2, Point b1, Point b2){
    F ax = add_f(a2.X,a1.X,-1), ay = add_f(a2.Y,a1.Y,-1);
    F bx = add_f(b2.X,b1.X,-1), by = add_f(b2.Y,b1.Y,-1);

    F res = cross(Point(ax,ay),Point(bx,by));
    return res==0;
}

Point RP(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

int solve(){
    int n;
    cin >>n;

    Point d = RP();
    vector<Point> a(n),b(n),c(n);
    rep(i,n){
        a[i] = RP();
        b[i] = RP();
        c[i] = RP();
    }

    rep(i,n){
        if(eq(c[i],d)) return i;
        if(parallel(a[i],b[i],c[i],d)) return i;

        d = crosspointLL(a[i],b[i],c[i],d);
    }
    return n;
}

int main(){
    cout << solve() << endl;
    return 0;
}
