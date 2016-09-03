#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long n, h;
	long a, b, c, d, e;
	
	
	scanf(" %ld %ld",&n,&h);
	scanf(" %ld %ld %ld %ld %ld",&a,&b,&c,&d,&e);	
	
	long ans=n*a;
	//普通の食事をする回数i
	for(long i=0; i<=n; ++i){
		//質素な食事の回数x
		long x = ((n-i)*e-i*b-h)/(d+e) +1;
		//if( ((n-i)*e-i*b-h)%(d+e) != 0) x++;
		if((n-i)*e-i*b-h<0) x=0;
		
		long tmp=a*i+c*x;
		if(tmp<ans) ans=tmp;
		
		//printf("i=%ld, x=%ld,  tmp=%ld\n", i, x, tmp);
		//if(h+i*b+x*d-(n-i-x)*e<=0) printf("error!!!\n");
	}
	
	printf("%ld\n", ans);
}