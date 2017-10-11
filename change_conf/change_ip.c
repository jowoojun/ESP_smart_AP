#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100 

// change interface file
int change_interface(char new_ip[MAX]){

    FILE * origin; // orgin file
    FILE * bak; // bak file

    char str[MAX];

    // open interface bakup file
    bak = fopen("/etc/network/interfaces.bak" , "w");
    if(!bak){
        printf("can't open the bakup file\n");
        return 0;
    }
    // open interface file
    origin = fopen("/etc/network/interfaces" , "r");
    if(!origin){
        printf("can't open the origin file\n");
        return 0;
    }

    while( fgets(str , MAX , origin) != NULL ){

        if( strncmp( "address" , str,strlen("address")) == 0 ){

            // add new ip address
            strcpy(str , "address ");
            strcat(str , new_ip);
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

// change dnsmasq file
int change_dnsmasq(char new_ip[MAX]){

    FILE * origin; // orgin file
    FILE * bak; // bak file

    char str[MAX];

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

        if( strncmp( "listen-address=" , str , 15) == 0 ){

            // add new ip address
            strcpy(str , "listen-address=");
            strcat(str , new_ip);
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

    change_interface(argv[1]);

    change_dnsmasq(argv[1]);

    return 0;
}
