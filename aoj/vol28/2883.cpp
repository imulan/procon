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

string s,p;

int H(int &idx){
    if(s[idx]=='['){
        ++idx;
        char op = s[idx];
        ++idx;

        int val=-1;
        if(op=='+') val = H(idx)|H(idx);
        else if(op=='*') val = H(idx)&H(idx);
        else if(op=='^') val = H(idx)^H(idx);
        else assert(false);

        assert(s[idx]==']');
        ++idx;

        return val;
    }
    else{
        int letter = s[idx]-'a';
        ++idx;
        assert(0<=letter && letter<=3);
        return p[letter]-'0';
    }
}

int main(){
    while(cin >>s,(s!=".")){
        cin >>p;

        int idx = 0;
        int v = H(idx);

        int ct = 0;
        rep(i,10000){
            int t = i;
            rep(j,4){
                p[3-j] = t%10+'0';
                t/=10;
            }
            idx = 0;
            if(H(idx) == v) ++ct;
        }

        cout << v << " " << ct << endl;
    }
    return 0;
}
