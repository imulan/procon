#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

const ll MOD=1e9+7;

ll gcd(ll x, ll y){
  if(x<y) swap(x,y);
	while(x%y!=0){
		long z=x%y;
		x=y;
		y=z;
	}

	return y;
}

int main(int argc, char const *argv[]) {
  ll n, k;
  cin >>n >>k;

  vector<ll> g(k+1); //iとkのgcd

  for(ll i=1; i<=k; ++i) g[i] = gcd(i,k);

  ll q=n/k; //商
  ll r=n%k; //余り
  if(r==0){
    r=k;
    --q;
  }
  //printf(" q= %lld, r= %lld\n", q, r);

  ll ans=0;
  //gcd(i,k) = gcd(i%k, k)という性質を利用
  for(ll i=1; i<=k; ++i){ //kの剰余がiのものを計算する
    //printf("g[%lld] = %lld\n", i, g[i]);
    if(i>r){
      ans+=((i+(q-1)*k+i)*q/2) *k/g[i];
      //cout << i << " , " << (q-1)*k+i << endl;
    }
    else{
      ans+=((i+q*k+i)*(q+1)/2) *k/g[i];
      //cout << i << " , " << q*k+i << endl;
    }
    ans %= MOD;
    //cout <<" " <<  ans << endl;
  }

  cout << ans << endl;

  return 0;
}
