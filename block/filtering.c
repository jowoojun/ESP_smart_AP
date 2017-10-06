#include <stdio.h>
#include <string.h>
#define MAX 100
void change_category(char * category , FILE * bannedsitelist){

    char ban[MAX];
    strcpy(ban,".Include</usr/local/etc/e2guardian/lists/blacklists/");

    if(strcmp(category , "adult") == 0){
        strcat(ban,"adult/domains>");
    }else if(strcmp(category , "astrology") == 0){
        strcat(ban,"astrology/domains>");
    }else if(strcmp(category , "bank") == 0){
        strcat(ban,"bank/domains>");
    }else if(strcmp(category , "blog") == 0){
        strcat(ban,"blog/domains>");
    }else if(strcmp(category , "chat") == 0){
        strcat(ban,"chat/domains>");
    }else if(strcmp(category , "cooking") == 0){
        strcat(ban,"cooking/domains>");
    }else if(strcmp(category , "drugs") == 0){
        strcat(ban,"drug/domains>");
    }else if(strcmp(category , "gambling") == 0){
        strcat(ban,"gambling/domains>");
    }else if(strcmp(category , "games") == 0){
        strcat(ban,"games/domains>");
    }else if(strcmp(category , "mail") == 0){
        strcat(ban,"mail/domains>");
    }else if(strcmp(category , "social_networks") == 0){
        strcat(ban,"social_networks/domains>");
    }else if(strcmp(category , "shopping") == 0){
        strcat(ban,"shopping/domains>");
    }

    fprintf(bannedsitelist , "%s\n" , ban);

    return ;
}

int main(int argc , char * argv[]){

    FILE * bannedsitelist;
    bannedsitelist = fopen("/usr/local/etc/e2guardian/lists/bannedsitelist" , "w");
    if(!bannedsitelist){
        printf("cat not open bannedsitelist \n");
    }

    int i;
    for( i = 1 ; i < argc ; i++){
        change_category(argv[i] , bannedsitelist);
    }

    system("./end.sh");

    return 0;
}

