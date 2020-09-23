#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    
 int   main()
    {
		
		
        int temp,n=4,i=0,max=0,min=99999,raz,b;

        int a[4];
		srand(time(NULL));
		
        while(i<n)
        {
			
        	a[i]=0+(rand()%101);
            i++;
        }
		

        i=0;

        while(i<n) printf(" %d",a[i++]);
		scanf("%d",&b);
		return 0;
}
