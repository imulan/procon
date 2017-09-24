#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) (x).begin() (x).end()

int main()
{
    string s;
    cin>>s;

    int n = s.size();
    int cnt=0;
    rep(i,n){
        if(s[i]=='(') cnt++;
        else if(s[i]==')') cnt--;
        else cout << cnt << endl;
    }

}
