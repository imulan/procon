#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;

const int N=23;
int f[N][8] = {
    {1,2,3,0,5,6,7,4},
    {2,3,0,1,6,7,4,5},
    {3,0,1,2,7,4,5,6},
    {4,7,6,5,0,3,2,1},
    {5,4,7,6,1,0,3,2},
    {6,5,4,7,2,1,0,3},
    {7,6,5,4,3,2,1,0},
    {0,3,7,4,1,2,6,5},
    {3,7,4,0,2,6,5,1},
    {7,4,0,3,6,5,1,2},
    {4,0,3,7,5,1,2,6},
    {1,5,6,2,0,4,7,3},
    {5,6,2,1,4,7,3,0},
    {6,2,1,5,7,3,0,4},
    {2,1,5,6,3,0,4,7},
    {0,4,5,1,3,7,6,2},
    {4,5,1,0,7,6,2,3},
    {5,1,0,4,6,2,3,7},
    {1,0,4,5,2,3,7,6},
    {3,2,6,7,0,1,5,4},
    {2,6,7,3,1,5,4,0},
    {6,7,3,2,5,4,0,1},
    {7,3,2,6,4,0,1,5},
};

vi normalize(const vi& v)
{
    vi ret(v);

    rep(i,N)
    {
        vi tmp(8);
        rep(j,8) tmp[j] = v[f[i][j]];

        ret = min(ret,tmp);
    }

    return ret;
}

int main()
{
    string s[8];
    while(cin >>s[0])
    {
        for(int i=1; i<8; ++i) cin >>s[i];

        vi a(8);

        map<string,int> col;
        int now=0;
        rep(i,8)
        {
            if(col.find(s[i]) == col.end()) col[s[i]]=now++;
            a[i] = col[s[i]];
        }

        sort(all(a));

        set<vi> octahedra;

        do {
            vi norm = normalize(a);
            octahedra.insert(norm);
        } while(next_permutation(all(a)));

        cout << octahedra.size() << '\n';
    }

    return 0;
}
