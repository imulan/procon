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

struct Player{
    int rate,l,r,t;
    bool rated;
    int col;

    Player(){}
    Player(int _rate, int _l, int _r, int _t, string _rated, string color)
    {
        rate = _rate;
        l = _l;
        r = _r;
        t = _t;
        rated = (_rated=="rated");

        if(color=="white") col = 1;
        else if(color=="black") col = -1;
        else col = 0;
    }

    void show()
    {
        printf(" %d %d %d %d %d %d\n", rate,l,r,t,rated,col);
    }
};

int match(Player p, Player q)
{
    if(p.rated != q.rated) return 0;
    if(p.t != q.t) return 0;

    if((p.col==0&&q.col==0) || (p.col==1&&q.col==-1) || (p.col==-1&&q.col==1))
    {
        if(q.l<=p.rate && p.rate<=q.r && p.l<=q.rate && q.rate<=p.r) return 1;
    }
    return 0;
}

void solve()
{
    int n;
    cin >>n;
    vector<Player> p(n);
    rep(i,n)
    {
        int R,MIN,MAX,T;
        string RATED,COLOR;
        cin >>R >>MIN >>MAX >>T >>RATED >>COLOR;
        p[i] = Player(R,MIN,MAX,T,RATED,COLOR);
    }

    // rep(i,n) p[i].show();

    vector<bool> ave(n);
    rep(i,n)
    {
        bool found = false;
        rep(j,i)if(ave[j])
        {
            if(match(p[i],p[j]))
            {
                printf("%d\n", j+1);
                found = true;
                ave[j] = false;
                break;
            }
        }

        if(!found)
        {
            printf("wait\n");
            ave[i] = true;
        }
    }
}

int main()
{
    int T;
    cin >>T;
    while(T--) solve();
    return 0;
}
