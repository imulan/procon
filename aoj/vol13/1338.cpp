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

using pl = pair<ll,ll>;

struct TIME{
    ll h,m;
    pl s;
};

void PRINT_T(TIME t){
    printf("%lld %lld %lld %lld\n", t.h, t.m, t.s.fi, t.s.se);
}

const ll INF = 60*60*100*10;

bool big(pl a, pl b){
    return a.fi*b.se < b.fi*a.se;
}

pl norm(pl a){
    ll G = __gcd(a.fi, a.se);
    a.fi /= G;
    a.se /= G;
    return a;
}

int H,x,y,z;

// a から b
pl sub(TIME a, TIME b){
    pl p = a.s;
    p.fi += p.se*60*(60*a.h+a.m);

    pl q = b.s;
    q.fi += q.se*60*(60*b.h+b.m);

    while(big(q,p)) q.fi += H*3600*q.se;
    p = norm(p);
    q = norm(q);

    ll X = q.fi*p.se - p.fi*q.se;
    ll Y = q.se*p.se;
    pl res(X,Y);
    res = norm(res);

    // printf(" DIFF:\n");
    // PRINT_T(a);
    // PRINT_T(b);
    // dbg(res);
    return res;
}

int main(){
    while(cin >>H >>x >>y >>z,H){
        ll T = 60*H;

        TIME base = {x,y,{z,1}};

        pl diff(INF,1);
        TIME ans;

        auto upd = [&](ll p, ll q, int i, int j){
            ll t = 60*i+j;
            if(p>=0 && p/q<60){
                pl s = norm({p,q});
                // printf(" CAND %d %d %lld/%lld :", i,j,s.fi,s.se);

                pl th(60*t*s.se+s.fi, 60*T*s.se);
                pl tm(60*j*s.se+s.fi, 3600*s.se);
                pl ts(s.fi, s.se*60);
                th = norm(th);
                tm = norm(tm);
                ts = norm(ts);

                if( th!=tm && th!=ts && tm!=ts ){
                    TIME tmp = {i,j,s};
                    pl td = sub(base, tmp);
                    if(big(td,diff)){
                        diff = td;
                        ans = tmp;
                    }
                    // printf("OK");
                }
                // printf("\n");
            }
        };

        rep(i,H)rep(j,60){
            ll t = 60*i+j;

            // 1つめ
            ll p = 3600*t - 60*T*j;
            ll q = T - 60;
            upd(p,q,i,j);

            // 2つめ
            p = 3600*t + 60*T*j;
            q = 119*T - 60;
            upd(p,q,i,j);

            // 3つめ
            p = 3600*(T+t) + 60*T*j;
            q = 119*T - 60;
            upd(p,q,i,j);

            // 4つめ
            p = 3600*(t-T) + 60*T*j;
            q = 119*T - 60;
            upd(p,q,i,j);
        }

        PRINT_T(ans);
    }
    return 0;
}
