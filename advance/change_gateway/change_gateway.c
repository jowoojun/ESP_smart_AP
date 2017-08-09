#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void log_print(){
    FILE * log; // log file
    
    // open the log file
    log = fopen("/home/ap_log/ap_system.log" ,"a");
    if(!log){
        printf("log file open fail\n");
        return ;
    }

    fprintf(log,"%s\n","\"게이트웨이변경\"");
    
    fclose(log);

    return ;
}

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
        
        if( strncmp("\tgateway", str, strlen("\tgateway") ) == 0 ){
            
            // add new subnet
            strcpy(str, "\tgateway ");
            strcat(str, new_gateway);
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
    
    // change gateway
    change_gateway( argv[1] );
    
    // print log
    log_print();

    return 0;
}

