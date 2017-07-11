#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // remove the hostapd.conf
    system("sudo rm /etc/hostapd/hostapd.conf");
    
    FILE * fp;
    FILE * bp;
    
    char * ssid;
    char * pwd;
    
    char temp[100];
    
    // read new ssid and pwd;
    printf("new ssid : ");
    scanf("%s",temp);
    ssid = (char*)malloc(strlen(temp)+1);
    strcpy(ssid , temp);

    printf("new pwd : ");
    scanf("%s",temp);
    pwd = (char*)malloc(strlen(temp)+1);
    strcpy(pwd, temp);

    // open hostapde.conf
    fp = fopen("/etc/hostapd/hostapd.conf", "w");
    if(!fp){
        printf("can't open the file(hostapd.conf)\n");
        return 0;
    }else{
        printf("sucess of file(hostapd.conf) open\n");
    }

    
    // open hostapd_conf.bak
    bp = fopen("/home/pi/changgunLEE/hostapd_conf.bak", "r");
    if(!bp){
        printf("can't opent the file(hostapd_conf.bak)\n");
        return 0;
    }else{
        printf("success of file(hostapd.conf) open\n");
    }
    
    // write to hostapd.conf
    fprintf(fp, "#This is the name of the  network\n");
    fprintf(fp, "ssid=%s\n\n" , ssid);
    
    fprintf(fp, "#The network passphrase\n");
    fprintf(fp, "wpa_passphrase=%s\n\n", pwd);

   
    // Add the bak file
    while( fgets(temp, sizeof(temp), bp) != NULL ){
        fprintf(fp , "%s" , temp);
    }

    // close fp
    fclose(fp);
    fclose(bp);

    // restart hostapd
    system("sudo service hostapd restart");
    
    // print msg
    printf("chage ssid and pwd\nrestart hostapd\n");
    
    // free
    free(ssid);
    free(pwd);

    return 0;
}

