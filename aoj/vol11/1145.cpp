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

string s;
int x;

int ct;
char c;

int idx;

string now;

void num();
void read();

void num(){
    int n = 0;
    while(idx<s.size() && isdigit(s[idx])){
        n = n*10 + s[idx]-'0';
        ++idx;
    }

    if(s[idx]=='('){
        ++idx;
        int start = idx;

        rep(i,n){
            idx = start;
            read();
            if(c != '0') return;
        }

        assert(s[idx]==')');
        ++idx;
    }
    else{
        rep(i,n){
            now += s[idx];
            if(ct == x){
                c = s[idx];
                return;
            }
            ++ct;
        }
        ++idx;
    }
}

void read(){
    if(c != '0') return;
    if(idx >= s.size()) return;

    if(isdigit(s[idx])) num();
    if(isupper(s[idx])){
        now += s[idx];
        if(ct == x){
            c = s[idx];
            return;
        }

        // dbg(ct);
        ++ct;
        ++idx;
    }
    if(s[idx]==')') return;

    read();
}

int main(){
    while(cin >>s >>x,(s!="0")){
        c = '0';
        idx = 0;
        ct = 0;

        now = "";

        read();
        // dbg(now);
        cout << c << endl;
    }
    return 0;
}
