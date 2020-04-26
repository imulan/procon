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

using ull = unsigned long long;
using vi = vector<int>;

const vector<vi> NG(1,vi(1,-1));
const int B = 64;

int main(){
    int n;
    cin >>n;

    vector<int> s(n),t(n);
    vector<ull> u(n),v(n);
    rep(i,n) cin >>s[i];
    rep(i,n) cin >>t[i];
    rep(i,n) cin >>u[i];
    rep(i,n) cin >>v[i];

    auto calc = [&](const vi &row, const vi &col){
        vector<vi> r(n, vi(n,-1));

        vector<int> fr,fc;
        // row
        rep(i,n){
            int ALL = -1;
            if((s[i]^row[i])==1) ALL = row[i];

            if(ALL == -1) fr.pb(i);
            else rep(j,n) r[i][j] = ALL;
        }
        // col
        rep(i,n){
            int ALL = -1;
            if((t[i]^col[i])==1) ALL = col[i];

            if(ALL == -1) fc.pb(i);
            else{
                rep(j,n){
                    if(r[j][i]!=-1 && r[j][i]!=ALL) return NG;
                    r[j][i] = ALL;
                }
            }
        }

        int R = fr.size(), C = fc.size();
        if(R>=2 && C>=2){
            rep(i,R)rep(j,C) r[fr[i]][fc[j]] = (i+j)%2;
        }
        else if(R == 1){
            int ri = fr[0];
            for(int i:fc){
                vector<int> ct(2);
                rep(j,n)if(r[j][i] != -1) ++ct[r[j][i]];

                int v = s[ri];
                if(ct[col[i]]==0) v = col[i];
                r[ri][i] = v;
            }
        }
        else if(C == 1){
            int ci = fc[0];
            for(int i:fr){
                vector<int> ct(2);
                rep(j,n)if(r[i][j] != -1) ++ct[r[i][j]];

                int v = t[ci];
                if(ct[row[i]]==0) v = row[i];
                r[i][ci] = v;
            }
        }

        // check
        rep(i,n){
            if(s[i]==0){
                int val = 1;
                rep(j,n) val &= r[i][j];
                if(val != row[i]) return NG;
            }
            else{
                int val = 0;
                rep(j,n) val |= r[i][j];
                if(val != row[i]) return NG;
            }
        }
        rep(i,n){
            if(t[i]==0){
                int val = 1;
                rep(j,n) val &= r[j][i];
                if(val != col[i]) return NG;
            }
            else{
                int val = 0;
                rep(j,n) val |= r[j][i];
                if(val != col[i]) return NG;
            }
        }

        return r;
    };

    vector<vector<ull>> a(n, vector<ull>(n));
    rep(b,B){
        vi row(n), col(n);
        rep(i,n) row[i] = u[i]>>b&1;
        rep(i,n) col[i] = v[i]>>b&1;

        vector<vi> m = calc(row,col);
        if(m == NG){
            cout << -1 << "\n";
            return 0;
        }

        rep(i,n)rep(j,n)if(m[i][j]) a[i][j] |= (1ULL<<b);
    }

    rep(i,n)rep(j,n) cout << a[i][j] << " \n"[j==n-1];
    return 0;
}
