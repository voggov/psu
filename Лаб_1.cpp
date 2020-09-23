#include "StdAfx.h"
#include <stdio.h>
    
 int   main(void)
    {
        int temp,n=4,i=0,max=0,min=99999,raz,b;

        int a[4]={3,13,15,25};

        while(i<n)
        {
        	if (a[i] <min) {
				min=a[i];
			}
            if (a[i] > max) 
				max=a[i];
            i++;
        }
		raz=max-min;

        i=0;

        while(i<n) printf(" %d",a[i++]);
		printf ("\n%d",raz);
		scanf("%d",&b);
}

