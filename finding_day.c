#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isleap(int y)
{
    if(y%4==0)
    {
        if(y%100==0)
        {
            if(y%400==0)
                return 366;
            else
                return 365;
        }
        else 
            return 366;
    }
    else 
        return 365;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int dd,mm,yy,numofdays=0,refdd,refmm,refyy;
    refdd=1;
    refmm=1;
    refyy=1970;
        
    scanf("%d/%d/%d",&dd,&mm,&yy);
    
    if((dd<0)||(dd>32)||(mm<0)||(mm>13)||(yy<1000))
        printf("Invalid Date");
    else
    {
        for(refyy;refyy<yy;refyy++)
        {
            numofdays += isleap(refyy);
        }
        switch(mm-1)
        {
                case 12: numofdays += 31;
                case 11: numofdays += 30;
                case 10: numofdays += 31;
                case 9: numofdays += 30;
                case 8: numofdays += 31;
                case 7: numofdays += 31;
                case 6: numofdays += 30;
                case 5: numofdays += 31;
                case 4: numofdays += 30;
                case 3: numofdays += 31;
                case 2:
                { 
                    if(isleap(yy)==365)
                    numofdays += 28;
                    else
                        numofdays += 29;
                    
                } 
                
                case 1: numofdays += 31;
        }
        numofdays += dd;
        numofdays %= 7;
        switch(numofdays)
        {
                case 1:printf("Thursday");break;
                case 2:printf("Friday");break;
                case 3:printf("Saturday");break;
                case 4:printf("Sunday");break;
                case 5:printf("Monday");break;
                case 6:printf("Tuesday");break;
                case 7:printf("Wednesday");break;
        }
    }
    return 0;
}
