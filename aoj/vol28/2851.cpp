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

int r,c,s;
int a[10][10];
bool ok = false;

void dfs(int d){
    if(d == -1) return;
    bool found = false;

    // printf(" ----d %d\n",d);
    // rep(i,r){
    //     rep(j,c) printf(" %d",a[i][j]);
    //     printf("\n");
    // }

    rep(i,r){
        rep(j,c){
            int z = 0;
            for(int k=j; k<c; ++k){
                z += a[i][k];
                if(z>s) found = true;
            }
        }

        if(found){
            rep(j,c){
                a[i][j] = -a[i][j];
                dfs(d-1);
                a[i][j] = -a[i][j];
            }
            break;
        }
    }

    if(!found){
        rep(i,c){
            rep(j,r){
                int z = 0;
                for(int k=j; k<r; ++k){
                    z += a[k][i];
                    if(z>s) found = true;
                }
            }

            if(found){
                rep(j,r){
                    a[j][i] = -a[j][i];
                    dfs(d-1);
                    a[j][i] = -a[j][i];
                }
                break;
            }
        }
    }

    if(!found) ok = true;
}

int main(){
    int K;
    cin >>r >>c >>K >>s;
    rep(i,r)rep(j,c) cin >>a[i][j];

    dfs(K);
    cout << (ok?"Yes":"No") << endl;
    return 0;
}
