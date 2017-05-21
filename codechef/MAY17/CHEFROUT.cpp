#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

string check(string x)
{
    if(x=="C" || x=="E" || x=="S"|| x=="CE"|| x=="ES"|| x=="CS" || x=="CES") return "yes";
    return "no";
}

int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        string s;
        cin >>s;
        int n = s.size();

        string x="";
        int idx=0;
        while(idx<n)
        {
            char f = s[idx];
            x += f;
            while(idx<n && s[idx]==f) ++idx;
        }

        cout << check(x) << endl;
    }
    return 0;
}
