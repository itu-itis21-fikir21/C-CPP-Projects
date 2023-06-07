#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatch(char* s, char* p){
    bool ismatch=true;
    int i=0, k=0;
    while(true){
        if((s[i]=='\0')&& (p[k]=='\0')) break;
        else if(((p[k]=='\0')&&(s[i]!='\0'))||((p[k]!='\0')&&(s[i]=='\0'))){
            while(p[k]!='\0'){if(p[k++]=='*' || p[k++]=='.') break;
            else{ismatch = false;break;}}}
        else if(s[i]!=p[k]){
            if(p[k]=='*'){
                while(s[i]==s[i-1]){ i++;} 
                k++;
                while(p[k]==s[i-1]) k++;}
            else if(p[k]=='.'){
                p[k]=s[i];
                i++; k++;}
            else{ismatch=false; break;}}
        else{i++; k++;}}
    return ismatch;
}

int main(){
    char string[20];
    char pattern[20];
    printf("enter the arrays: ");
    scanf("%s", string);
    scanf("%s", pattern);
    bool result = isMatch(string, pattern);
    if(result==true) printf("true");
    else printf("false");
    return 0;
}