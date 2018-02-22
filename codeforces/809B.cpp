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

int n,k;

int ct = 0;
bool ask(int x, int y){
    if(ct == 60) assert(false);

    cout << 1 << " " << x << " " << y << endl;
    cout << flush;

    ++ct;

    string res;
    cin >>res;
    return res=="TAK";
}

int findone(int l, int r){
    if(!(l<=r)) return -1;

    while(r-l>1){
        int m = (l+r)/2;

        if(ask(m,m+1)) r = m;
        else l = m;
    }

    if(ask(l,r)) return l;
    else return r;
}

int main(){
    cin >>n >>k;

    int ax = -1, ay = -1;
    ax = findone(1,n);
    // dbg(ax);

    int L=1, R=ax-1;
    if(R-L>=0){
        int c = findone(L,R);
        if(ask(c,ax)) ay = c;
    }

    if(ay==-1){
        L=ax+1;
        R=n;
        if(R-L>=0){
            int c = findone(L,R);
            if(ask(c,ax)) ay = c;
        }
    }

    // answer
    assert(ax!=-1 && ay!=-1 && ax!=ay);
    cout << 2 << " " << ax << " " << ay << endl;
    cout << flush;
    return 0;
}
