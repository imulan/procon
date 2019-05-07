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

int main(){
    string s;
    cin >>s;
    int n = s.size();

    int star = -1;
    rep(i,n)if(s[i]=='*') star = i;

    int ans = 0;
    stack<int> st;
    rep(i,n){
        if(s[i]=='*') continue;

        if(s[i]=='(') st.push(i);
        else{
            int l = st.top();
            st.pop();
            ans += (l<star && star<i);
        }
    }
    cout << ans << endl;
    return 0;
}
