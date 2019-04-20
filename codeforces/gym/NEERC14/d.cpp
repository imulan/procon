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
    double d,l,r,t,h;
    fin >>d >>l >>r >>t >>h;

    double theta = asin(t/l);
    double tt = t*cos(theta);

    double ans = 0;

    if(h < tt){


    }
    else if(h < t){


    }
    else{


    }

    fout << setprecision(10) << ans << "\n";
}

int main(){

    #ifdef ONLINE_JUDGE
    ifstream ifs("damage.in");
    ofstream ofs("damage.out");
    solve(ifs, ofs);
    ifs.close();
    ofs.close();
    #else
    solve(cin, cout);
    #endif

    return 0;
}
