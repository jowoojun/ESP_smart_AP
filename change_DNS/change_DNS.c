#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int change_DNS(char DNS[MAX] , char sub_DNS[MAX]){
    
    FILE * origin; // orgin file
    FILE * bak; // bak file

    char str[MAX];

    // open interface bakup file
    bak = fopen("/etc/network/interfaces.bak","w");
    if(!bak){
        printf("can't open the bakup file\n");
        return 0;
    }
    // open interface file
    origin = fopen("/etc/network/interfaces" ,"r");
    if(!origin){
        printf("can't open the origin file\n");
        return 0;
    }

    while( fgets(str , MAX , origin) != NULL ){
        
        if( strncmp("dns-nameservers ", str, 16) == 0 ){
            
            // add new subnet
            strcpy(str, "\tdns-nameservers ");
            strcat(str, DNS);
            strcat(str, " ");
            strcat(str, sub_DNS);
            fprintf(bak , "%s\n",str);

        }else{
            fprintf(bak , "%s" ,str);
        }
    }

    return 0;
}

int main( int argc , char * argv[] ){
    
    change_DNS( argv[1] ,argv[2] );
    
    return 0;
}

