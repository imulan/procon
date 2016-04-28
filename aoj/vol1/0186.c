//TLE

#include <stdio.h>

int main(void){
	while(1){
		long n, m, a, b, c;
		scanf(" %ld",&n);
		if(n==0) break;	
		
		scanf(" %ld %ld %ld %ld", &m, &a, &b, &c);
	
		long jid = c; //地鶏,a円
		long nom = (n-jid<0) ? 0:(n-jid); //ふつう,b円
		int flag=0;
		
		printf("%ld %ld\n", jid, nom);
		while(1){
			if(jid<=0) {flag=1; break;}
			if(m >= jid*a + nom*b) break; 
			jid--;
		}
		printf("%ld %ld\n", jid, nom);
		
		if(flag==0){
		
			if(jid + nom >= n){
				while(1){
					nom++;
					if(m < jid*a + nom*b) {
						nom--;
						break;				
					}	
				}
			}
			else{
				while(1){
					if(jid<=0) {flag=1; break;}
					if(jid + nom >= n) break;
				
					while(1){
						if(jid + nom >= n) break;
						jid--;
						while(1){
							if(m < jid*a + nom*b) {
								nom--;
								break;				
							}		
							nom++;
						}
					
					}
				}
			}
			
		}
		
		if(flag==0) printf("%ld %ld\n", jid, nom);
		else printf("NA\n");
		
	}

	return 0;
}