#include <stdio.h>
#include <string.h>
#define MAX 100
int block(char ip_add[MAX]){
    
    FILE * filter;
    char str[MAX];

    filter = fopen("/home/pi/changgunLEE/esp_smart_ap/block_site/filter","r");
    if(!filter){
        printf("can't open the filter\n");
    }

    while( fscanf(filter,"%s",str) != EOF ){
       if( strcmp(str,ip_add) == 0 ){
            // 차단된 사이트
            return 1;
        }
        
    }

    return 0;
}

void sitefiter(char ip_add[MAX]){
    FILE * ip;

    //open ip
    ip = fopen("/home/pi/changgunLEE/esp_smart_ap/block_site/ip_address","w");
    if(!ip){
        printf("can't open the ip\n");
    }
    
    
    // block site
    if( block(ip_add)){
        // 사이트 블록
        fprintf(ip,"차단된 사이트를 다른사이트로 넘겨준다");
    }else{
        // 사이트 블록 X
        fprintf(ip,"%s",ip_add);
    }

    return ;
}


int main(int argc, char *argv[]){
    sitefiter(argv[1]);
    return 0; 
}
