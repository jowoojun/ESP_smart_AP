#include <stdio.h>
int main(int argc, char * argv[]){
    FILE * apjson = fopen("../info/ap_info.json","w");
    if( !apjson ){
        printf("cat not open ap_info.json file");
        return 0;
    }

    fprintf(apjson , "{\n");
    fprintf(apjson , "\"internet_status_code\":\"1\"\n");
    fprintf(apjson , ",\"my_ip\":\"172.24.1.1\"\n");
    fprintf(apjson , ",\"default_dns\":\"127.0.0.1\"\n");
    fprintf(apjson , ",\"sub_dns\":\"127.0.0.1\"\n");
    fprintf(apjson , ",\"gateway\":\"192.168.0.1\"\n");
    fprintf(apjson , ",\"DHCP_start_ip\":\"%s\"\n" , argv[1]);
    fprintf(apjson , ",\"DHCP_end_ip\":\"%s\"\n" , argv[2]);
    fprintf(apjson , ",\"DHCP_MAC_address\":\"b8:27:eb:6c:2b:85\"\n");
    fprintf(apjson , "}\n");
    
    return 0;
}
