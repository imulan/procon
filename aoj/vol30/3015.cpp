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

bool pal(const string &s){
    int L = s.size();
    rep(i,L)if(s[i]!=s[L-1-i]) return false;
    return true;
}

int main(){
    int n,L;
    cin >>n >>L;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    set<string> S;
    map<string,int> ct;
    rep(i,n){
        S.insert(s[i]);
        ++ct[s[i]];
    }

    string a = "";
    for(string x:S){
        string rev = x;
        reverse(all(rev));
        while(1){
            if(x==rev){
                if(ct[x]>=2){
                    ct[x]-=2;
                    a += x;
                }
                else break;
            }
            else{
                if(ct[x]>=1 && ct[rev]>=1){
                    --ct[x];
                    --ct[rev];
                    a += x;
                }
                else break;
            }
        }
    }

    string c = "";
    for(const auto &p:ct){
        if(p.se>0){
            if(pal(p.fi)){
                c = p.fi;
                break;
            }
        }
    }

    string b = a;
    reverse(all(b));
    cout << a+c+b << endl;
    return 0;
}
