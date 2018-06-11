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

using P = pair<int,char>;

int main(){
    int a,b,c,d;
    cin >>a >>b >>c >>d;

    int n = 50, m = 50;
    vector<string> f(n);
    rep(i,n/2){
        f[i] = string(n/2,'A') + string(n/2,'B');
        f[n/2+i] = string(n/2,'C') + string(n/2,'D');
    }

    int y=1, x=m/2+1;
    while(a>1){
        f[y][x] = 'A';

        x += 2;
        if(x>=m){
            y += 2;
            x = m/2+1;
        }
        --a;
    }

    y=n/2+1;
    x=1;
    while(b>1){
        f[y][x] = 'B';

        x += 2;
        if(x>=m/2){
            y += 2;
            x = 1;
        }
        --b;
    }

    y=n/2+1;
    x=m/2+1;
    while(c>1){
        f[y][x] = 'C';

        x += 2;
        if(x>=m){
            y += 2;
            x = m/2+1;
        }
        --c;
    }

    y=1;
    x=1;
    while(d>1){
        f[y][x] = 'D';

        x += 2;
        if(x>=m/2){
            y += 2;
            x = 1;
        }
        --d;
    }

    cout << n << " " << m << endl;
    rep(i,n) cout << f[i] << endl;
    return 0;
}
