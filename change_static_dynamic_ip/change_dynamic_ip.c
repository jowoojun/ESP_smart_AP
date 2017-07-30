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

    fprintf(log,"%s\n","\"고정ip->유동ip변경\"");

    fclose(log);

    return ;
}

int main(void){
    
    FILE * bak;
    FILE * origin;
    char str[MAX];

    // open the bak file
    bak = fopen("/etc/network/interfaces.bak" , "w");
    if(!bak){
        printf("can't open the bakup file\n");
        return 0;
    }

    //open the origin file
    origin = fopen("/etc/network/interfaces","r");
    if(!origin){
        printf("cat't open the origin file\n");
        return 0;
    }
    
    // change static to dynamic ip
    while ( fgets(str , MAX ,origin) != NULL ){
        if( !strncmp("iface wlan0 inet static", str, 21 ) ){
            
            strcpy(str,"iface wlan0 inet");
            strcat(str," dhcp");
            fprintf(bak,str);
            break;

        }else {
     
            fprintf(bak,str);
        
        }
    }
    // close the files
    fclose(origin);
    fclose(bak);

    //print the log for client
    log_print();

    return 0;
}
