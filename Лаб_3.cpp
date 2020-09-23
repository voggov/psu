#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    
 int   main()
    {
		
		
        int temp,i=0,max=0,min=99999,raz,b,*mas,n;

		srand(time(NULL));
		printf("Input size massiv:");
		scanf("%d",&n);
		mas = (int*)malloc(n * sizeof(int));
		printf("\nInput elements:\n");
        while(i<n)
        {
			
        	scanf("%d",&mas[i]);
            i++;
        }
		

        i=0;
		printf("massiv:");
        while(i<n) printf(" %d",mas[i++]);
		scanf("%d",&b);
		return 0;
}
