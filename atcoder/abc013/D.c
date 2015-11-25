#include <stdio.h>

typedef struct {
	long num;
	long k;
}nums;

void QSort(nums x[ ], long left, long right)
{
    long i, j;
    long pivot;

    i = left;                     
    j = right;                   
    pivot = x[(left + right) / 2].k; 
    
    while (1) {                  

        while (x[i].k < pivot)  
            i++;                   
            
        while (pivot < x[j].k)      
             j--;                   
        if (i >= j)                
            break;               
            
        nums temp;
   		temp = x[i];
   		x[i] = x[j];
    	x[j] = temp;
    	
    	i++;       
    	j--;
    }

    if (left < i - 1)              /* 基準値の左に 2 以上要素があれば */
        QSort(x, left, i - 1);     /* 左の配列を Q ソートする */
    if (j + 1 <  right)            /* 基準値の右に 2 以上要素があれば */
        QSort(x, j + 1, right);    /* 右の配列を Q ソートする */
}

nums p[200000] ,law[200000], old[200000];

int main(void){
	long n, m, d, i, j;
	long a;
	
	scanf("%ld %ld %ld", &n, &m, &d);
	
	//１回目処理
	for(i=0; i<n; i++) {
		p[i].num = i+1;
		p[i].k = i+1;
	}
	
	for(i=0; i<m; i++) {
		scanf(" %ld", &a);
		
		long tmp = p[a-1].k;
		p[a-1].k = p[a].k;
		p[a].k = tmp;
		
	}
		
	QSort(p, 0, n-1);
	for(j=0; j<n; j++)
			law[j] = p[j]; //rule memo
			
	//for(j=0; j<n; j++)
		//printf("%ld: %ld\n",law[j].num, law[j].k);

	//１回目処理終了
	
	for(i=1; i<d; i++){	
		for(j=0; j<n; j++)
			old[j] = p[j];
				
		for(j=0; j<n; j++)
			p[j] = old[ law[j].num -1];
			
	}
		
	for(j=0; j<n; j++)
		printf("%ld\n", p[j].num);
	


	return 0;
}