#include <cstdio>
#include <iostream>
using namespace std;

//うるう年判定
bool uru(int y){
	bool ret = false;
	
	if(y%4==0){
		ret=true;
		if(y%100==0){
			ret=false;	
			if(y%400==0) ret = true;
		}
	}
	
	return ret;
}

int main(){
	int a, b;
	cin >> a >> b;
	
	int ans=0;
	
	if(b-a<1000){		
		for(int i=a; i<=b; ++i){
			if(uru(i)) ++ans;	
		}
	}
	else{
		//aを400で割り切れるところまでつめる
		while(a%400!=1){
			if(uru(a)) ans++;
			a++;	
		}
		
		//bを400で割り切れるところまでつめる
		while(b%400!=0){
			if(uru(b)) ans++;
			b--;	
		}
		
		//printf(" now a=%d, b=%d\n", a, b);
		
		ans += (b-a+1)/400*97;			
	}
	
	cout << ans << endl;
}