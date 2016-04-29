#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n;		
		scanf(" %d", &n);
		if(n==0) break;
		
		int a=0, b=0, c=0;
		int aok=0, bok=0, cok=0;
		
		for(int i=0; i<n; ++i){
			int h, m, M;
			
			scanf(" %d:%d %d", &h, &m, &M);
			if(m>M) M+=60;
			
			if(11<=h && h<=14){
				a++;
				if(M-m<=8) aok++;	
			}
			else if(18<=h && h<=20){
				b++;
				if(M-m<=8) bok++;	
			}
			else if(h==0 || h==1 || (21<=h && h<=23)){
				c++;	
				if(M-m<=8) cok++;	
			}		
				
		}
		
		printf("lunch ");
		if(a==0) printf("no guest\n");
		else printf("%d\n", aok*100/a);

		printf("dinner ");
		if(b==0) printf("no guest\n");
		else printf("%d\n", bok*100/b);

		printf("midnight ");
		if(c==0) printf("no guest\n");
		else printf("%d\n", cok*100/c);
	}
}