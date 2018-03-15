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

using vd = vector<double>;
using mat = vector<vd>;

mat mul(const mat &a, const mat &b){
    int n = a.size();
    mat c(n,vd(n));
    rep(i,n)rep(j,n)rep(k,n) c[i][j] += a[i][k]*b[k][j];
    return c;
}

vd mul(const mat &a, const vd &v){
    int n = a.size();
    vd ret(n);
    rep(i,n)rep(j,n) ret[i] += a[i][j]*v[j];
    return ret;
}

mat pow(const mat &a, int x){
    int n = a.size();

    mat ret(n,vd(n));
    rep(i,n) ret[i][i] = 1;

    mat p(a);
    while(x){
        if(x&1) ret = mul(ret,p);
        p = mul(p,p);
        x>>=1;
    }
    return ret;
}

const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int main(){
    int h,w,t;
    cin >>h >>w >>t;
    int sy,sx,gy,gx;
    cin >>sy >>sx >>gy >>gx;

    vector<string> b(h);
    rep(i,h) cin >>b[i];

    auto ID = [&](int y, int x){ return y*w+x; };

    int n = h*w;
    mat A(n,vd(n));

    rep(i,h)rep(j,w)if(b[i][j]=='.'){
        int ct = 0;
        rep(d,4){
            int ny = i+dy[d], nx = j+dx[d];
            ct += (b[ny][nx]=='.');
        }

        if(ct==0){
            A[ID(i,j)][ID(i,j)] = 1;
        }
        else{
            double p = 1.0/ct;
            rep(d,4){
                int ny = i+dy[d], nx = j+dx[d];
                if(b[ny][nx]=='.') A[ID(ny,nx)][ID(i,j)] = p;
            }
        }
    }

    vd start(n);
    start[ID(sy,sx)] = 1;

    vd ans = mul(pow(A,t), start);

    printf("%.10f\n", ans[ID(gy,gx)]);
    return 0;
}
