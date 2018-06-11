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

string solve(){
    int n,p;
    string s;
    cin >>n >>p >>s;

    rep(i,n){
        int j = i+p;
        if(j>=n) break;

        if(s[i]!='.' && s[j]!='.' && s[i]!=s[j]){
            rep(k,n)if(s[k]=='.') s[k]='0';
            return s;
        }

        if(s[i]=='.'){
            if(s[j]=='0') s[i] = '1';
            else if(s[j]=='1') s[i] = '0';
            else{
                s[i] = '0';
                s[j] = '1';
            }

            rep(k,n)if(s[k]=='.') s[k]='0';
            return s;
        }
        if(s[j]=='.'){
            if(s[i]=='0') s[j] = '1';
            else if(s[i]=='1') s[j] = '0';
            else{
                s[i] = '0';
                s[j] = '1';
            }

            rep(k,n)if(s[k]=='.') s[k]='0';
            return s;
        }
    }

    return "No";
}

int main(){
    cout << solve() << endl;
    return 0;
}
