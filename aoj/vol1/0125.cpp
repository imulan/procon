#include <iostream>
#include <cstdio>

using namespace std;

bool uru(int n){
	if( (n%4==0 && n%100!=0) || (n%4==0 && n%100==0 && n%400==0) )
		return true;
	else return false; 
}

int main(){
	while(1){
		int y1, y2, m1, m2, d1, d2;
		int d[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		long ans=0;
		
		cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
		if(y1==-1) break;
	
		if(y1==y2){
			if(m1==m2) ans=d2-d1;
			else{
				ans += d[m1-1]-d1+1;
				if(uru(y1) && m1==2) ++ans;
				++m1;
			
				while(m1!=m2){
					ans += d[m1-1];
					if(uru(y1) && m1==2) ++ans;
						
					++m1;
					//printf("%ld\n", ans);
				
				}
				ans+=d2-1;
			}
				
		}else{
			ans += d[m1-1]-d1+1;
			if(uru(y1) && m1==2) ++ans;
			++m1;	
			//printf("%ld\n", ans);
		
			while(m1<=12){
					ans += d[m1-1];
					if(uru(y1) && m1==2) ++ans;
						
					++m1;
					//printf("%ld\n", ans);
			}
			
			ans += d2-1;
			--m2;
			
			while(m2>=1){
					ans += d[m2-1];
					if(uru(y2) && m2==2) ++ans;
						
					//printf("%ld\n", ans);
					--m2;
			}
		
			for(int i=y1+1; i<=y2-1; ++i){
				if(uru(i)) ans += 366;
				else ans += 365;
			} 
	
		}
	
		printf("%ld\n", ans);
	
	}

	return 0;
}