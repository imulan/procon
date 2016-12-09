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

vi p,m;
int P,M;
int z=0;

int Dry()
{
    sort(all(m),greater<int>());
    sort(all(p),greater<int>());

    int ret=0;
    int z_rem=z;

    int p_idx=0;
    rep(m_idx,M)
    {
        while(p_idx<P && m[m_idx]<=p[p_idx]) ++p_idx;

        if(p_idx==P && z_rem==0)
        {
            ret+=(M-m_idx)/2;
            break;
        }

        if(p_idx==P)
        {
            --z_rem;
            ++ret;
        }
        else
        {
            ++ret;
            ++p_idx;
        }
    }

    return ret;
}

int Wet()
{
    swap(p,m);
    swap(P,M);

    int ret = Dry();

    swap(p,m);
    swap(P,M);

    return ret;
}

int Moist()
{
    sort(all(m));
    sort(all(p));

    int ret=z/2;

    int p_idx=0,m_idx=0;
    while(p_idx<P && m_idx<M)
    {
        if(p[p_idx] < m[m_idx]) ++p_idx;
        else if(p[p_idx] > m[m_idx]) ++m_idx;
        else
        {
            ++p_idx;
            ++m_idx;
            ++ret;
        }
    }

    return ret;
}

int main()
{
    int n;
    scanf(" %d", &n);

    rep(i,2*n)
    {
        int a;
        scanf(" %d", &a);
        if(a>0) p.pb(a);
        else if(a<0) m.pb(-a);
        else ++z;
    }

    P=p.size();
    M=m.size();
    printf("%d %d %d\n", Dry(), Wet(), Moist());
    return 0;
}
