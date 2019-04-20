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

using pi = pair<int,int>;

const pi ZERO(0,0);

pi query(pi p){
    cout << p.fi << " " << p.se << endl;
    cout << flush;

    int x,y;
    cin >>x >>y;
    assert(x!=-1);
    return {x,y};
}

void solve(){
    int a;
    cin >>a;

    if(a==20){
        rep(i,1000){
            pi res = query({2,3*(i%3)+2});
            if(res == ZERO) return;
        }
    }
    else{
        int ct = 0;
        bool f[20][20]={};

        rep(i,5)rep(j,5){
            int x = 3*i+2, y = 3*j+2;
            while(ct<1000){
                pi res = query({x,y});
                if(res == ZERO) return;

                f[res.fi][res.se] = true;
                bool ok = true;
                for(int X=-1; X<=1; ++X)for(int Y=-1; Y<=1; ++Y){
                    ok &= f[x+X][y+Y];
                }
                if(ok) break;
            }
        }
    }
}

int main(){
    int T;
    cin >>T;
    rep(i,T) solve();
    return 0;
}
