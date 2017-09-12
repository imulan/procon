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

int main()
{
    string s;
    cin >>s;

    int n = s.size();
    vector<int> r(26,-1);
    rep(i,n) r[s[i]-'a'] = i;

    string ans = "";
    int f = 0;
    stack<char> st;
    rep(i,n)
    {
        while(r[f]<i) ++f;

        while(!st.empty() && st.top()<='a'+f)
        {
            ans += st.top();
            st.pop();
        }

        st.push(s[i]);
    }
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    cout << ans << endl;
    return 0;
}
