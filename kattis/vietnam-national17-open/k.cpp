#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#define X first
#define Y second

using P = pair<ll,ll>;
using VP = vector<P>;

P SUB(P a, P b){
    return {a.X-b.X, a.Y-b.Y};
}

ll dot(P a, P b){
    return a.X*b.X + a.Y*b.Y;
}

ll cross(P a, P b){
    return a.X*b.Y - a.Y*b.X;
}

ll norm(P a){
    return a.X*a.X + a.Y*a.Y;
}

int ccw(P a, P b, P c){
    b = SUB(b,a);
    c = SUB(c,a);
    if(cross(b,c) > 0) return +1;
    if(cross(b,c) < 0) return -1;
    if(dot(b,c) < 0) return +2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}

VP convexHull(VP ps){
    int n = ps.size(), k = 0;
    sort(all(ps));
    VP ch(2*n);
    for(int i=0; i<n; ch[k++] = ps[i++]){
        while(k>=2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    }
    for(int i=n-2, t=k+1; i>=0; ch[k++] = ps[i--]){
        while(k>=t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    }
    ch.resize(k-1);
    return ch;
}

int inPolygon(const VP &ps, P p){
    int n = ps.size();
    bool in = false;
    rep(i,n){
        P a = SUB(ps[i],p);
        P b = SUB(ps[(i+1)%n],p);
        if( cross(a,b)==0 && dot(a,b)<=0 ) return 2;
        if(a.Y > b.Y) swap(a,b);
        if( (a.Y*b.Y<0 || (a.Y*b.Y<=0 && b.Y>0)) && cross(a,b)<=0 ) in = !in;
    }
    return in;
}

P READ(){
    ll x,y;
    scanf(" %lld %lld", &x, &y);
    return P(x,y);
}

int solve(){
    int n;
    scanf(" %d", &n);
    VP t(n);
    rep(i,n) t[i] = READ();

    int s;
    scanf(" %d", &s);
    VP c(s);
    rep(i,s) c[i] = READ();

    VP h = convexHull(t);

    auto COUNT = [&](){
        int ans = 0;
        rep(i,s){
            if(inPolygon(h, c[i]) != 0) ++ans;
        }
        return ans;
    };

    if(h.size()<=2) return 0;
    if(h.size()>=4) return COUNT();

    assert(h.size() == 3);

    bool exist = false;
    rep(i,n){
        if(inPolygon(h, t[i]) == 1) exist = true;
    }
    if(exist) return COUNT();

    vector<int> ect(3,0);
    rep(i,n){
        bool vertex = false;
        rep(j,3)if(h[j] == t[i]) vertex = true;
        if(vertex) continue;

        int ct = 0;
        int idx = -1;
        rep(j,3){
            P p = h[j], q = h[(j+1)%3];
            if( ccw(p,q,t[i]) == 0 ){
                ++ct;
                idx = j;
            }
        }
        assert(ct<=1);
        if(ct) ect[idx]++;
    }

    int z = 0;
    rep(i,3) z += (ect[i]==0);

    if(z>=2) return 0;
    if(z==0) return COUNT();

    P dame;
    rep(i,3)if(ect[i]==0) dame = h[(i+2)%3];

    // printf(" DAME : %lld %lld\n",dame.X,dame.Y);
    VP nh;
    rep(i,n)if(t[i] != dame) nh.pb(t[i]);
    h = convexHull(nh);

    assert(h.size()==4);
    return COUNT();
}

int main(){
    printf("%d\n", solve());
    return 0;
}
