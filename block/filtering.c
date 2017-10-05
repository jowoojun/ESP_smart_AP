#include <stdio.h>
#include <string.h>
#define MAX 100
void change_category(char * category , FILE * bannedsitelist){

    char ban[MAX];
    strcpy(ban,".Include</usr/local/etc/e2guardian/lists/blacklists/");

    switch(category){

        case "adult":
            strcat(ban,"adult/domains>");
            break;
        case "astrology" :
            strcat(ban,"astrology/domains>");
            break;
        case "bank" :
            strcat(ban,"bank/domains>");
            break;
        case "blog" :
            strcat(ban,"blog/domains>");
            break;
        case "chat" :
            strcat(ban,"chat/domains>");
            break;
        case "cooking":
            strcat(ban,"cooking/domains>");
            break;
        case "drugs":
            strcat(ban,"drug/domains>");
            break;
        case "gambling":
            strcat(ban,"gambling/domains>");
            break;
        case "games":
            strcat(ban,"games/domains>");
            break;
        case "mail":
            strcat(ban,"main/domains>");
            break;
        case "social_networks":
            strcat(ban,"social_networks/domains>");
            break;
        case "shopping":
            strcat(ban,"shopping/domains>");
            break;
    }

    fprintf(bannedsitelist , "%s\n" , ban);

    return ;
}

int main(int argc , char * argv[]){
    
    FILE * bannedsitelist;
    bannedsitelist = fopen("/usr/local/etc/e2guardian/list/bannedsitelist" , "w");
    
    for(int i = 0 ; i < argc ; i++){
        change_category(argv[i] , bannedsitelist);
    }

    system("./");

    return 0;
}

