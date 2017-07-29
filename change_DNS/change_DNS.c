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

    fprintf(log,"%s\n","DNS를 변경");
    
    fclose(log);

    return ;
}

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
        
        if( strncmp("\tdns-nameservers", str, strlen("\tdns-nameservers") ) == 0 ){
            
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

    // close the file
    fclose(origin);
    fclose(bak);

    return 0;
}

int main( int argc , char * argv[] ){
    
    // change DNS address
    change_DNS( argv[1] ,argv[2] );
    
    // print log
    log_print();

    return 0;
}

