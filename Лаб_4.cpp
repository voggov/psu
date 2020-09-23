#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    
 int   main()
    {
		
		
        int temp,n=5,i=0,max=0,min=99999,raz,b,j=0,sum=0;

        int a[5][5];
		srand(time(NULL));
		printf("massiv:\n");
		
		for (int i=0;i<5;i++) {
			for (int j=0;j<5;j++) {
				a[i][j]=0+(rand()%51);
				printf("%d\t",a[i][j]);
			}
			printf("\n");
		}
		for (int i=0;i<5;i++) {
			sum=0;
			for (int j=0;j<5;j++) {
				sum+=a[i][j];
				
			}
			printf("\nsum %d= %d",i,sum);
		}
		

 

       
			
		scanf("%d",&b);
		return 0;
}
