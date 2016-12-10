#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

string solve()
{
    int n;
    set<string> s;
    cin >>n;
    rep(i,n)
    {
        string used;
        cin >>used;
        s.insert(used);
    }

    if(n>=129600) return "NO";

    string x="bgmnr", y="aaeiuu";
    do{
        rep(i,6)
        {
            string z="";
            char sel=y[i];
            rep(j,6)if(j!=i) z+=y[j];

            do{
                // sel として選んだ母音を入れる位置
                rep(j,6)
                {
                    string name="";
                    if(j==0) name+=sel;
                    rep(k,5)
                    {
                        name+=x[k];
                        name+=z[k];
                        if(j==k+1) name+=sel;
                    }

                    if(s.find(name) == s.end()) return name;
                }
            }while(next_permutation(all(z)));
        }
    }while(next_permutation(all(x)));

    return "NO";
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    cout << solve() << '\n';
    return 0;
}
