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

const int N = 100010;
int prex[N]={}, prey[N]={};
int sufx[N]={}, sufy[N]={};

int solve(){
    int d,n,m;
    cin >>d >>n >>m;
    vector<int> x1(d),y1(d),x2(d),y2(d);
    rep(i,d) cin >>x1[i] >>y1[i] >>x2[i] >>y2[i];

    // l,r,t,b
    int cnt[4];
    rep(i,4) cin >>cnt[i];

    rep(i,d){
        int x = min(x1[i],x2[i]);
        ++prex[x];
        x = max(x1[i],x2[i]);
        ++sufx[x];

        int y = min(y1[i],y2[i]);
        ++prey[y];
        y = max(y1[i],y2[i]);
        ++sufy[y];
    }

    rep(i,N-1){
        prex[i+1] += prex[i];
        prey[i+1] += prey[i];
    }
    for(int i=N-2; i>=0; --i){
        sufx[i] += sufx[i+1];
        sufy[i] += sufy[i+1];
    }

    rep(i,d){
        int lx = min(x1[i],x2[i]), rx = max(x1[i],x2[i]);
        int ly = min(y1[i],y2[i]), ry = max(y1[i],y2[i]);

        int v[4];

        if(lx == rx){
            v[0] = prex[lx-1];
            v[1] = sufx[rx+1];
        }
        else{
            v[0] = prex[lx]-1;
            v[1] = sufx[rx]-1;
        }

        if(ly == ry){
            v[2] = prey[ly-1];
            v[3] = sufy[ry+1];
        }
        else{
            v[2] = prey[ly]-1;
            v[3] = sufy[ry]-1;
        }

        bool valid = true;
        rep(j,4) valid &= (v[j]==cnt[j]);
        if(valid) return i+1;
    }
    return -1;
}

int main(){
    cout << solve() << endl;
    return 0;
}
