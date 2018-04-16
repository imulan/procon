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

bool vowel(char c){
    string v = "aeiuoy";
    rep(i,v.size())if(v[i]==c) return true;
    return false;
}

int main(){
    int n;
    string s;
    cin >>n >>s;

    while(1){
        bool update = false;
        int S = s.size();
        rep(i,S-1){
            if(vowel(s[i]) && vowel(s[i+1])){
                s = s.substr(0,i+1)+s.substr(i+2);
                update = true;
                break;
            }
        }

        if(!update) break;
    }

    cout << s << endl;
    return 0;
}
