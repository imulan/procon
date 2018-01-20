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

bool is_operator(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

int main(){
    string s;
    cin >>s;
    int S = s.size();

    string ans = "";
    stack<char> op;

    int i=0;
    while(i<S){
        if(is_operator(s[i])){
            op.push(s[i]);
            i+=2;
            ans += '(';
        }
        else if(isdigit(s[i])){
            while(i<S && isdigit(s[i])) ans += s[i++];
        }
        else if(s[i]==','){
            ans += op.top();
            ++i;
        }
        else if(s[i]==')'){
            op.pop();
            ans += ')';
            ++i;
        }
        else assert(false);
    }

    cout << ans << endl;
    return 0;
}
