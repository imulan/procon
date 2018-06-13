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

using vi = vector<int>;
using vvi = vector<vi>;
using bl = vector<vvi>;

const int H = 17;

vvi read_one(){
    vvi ret(2,vi(2));
    rep(i,2){
        string s;
        cin >>s;
        rep(j,2) if(s[j]=='#') ret[!i][j]=1;
    }
    return ret;
}

bool IN(int y, int x){
    return 0<=y && y<2 && 0<=x && x<2;
}

int n;
vector<bl> b;

int dfs(int dep, vector<vvi> f){
    if(dep==n) return 0;
    int ret = 0;
    for(int dy=-1; dy<=1; ++dy)for(int dx=-1; dx<=1; ++dx){
        bool ok = true;
        bl B = b[dep];
        rep(i,2){
            rep(j,2)rep(k,2){
                if(B[i][j][k]==1){
                    int ny=j+dy, nx=k+dx;
                    if(!IN(ny,nx)) ok = false;
                }
            }
        }
        if(!ok) continue;
        // printf(" dir :: %d %d\n",dy,dx);

        int h = H-2;
        while(h>=0){
            bool can_place = true;
            rep(i,2)rep(j,2)rep(k,2){
                int ny = j+dy, nx = k+dx;
                // printf(" %d %d %d  NN %d %d\n",i,j,k,ny,nx);
                // dbg(h+i);
                // dbg(f[h+i][j][k]);
                // if(IN(ny,nx)) dbg(B[i][ny][nx]);

                if(IN(ny,nx) && f[h+i][ny][nx]==1 && B[i][j][k]==1) can_place = false;
            }
            if(!can_place) break;
            --h;
        }
        ++h;
        // dbg(h);

        vector<vvi> nf = f;
        rep(i,2)rep(j,2)rep(k,2){
            int ny = j+dy, nx = k+dx;
            if(IN(ny,nx) && B[i][j][k]==1){
                assert(nf[h+i][ny][nx]==0);
                nf[h+i][ny][nx] = 1;
            }
        }

        int add = 0;
        rep(i,2){
            bool one = true;
            rep(j,2)rep(k,2){
                if(nf[h+i][j][k]!=1) one = false;
            }
            if(one){
                rep(j,2)rep(k,2) nf[h+i][j][k] = 0;
                ++add;
            }
        }

        vector<vvi> NXF(H,vvi(2,vi(2)));
        int IDX = 0;
        rep(i,H){
            bool zero = true;
            rep(j,2)rep(k,2)if(nf[i][j][k]==1) zero = false;
            if(!zero){
                NXF[IDX++] = nf[i];
            }
        }

        ret = max(ret, dfs(dep+1, NXF) + add);
    }
    return ret;
}

int main(){
    int h;
    while(cin >>h >>n,h){
        vector<vvi> f(H,vvi(2,vi(2)));
        rep(i,h) f[i] = read_one();

        b = vector<bl>(n);
        rep(i,n){
            b[i] = bl(2);
            rep(j,2) b[i][j] = read_one();

            bool firstzero = true;
            rep(j,2)rep(k,2){
                if(b[i][0][j][k]==1) firstzero = false;
            }
            if(firstzero){
                swap(b[i][0],b[i][1]);
            }
        }

        cout << dfs(0,f) << endl;
    }
    return 0;
}
