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
using P = pair<pi,int>;

const double EPS = 1e-8;

bool comp(const P pp, const P qq){
    pi p = pp.fi, q = qq.fi;
    if(p.se == 0) return true;
    if(q.se == 0) return false;

    return p.fi*q.se > q.fi*p.se;
}

void solve(istream &fin, ostream &fout){
    int n,A,B;
    fin >>n >>A >>B;

    vector<int> g(n),a(n),b(n);
    rep(i,n) fin >>g[i] >>a[i] >>b[i];

    vector<P> v(n);
    rep(i,n) v[i] = { {a[i],b[i]}, i};
    sort(all(v), comp);

    vector<double> ans(n,0);
    double aa = 0, bb = 0;
    rep(i,n){
        int idx = v[i].se;

        double ss;
        if(b[idx] == 0) ss = g[idx];
        else ss = min( (B-bb)/b[idx], (double)g[idx] );

        ans[idx] = ss;
        aa += ss*a[idx];
        bb += ss*b[idx];
    }

    if(aa < A-EPS){
        fout << "-1 -1" << "\n";
        return;
    }

    fout << setprecision(10);
    fout << aa << " " << bb << "\n";
    rep(i,n) fout << ans[i] << " \n"[i==n-1];
}

int main(){

    #ifdef ONLINE_JUDGE
    ifstream ifs("burrito.in");
    ofstream ofs("burrito.out");
    solve(ifs, ofs);
    ifs.close();
    ofs.close();
    #else
    solve(cin, cout);
    #endif

    return 0;
}
