#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


// log print
void log_print(){
    FILE * log; // log file

    // open the log file
    log = fopen("/home/ap_log/ap_system.log" ,"a");
    if(!log){
        printf("log file open fail\n");
        return ;
    }

    fprintf(log,"%s\n","블랙리스트를 설정하여 차단");

    fclose(log);

    return ;
}


int change_netmask(char new_netmask[MAX]){
    
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
        
        if( strncmp("netmask ", str, 8) == 0 ){
            
            // add new subnet
            strcpy(str, "\tnetmask ");
            strcat(str, new_netmask);
            fprintf(bak , "%s\n",str);

        }else{
            fprintf(bak , "%s" ,str);
        }
    }

    // close the files
    fclose(origin);
    fclose(bak);

    return 0;
}

int main( int argc , char * argv[] ){
    
    change_netmask( argv[1] );
    
    return 0;
}

