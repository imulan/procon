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
using P = pair<pi,pi>;

void solve(istream &fin, ostream &fout){
    int n,m;
    fin >>n >>m;

    vector<P> ans;
    for(int i=2; i<=n; i+=2){
        ans.pb({ {i,1}, {i,m} });
    }

    for(int i=2; i<=m; i+=2){
        ans.pb({ {1,i},{n,i} });
    }

    fout << ans.size() << "\n";
    for(auto p:ans) fout << p.fi.fi << " " << p.fi.se << " " << p.se.fi << " " << p.se.se << "\n";
}

int main(){

    #ifdef ONLINE_JUDGE
    ifstream ifs("alter.in");
    ofstream ofs("alter.out");
    solve(ifs, ofs);
    ifs.close();
    ofs.close();
    #else
    solve(cin, cout);
    #endif

    return 0;
}
