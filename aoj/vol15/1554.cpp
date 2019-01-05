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

bool is_uruu(int y){
    if(y%400 == 0) return true;
    if(y%100 == 0) return false;
    if(y%4 == 0) return true;
    return false;
}

const int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    ll p = 0, d = 0;
    rep(i,400){
        for(int j=1; j<=12; ++j){
            if((d+12)%7 == 6) ++p;

            int add = m[j];
            if(j==2 && is_uruu(i)) ++add;
            d += add;
        }
    }

    ll y1,y2,m1,d1,m2,d2;
    cin >>y1 >>m1 >>d1 >>y2 >>m2 >>d2;

    ++d2;
    int lim = m[m2];
    if(is_uruu(y2) && m2==2) ++lim;
    if(d2 == lim){
        d2 = 1;
        ++m2;
        if(m2 == 13){
            m2 = 1;
            ++y2;
        }
    }

    auto F = [&](ll Y, ll M, ll D){
        ll ret = p*(Y/400);
        Y %= 400;

        ll now = 0;
        rep(i,400){
            for(int j=1; j<=12; ++j){
                if(i==Y && j==M){
                    if(13 < D){
                        if( (now+12)%7 == 6 ) ++ret;
                    }
                    return ret;
                }

                if( (now+12)%7 == 6 ) ++ret;

                int add = m[j];
                if(j==2 && is_uruu(i)) ++add;
                now += add;
            }
        }
    };

    cout << F(y2,m2,d2) - F(y1,m1,d1) << endl;
    return 0;
}
