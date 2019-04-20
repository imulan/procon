#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    cin>>n;
    map<int,int> m;

    rep(i,n){
        rep(j,n){
            int x = i+1;
            int y = j+1;
            m[((x + x+y-1)*y/2)]++;
        }
    }

    set<int> s;
    for(auto p : m){
        if(s.count(p.second)==0){
            cout << p.second << "  " << p.first << endl;
            s.insert(p.second);
        }
    }


}
