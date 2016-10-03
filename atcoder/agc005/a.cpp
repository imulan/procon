#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    string s;
    cin >>s;

    stack<char> st;
    rep(i,s.size())
    {
        if(!st.empty() && st.top()=='S' && s[i]=='T') st.pop();
        else st.push(s[i]);
    }

    cout << st.size() << endl;
    return 0;
}
