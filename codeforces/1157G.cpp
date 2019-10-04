#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

void OK(const vector<int> &r, const vector<int> &c){
    cout << "YES\n";
    for(int i:r) cout << i;
    cout << "\n";
    for(int i:c) cout << i;
    cout << "\n";
}

int main(){
    int h,w;
    cin >>h >>w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h)rep(j,w) cin >>a[i][j];

    auto check = [&](const vector<vector<int>> &m){
        // dbg(m);
        int p = 0;
        rep(i,h)rep(j,w){
            if(p > m[i][j]) return false;
            p = m[i][j];
        }
        return true;
    };

    rep(first_row,2){
        // dbg(first_row);
        vector<int> r,c;
        vector<vector<int>> m;

        // first row: all 1
        r = vector<int>(h);
        c = vector<int>(w);
        m = a;
        if(first_row){
            r[0] = 1;
            rep(i,w) m[0][i] = !m[0][i];
        }
        rep(i,w)if(m[0][i]==0){
            c[i] = 1;
            rep(j,h) m[j][i] = !m[j][i];
        }
        for(int i=1; i<h; ++i)if(m[i][0]==0){
            r[i] = 1;
            rep(j,w) m[i][j] = !m[i][j];
        }
        if(check(m)){
            OK(r,c);
            return 0;
        }

        // first row: all 0
        r = vector<int>(h);
        c = vector<int>(w);
        m = a;
        if(first_row){
            r[0] = 1;
            rep(i,w) m[0][i] = !m[0][i];
        }
        rep(i,w)if(m[0][i]==1){
            c[i] = 1;
            rep(j,h) m[j][i] = !m[j][i];
        }
        // at most one can have both 0 and 1
        int ridx = -1;
        for(int i=1; i<h; ++i){
            int ct = 0;
            rep(j,w) ct += m[i][j];
            if(ct!=0 && ct!=w) ridx = i;
        }
        for(int i=1; i<h; ++i){
            if(i<=ridx){
                if(m[i][0]==1){
                    r[i]=1;
                    rep(j,w) m[i][j] = !m[i][j];
                }
            }
            else{
                if(m[i][0]==0){
                    r[i]=1;
                    rep(j,w) m[i][j] = !m[i][j];
                }
            }
        }
        if(check(m)){
            OK(r,c);
            return 0;
        }

        // first row: 0 .. 0 1 .. 1
        // otherwise, all must be one
        rep(z,w-1){
            r = vector<int>(h);
            c = vector<int>(w);
            m = a;
            if(first_row){
                r[0] = 1;
                rep(i,w) m[0][i] = !m[0][i];
            }

            rep(i,z+1)if(m[0][i]==1){
                c[i] = 1;
                rep(j,h) m[j][i] = !m[j][i];
            }
            for(int i=z+1; i<w; ++i)if(m[0][i]==0){
                c[i] = 1;
                rep(j,h) m[j][i] = !m[j][i];
            }

            for(int i=1; i<h; ++i)if(m[i][0]==0){
                r[i] = 1;
                rep(j,w) m[i][j] = !m[i][j];
            }

            if(check(m)){
                OK(r,c);
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;
}
