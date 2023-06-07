#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Client_Data{
    int acc_num;
    char name[50];
    double balance;
};
void find_account(FILE* fptr);
void update_account(FILE* fptr);
void delete_account(FILE* fptr);
void Switch_Request(int request);
void Write_account(FILE* fptr);
void read_account(FILE* fptr);
int main(){
    int request;
    Switch_Request(request);
    return 0;
}

void find_account(FILE* fptr){
    int account;
    printf("enter the account number you want to find:");
    scanf("%d", &account);
    
        fseek(fptr, (account-1)*sizeof(struct Client_Data), SEEK_SET);
        struct Client_Data client = {0, "", 0.0};
        fread(&client, sizeof(struct Client_Data), 1, fptr);

        printf("%d %s %lf", client.acc_num, client.name, client.balance);
}


void update_account(FILE* fptr){
    int account;
    
    printf("Enter the account you want to update:");
    scanf("%d", &account);
    fseek(fptr, (account-1)*sizeof(struct Client_Data), SEEK_SET);
    struct Client_Data client={0, "", 0.0};
    fread(&client, sizeof(struct Client_Data), 1, fptr);
    double change;
    printf("enter the new balance value: ");
    scanf("%lf", &change);
    client.balance=change;
    fseek(fptr, (account-1)*sizeof(struct Client_Data), SEEK_SET);
    fwrite(&client, sizeof(struct Client_Data), 1, fptr); 
} 

void delete_account(FILE* fptr){
    int account;
    printf("Enter the account you want to delete:");
    scanf("%d", &account);
    fseek(fptr, (account-1)*sizeof(struct Client_Data), SEEK_SET);
    struct Client_Data client = {0, "", 0.0};
    fwrite(&client, sizeof(struct Client_Data), 1, fptr);
}
void Write_account(FILE* fptr){
    fseek(fptr, 0, SEEK_END);
    struct Client_Data client;
    printf("enter the client information: ");
    scanf("%d %s %lf", &client.acc_num, client.name, &client.balance);
    fwrite(&client, sizeof(struct Client_Data), 1, fptr);
    
}
void read_account(FILE* fptr) {
    struct Client_Data client;
    fseek(fptr, 0, SEEK_SET);
    while (fread(&client, sizeof(struct Client_Data), 1, fptr) == 1) {
        printf("%d %s %.2lf\n", client.acc_num, client.name, client.balance);
    }
}


void Switch_Request(int request){
    FILE* fptr;
    if((fptr = fopen("balance.txt", "r+"))==NULL){
       puts("file couldn't be opened..");
    }
    printf("enter the operation you want to perform: ");
    scanf("%d", &request);
        switch (request){
            case 1:
             find_account(fptr);
             break;
            case 2:
              delete_account(fptr);
              break;
            case 3:
              update_account(fptr);
              break;
            case 4:
              Write_account(fptr);
              break;
            case 5:
              read_account(fptr);
              break; 
            default:
             printf("enter the valid number!");
             break; 
        }
    
    fclose(fptr);

}