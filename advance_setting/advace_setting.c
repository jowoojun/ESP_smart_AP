#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char ip_type[10];
    
    printf("choose one dynamic_ip or static_ip\n");
    scanf("%s",ip_type);

    // remove interfaces file
    system("sudo rm /etc/network/interfaces");

    if( strcmp(ip_type , "dynamic_ip") == 0 ){
        
        // 유동ip일때
        system("sudo ./dynamic_ip.sh");
        printf("change dynamic_ip\n");

    }else if( strcmp(ip_type , "static_ip") == 0 ){
        // 고정ip일때
        system("sudo ./static_ip.sh");
        printf("change static_ip\n");
    
    }else {
        // error
        return 0;
    }

    // DNS 바꾸기

    // 채널 바꾸기
    
    //restart dhcpcd hostapd
    system("sudo ifdown wlan0; sudo ifup wlan0");
    system("sudo service dnsmasq restart");
    
    // log남겨 주기
    printf("change network setting\n");
    //printf("restart dhcpcd and hostapd\n");
    
    system("sudo service hostapd restart");

    return 0;
}
