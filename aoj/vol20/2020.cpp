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

bool isvowel(char c){
    return c=='a' || c=='i' || c=='u' || c=='e' || c=='o';
}

bool ismusei(char c){
    return c=='k' || c=='s' || c=='t' || c=='h' || c=='p';
}

vector<string> split(string s){
    vector<string> ret;
    int n = s.size();
    int i = 0;

    auto P = [&](int x){
        ret.pb(s.substr(i,x));
        i += x;
    };

    while(i<n){
        if(isvowel(s[i])) P(1);
        else{
            if(s[i]=='n'){
                if(i==n-1) P(1);
                else{
                    if(isvowel(s[i+1]) || s[i+1]=='\'') P(2);
                    else{
                        if(s[i+1]=='y') P(3);
                        else P(1);
                    }
                }
            }
            else{
                if(s[i+1]=='y') P(3);
                else{
                    if(s[i]==s[i+1]) P(1);
                    else P(2);
                }
            }
        }
    }

    return ret;
}

int main(){
    string s;
    while(cin >>s,(s!="#")){
        vector<string> v = split(s);
        // dbg(v);
        int V = v.size();

        string ans = "";
        bool prev = false;
        rep(i,V){
            string m = v[i];
            int M = m.size();

            // check
            bool bracket = false;
            bool upd = false;
            if(M>1){
                upd = true;
                if(m[M-1]=='i'|| m[M-1]=='u'){
                    if(i==V-1){
                        if(ismusei(m[0])) bracket = true;
                    }
                    else{
                        if(ismusei(m[0]) && ismusei(v[i+1][0])) bracket = true;
                    }
                }
                else if(m[M-1]=='a'|| m[M-1]=='o'){
                    char focus_v = m[M-1];

                    int end_idx = i;
                    while(end_idx<V){
                        bool ok = false;

                        int sz = v[end_idx].size();
                        if(sz>1){
                            char ts = v[end_idx][0];
                            char tv = v[end_idx][sz-1];
                            if(ismusei(ts) && tv==focus_v) ok = true;
                        }

                        if(ok) ++end_idx;
                        else break;
                    }

                    if(end_idx-i > 1) bracket = true;
                }
            }

            // output
            for(char c:v[i]){
                if(isvowel(c) && !prev && bracket){
                    ans += '(';
                    ans += c;
                    ans += ')';
                }
                else ans += c;
            }

            if(upd){
                if(prev) bracket = false;
                prev = bracket;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
