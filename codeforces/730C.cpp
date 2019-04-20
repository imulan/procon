#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
/*
//#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
*/

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
/*
//#if __cplusplus >= 201103L
#include <array>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
*/
using namespace std;
#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl

#define uni(x) x.erase(unique(all(x)),x.end())
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 1000
#define M_INF 1000000000
ll n,m,v,i,x,y,q,w;
void solve(){
   // cin.tie(0);
  // ios::sync_with_stdio(false);
  // cin>>n>>m;
  scanf("%d%d",&n,&m);
  std::vector<vector<int> > v(n);
  rep(i,m){
    scanf("%ld%ld",&x,&y);
    // cin>>x>>y;
    x--;y--;
    v[x].pb(y);
    v[y].pb(x);
  }

    cin>>w;
    std::vector<PPI> store(w);
    rep(i,w) {
        int c,k,p;
        scanf("%d%d%d",&c,&k,&p);
        // cin>>c>>k>>p;
        c--;
        store[i] = PPI(P(p,k),c);
    }
    sort(all(store));

      // cin>>q;
    scanf("%d",&q);
    ll g,r,a;
    const ll NG = 5005;
    rep(i,q){
      // cin>>g>>r>>a;
      scanf("%lld%lld%lld",&g,&r,&a);
      g--;

        vector<int> edge_num(n,INF);
        priority_queue<P,vector<P>,greater<P> > que;
        // 今　時間　前
        edge_num[g] = 0;
        que.push(P(0,g));
        while(!que.empty()){
            P l = que.top();
            que.pop();
            if(l.fi > edge_num[l.se]) continue;
            rep(j,v[l.se].size()){
                if(edge_num[v[l.se][j]] > l.fi + 1){
                edge_num[v[l.se][j]] = l.fi + 1;
                que.push(P(l.fi + 1,v[l.se][j]));
                }
            }
        }

      ll L = -1, R = NG;
      while(L + 1 < R){
        ll mid = (L+R) / 2;

        ll money = 0;
        ll shovel = 0;
        rep(j,w){
          ll price = store[j].fi.fi, num = store[j].fi.se, city = store[j].se;
          if(edge_num[city]<=mid){
            if(shovel+num<=r) {
              shovel += num;
              money += num*price;
            } else {
              money += price*(r-shovel);
              shovel = r;
              break;
            }
          }
        }
        if(money <= a && shovel >= r) R=mid;
        else L=mid;
      }

      if(R==NG) R=-1;
      printf("%lld\n",R);
    }

}

int main(){
  solve();
  return 0;
}
