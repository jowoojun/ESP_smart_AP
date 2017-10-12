#include <stdio.h>
int main(int argc, char * argv[]){
    FILE * ipjson = fopen("../info/ip_conf.json","w");
    if( !ipjson ){
        printf("cat not open admin_conf.json file");
        return 0;
    }

    fprintf(ipjson , "{\n");
    fprintf(ipjson , "\"my_ip\":\"%s\"\n" , argv[1]);
    fprintf(ipjson , ",\"my_subnetmask\":\"%s\"\n" , argv[2]);
    fprintf(ipjson , ",\"DHCP_start_ip\":\"%s\"\n" , argv[3]);
    fprintf(ipjson , ",\"DHCP_end_ip\":\"%s\"\n" , argv[4]);
    fprintf(ipjson , "}\n");
    
    return 0;
}
