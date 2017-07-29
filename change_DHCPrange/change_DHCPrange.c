#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100 

void log_print(){
    FILE * log; // log file
    
    // open the log file
    log = fopen("/home/ap_log/ap_system.log" ,"a");
    if(!log){
        printf("log file open fail\n");
        return ;
    }

    fprintf(log,"%s\n","dhcp-range를 설정하였습니다");
    
    fclose(log);

    return ;
}

// change dnsmasq file
int change_DHCPrange(char start_ip[MAX], char end_ip[MAX]){
     
    FILE * origin; // orgin file
    FILE * bak; // bak file

    char str[MAX];
    char temp[MAX];
    strcpy(temp, start_ip);
    strcat(temp,",");
    strcat(temp, end_ip);
    strcat(temp, ",12h");

    // open dnsmasq.conf bakup file
    bak = fopen("/etc/dnsmasq.bak", "w");
    if(!bak){
        printf("can't open the bakup file\n");
        return 0;
    }
    // open dnsmasq.conf file
    origin = fopen("/etc/dnsmasq.conf" , "r");
    if(!origin){
        printf("can't open the origin file\n");
        return 0;
    }

    while( fgets(str , MAX , origin) != NULL){
 
        if( strncmp( "dhcp-range=" , str , 11) == 0 ){

            // add new ip address
            strcpy(str , "dhcp-range=");
            strcat(str , temp);
            fprintf(bak , "%s\n" ,str);

        }else{
            fprintf(bak , "%s" ,str);
        }
           
    }

    // close the files
    fclose(origin);
    fclose(bak);

    return 1;
}

int main( int argc , char * argv[] ){
    
    // change DHCP range
    change_DHCPrange(argv[1],argv[2]);
    
    // print log
    log_print();
    return 0;
}
