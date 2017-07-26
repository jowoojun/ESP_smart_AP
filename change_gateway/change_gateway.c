#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int change_gateway(char new_gateway[MAX]){
    
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
        
        if( strncmp("gateway ", str, 8) == 0 ){
            
            // add new subnet
            strcpy(str, "\tgateway ");
            strcat(str, new_gateway);
            fprintf(bak , "%s\n",str);

        }else{
            fprintf(bak , "%s" ,str);
        }
    }

    return 0;
}

int main( int argc , char * argv[] ){
    
    change_gateway( argv[1] );
    
    return 0;
}

