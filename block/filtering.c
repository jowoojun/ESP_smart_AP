#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void makegetfile(int argc , char * argv[]){
    printf("block.json 파일 생성\n");
    char temp[MAX];
    // 모든 카테고리를 불러와서 
    FILE * category = fopen("../block/category","r"); 
    if(!category){
        printf("cat not open category file\n");
        return ;
    }

    char allcategory[12][MAX];
    int i= 0;
    for(i = 0 ; i < 12 ; i++){
        fscanf(category,"%s",temp);
        strcpy(allcategory[i],temp);
    }
    close(category);

    // open block.json file   
    FILE * block = fopen("../info/block.json","w");

    fprintf(block ,"{\n");
    
    // print block_status_code data
    fprintf(block ,"\"block_status_code\":\"%s\"\n",argv[1]);
    
    // print block array data
    fprintf(block ,",\"block\":[");
    for(i = 2 ; i < argc-1 ;i++){
        fprintf(block, "\"%s\",",argv[i]);
    }
    fprintf(block, "\"%s\"]\n",argv[i]);

    //print pagelist array data
    fprintf(block ,",\"pagelist\":[");
    int k;
    for(i = 0 ; i < 12 ; i++){
        for( k = 2 ; k < argc ; k++){
            if( strcmp(allcategory[i],argv[k]) == 0 ){
                strcpy(allcategory[i],"NULL");
            }
        }
    }

    for(i= 0 ; i< 12 ; i++){
        if(strcmp(allcategory[i],"NULL") != 0){
            fprintf(block, "\"%s\"",allcategory[i]);
        }
        if(i != 11 && strcmp(allcategory[i],"NULL") != 0){
            fprintf(block, ",");
        }else if(i == 11 && strcmp(allcategory[i],"NULL") != 0){
            fprintf(block, "]\n",argv[i]);
        }
    }

    fprintf(block ,"}\n");

    return ;
}

int main(int argc , char * argv[]){
   
    // 사이트 카테고리 차단
    int on_off;
    
    FILE * bannedsitelist;
    bannedsitelist = fopen("/usr/local/etc/e2guardian/lists/bannedsitelist" , "w");
    if(!bannedsitelist){
        printf("cat not open bannedsitelist \n");
    }
    on_off = atoi(argv[1]); 
    
    int i;
    for( i = 2 ; i < argc ; i++){
        change_category(argv[i] , bannedsitelist);
    }
    
    fclose(bannedsitelist);
    system("cp /usr/local/etc/e2guardian/lists/bannedsitelist /usr/local/etc/e2guardian/lists/bannedsitelist_time");
    
    if(on_off == 0){
        // off
        bannedsitelist = fopen("/usr/local/etc/e2guardian/lists/bannedsitelist" , "w");
        fprintf(bannedsitelist , "# off block site");
        fclose(bannedsitelist);
    }

    // get용 json파일 만들어 보기
    makegetfile(argc , argv);
    
    // 나머지 end.sh 작동 시키기
    system("../block/end.sh");

    return 0;
}

