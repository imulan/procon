#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	int n;
	long x, a[32];
	long long ans=0;
		
	scanf(" %d %ld", &n, &x);
	for(int i=0; i<n; ++i) scanf(" %ld", &a[i]);
	
	//半分全列挙
	long p[100000], q[100000];
	long pp=0, qq=0;
	int half=n/2;
	
	for(long i=(1<<half)-1; i>=0; --i){
		p[pp]=0;
		for(int j=0; j<half; ++j){
			if((i>>j) & 1){
				p[pp]+=a[j];
			}
		}
		++pp;
	}
	sort(p, p+pp);
	
	for(long i=(1<<(n-half))-1; i>=0; --i){
		q[qq]=0;
		for(int j=0; j<n-half; ++j){
			if((i>>j) & 1){
				q[qq]+=a[half+j];
			}
		}
		++qq;
	}
	sort(q, q+qq);
	
	//for(long i=0; i<pp; ++i) printf("p[%ld]=%ld\n", i, p[i]);
	//for(long i=0; i<qq; ++i) printf("q[%ld]=%ld\n", i, q[i]);
	
	for(long i=0; i<pp; ++i){ //各pに対して該当するqがあるか
		long target=x-p[i];
		if(target<0) break;
		//二分探索
		long left=0, right=qq;
		long center;
		while(left<right){
			center=(left+right)/2;
			if(q[center]>target){
				right=center;
			}
			else if(q[center]<target){
				left=center+1;
			}
			else break;
			
			//printf("  c=%ld  l=%ld, r=%ld\n", center, left, right);
		}
		
		left=center;
		right=center;
		while(left < qq && q[left]==target) left++;
		while(right>=0 && q[right]==target) right--;
		
		
		//printf("c=%ld  l=%ld, r=%ld\n", center, left, right);
		
		if(left!=right) ans+=left-right-1;
		//cout << ans << endl;
	}
	
	
	cout << ans << endl;
}