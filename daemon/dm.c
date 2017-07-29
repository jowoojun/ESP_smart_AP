#include<stdio.h>
#include<signal.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

// Max token count = 20
#define TOKEN_COUNT 20

// token enum
typedef enum _TOKEN_TYPE{
    TOKEN_STRING,
    TOKEN_NUMBER,
}TOKEN_TYPE;

// Token structure
typedef struct _TOKEN{
    TOKEN_TYPE type;
    union{
        char *string;
        double number;
    };
    bool isArray;
}TOKEN;

// JSON structure
typedef struct _JSON {
    TOKEN tokens[TOKEN_COUNT];
}JSON;

// Get the string corresponding to the key
char *getString(JSON *json, char *key){ 
    int i;
    for(i = 0; i < TOKEN_COUNT; i++){ // loop as long as token_count
        if(json->tokens[i].type == TOKEN_STRING && strcmp(json->tokens[i].string, key) == 0){ // token's type is the string and token's string matches the key
                if(json->tokens[i + 1].type == TOKEN_STRING){ // next token is the string
                    return json->tokens[i + 1].string; // return next token's string
                }
        }
    }
    return NULL; // if no key is found
}

// Get the string of the index corresponding to the key
char *getArrayString(JSON *json, char *key, int index){ 
    int i;
    for(i = 0; i < TOKEN_COUNT; i++){ // loop as long as token_count
        if(json->tokens[i].type == TOKEN_STRING && strcmp(json->tokens[i].string, key) == 0){ // token's type is the string and token's string matches the key
            if(json->tokens[i + 1 + index].type == TOKEN_STRING && json->tokens[i + 1 + index].isArray == true){ // next token is the string and that is array
                    return json->tokens[i + 1 + index].string; // return next token's index string 
                }
        }
    }
    return NULL; // if no key is found
}

// Get element count of the Array corresponding to the key
int getArrayCount(JSON *json, char *key){ 
    int i;
    for(i = 0; i < TOKEN_COUNT; i++){ // loop as long as token_count
        if(json->tokens[i].type == TOKEN_STRING && strcmp(json->tokens[i].string, key) == 0){ // token's type is the string and token's string matches the key
            int j = 0;
            while(json->tokens[i + j + 1].isArray == true){  // return the number of tokens that isArray is 1
                j++;
            }
            return j;
        }
    }
    return 0; // if no key is found
}


// Get the Number corresponding to the key
double getNumber(JSON *json, char *key){ 
    int i;
    for(i = 0; i < TOKEN_COUNT; i++){ // loop as long as token_count
        if (json->tokens[i].type == TOKEN_STRING && strcmp(json->tokens[i].string, key) == 0) {  // token's type is the string and token's string matches the key
           if(json->tokens[i + 1].type == TOKEN_NUMBER){   // next token is the number
               return json->tokens[i + 1].number;   // return next token's number
           }
        }
    }
    return 0.0;   // if no key is found
}

// Read JSON
void parseJSON(char *file, int size, JSON *json){
    int tokenIndex = 0; // token index
    int pos = 0; // store position of text

    if(file[pos] != '{'){ // make sure it is JSON
        return ;
    }

    pos ++; // next character

    
    while(pos < size){ // loop as long as filesize
        switch (file[pos]){ // the kind of the character
            case '"' :
                {                 
                    // search starting point. +1 -> except for "
                    char *begin = file + pos + 1;

                    // search ending point. until "
                    char *end = strchr(begin, '"');
                    if(end == NULL){ // if there isn't "
                        break; // end
                    }
                    
                    // real length of file
                    int length = end - begin;
    
                    // The type of the token is a String
                    json->tokens[tokenIndex].type = TOKEN_STRING;
                    // allocate memory
                    json->tokens[tokenIndex].string = malloc(length + 1);
                    // initailize allocated memory
                    memset(json->tokens[tokenIndex].string, 0, length + 1);
                    // copy only the length of the string from begin to begin+length
                    memcpy(json->tokens[tokenIndex].string, begin, length);
    
                    tokenIndex++; // next tokenindex
    
                    pos = pos + length + 1; // now position + the length of string + "(+1)
                }
                break;
            case '0': case '1': case '2': case '3': case '4': case '5': 
            case '6': case '7': case '8': case '9': case '-':       
                {
                    // search starting point
                    char *begin = file + pos;
                    char *end;
                    char *buffer;
                    
                    // search ending point
                    end = strchr(file + pos, ',');
                    if(end == NULL){
                        end == strchr(file + pos, '}');
                        if(end == NULL){
                            break;
                        }
                    }
                    
                    // real length of file
                    int length = end - begin;

                    // allocate memory
                    buffer = malloc(length + 1);

                    // initialize allocated memory
                    memset(buffer, 0, length + 1);

                    /// copy only the length of the string from begin to begin+length 
                    memcpy(buffer, begin, length);

                     // The type of the token is a Number
                    json->tokens[tokenIndex].type = TOKEN_NUMBER;
                    /// Convert string to number and store it in tokens
                    json->tokens[tokenIndex].number = atof(buffer);

                    // free buffer
                    free(buffer);

                    tokenIndex++; // next tokenindex

                    pos = pos + length + 1; // now position + the length of string + "(+1)
 
                }
                break;
            case '[':
                {
                    pos++; // goto next charater
                    
                    // loop until ]
                    while(file[pos] != ']'){
                        if(file[pos] == '"'){  // That is string
                            // search string point
                            char *begin = file + pos + 1;
                            // search ending point
                            char *end = strchr(begin, '"');
                            if(end == NULL){
                                break;
                            }

                            // real length of file
                            int length = end - begin;

                            // The type of the token is String
                            json->tokens[tokenIndex].type = TOKEN_STRING;
                            
                            // allocate memory
                            json->tokens[tokenIndex].string = malloc(length + 1);

                            // The string is Array
                            json->tokens[tokenIndex].isArray = true;

                            // initialize allocated memory
                            memset(json->tokens[tokenIndex].string, 0, length + 1);

                            // copy only the length of the string from begin to begin+length
                            memcpy(json->tokens[tokenIndex].string, begin, length);

                            tokenIndex++;

                            pos = pos + length + 1;
                        }
                        pos++;
                    }
                }
        }
        pos++;
    }
}

// Free JSON and tokens
void freeJSON(JSON *json){
    int i;
    // free all of the tokens
    for(i = 0; i < TOKEN_COUNT; i++){
        if(json->tokens[i].type == TOKEN_STRING){
            free(json->tokens[i].string);
        }
    }
}


// Read file, and Return content and file_size
char *readFile(char *filename, int *fileSize){
    int size;
    char *buffer;

    FILE *fp = fopen(filename, "rb");
    if(fp == NULL){
        return NULL;
    }

    // seek fileSize
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // allocate memory and initialize that
    buffer = malloc(size + 1);
    memset(buffer, 0 , size);

    // read file
    if(fread(buffer, size, 1, fp) < 1){
        *fileSize = 0;
        free(buffer);
        fclose(fp);
        return NULL;
    }

    // hand over size
    *fileSize = size;

    // finalize
    fclose(fp);
    return buffer;
}

// Handle signal
void signalhandler(int signal){
    int size; // the size of the JSON
    char *file;

    // initialize json varialbe
    JSON json = {0, };
    
    if(signal == SIGUSR1){
        file = readFile("ex.json", &size); // file is the varialbe of JSON
        if(file == NULL){
            return ;
        }

        // parsing JSON file
        parseJSON(file, size, &json);

        // print JSON content
        printf("%s : %s\n", json.tokens[0].string, getString(&json, json.tokens[0].string));
        printf("%s : %s\n", json.tokens[2].string, getString(&json, json.tokens[2].string));
        printf("%s : %f\n", json.tokens[4].string, getNumber(&json, json.tokens[4].string));
        printf("%s : \n", json.tokens[6].string);

        int lists = getArrayCount(&json, json.tokens[6].string);
        
        int i;
        for(i = 0; i < lists; i++){
            printf("  %s\n", getArrayString(&json, json.tokens[6].string, i));
        }
        printf("\n");
   }else if(signal == SIGUSR2){
       file = readFile("exam.json", &size); // file is the varialbe of JSON
       if(file == NULL){
           return ;
       }

       // parsing JSON file
       parseJSON(file, size, &json);
       printf("%s : %s\n", json.tokens[0].string, getString(&json, json.tokens[0].string));
       printf("%s : %s\n", json.tokens[2].string, getString(&json, json.tokens[2].string));
       printf("%s : %f\n", json.tokens[4].string, getNumber(&json, json.tokens[4].string));
       printf("\n");
   }


   // release json
   freeJSON(&json);

   // release file
   free(file);

   return ;
}

int main(void){
    while(1){
        signal( SIGUSR1 , signalhandler );
        signal( SIGUSR2 , signalhandler);
    }
}

