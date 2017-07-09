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

int vec[30][30];
int n,m;

bool solve(){
    rep(i,n){
        int pre = -1;
        rep(j,m)if(vec[i][j]!=j){
            if(pre==-1) pre = j;
            else {
                if(pre == vec[i][j]) pre = 30;
                else return false;
            }
        }
    }
    return true;
}

bool sol()
{
    cin>>n>>m;
    rep(i,n)rep(j,m) cin>>vec[i][j], vec[i][j]--;

    if(solve()) return true;
    rep(i,m) rep(j,i){
        rep(k,n) swap(vec[k][i], vec[k][j]);
        if(solve()) return true;
        rep(k,n) swap(vec[k][i], vec[k][j]);
    }

    return false;
}

int main()
{
    if(sol()) cout << "YES" << endl;
    else cout << "NO" << endl;
}
