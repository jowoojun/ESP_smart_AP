#include <stdio.h>
#include <string.h>
#define MAX 100

void print_info( char * info_data,FILE * info ){
    char temp[MAX];

    while(fgets() == 1){
        
        if(strcmp(temp,'}')==0){
            break;
        }
        fprintf(info,"%s\n",temp);    
    }

    fprintf(info,"%s\n}",info_data);    
   
    return ;
}

int main(int argv,char*argc[]){
    FILE * info;
    char info_data[MAX];

    info = fopen("info.json","r+w");
    if(!info){
        printf("info.json 파일을 열수 없습니다.\n");
        return 0;
    }
    
    // json파일 형식으로 만들어서 파일 끝부분에 넣어준다.
    strcpy(info_data,'\"');
    strcat(info_data,argc[1]);
    strcat(info_data,"\":");
    

    return 0;

    // 아니면 넘어오믄 json파일을 저장해서 넘겨주는 형식도 괜찮을거 같다.
}
