#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STRING_LENGTH 50

void swap(char* first, char* second){
	*first = *first + *second; //f = f + s
	*second = *first - *second; //s = (f + s) - s = f 
	*first = *first - *second; 
}


char* inttostring(int input, char* string){
/* char c;

c = '0'

c+=1 // c = '1' 
input = 51
string[0] = '1'
input = 5
string[1] = '5'
string = '15'
string = "51"
*/
	int i = 0;
	do{
		string[i++] = input % 10 + '0';
	} while ((input /= 10) > 0);
		
	
	string[i] = '\0';
	int str_len = i;
	for(i = 0; i<str_len/2; swap(&string[i], &string[str_len-i-1]), i++);
	return string;
	
}




//strlength function
int strlenght(char* string){
	int counter = 0;
	for( ; string[counter] != '\0'; counter++);
	return counter;
}

//strcopy function
char* strcopy(char* source_string, char* destination_string){
	int source_lenght = strlenght(source_string);
	for(int i = 0; i <= source_lenght; i++){
		destination_string[i] = source_string[i];
	}
	return destination_string;
}
//strconcatenate function
char* strconcatenate(char* add_string, char* base_string){
	int base_lenght = strlenght(base_string);
	base_string += base_lenght;
	return strcopy(add_string, base_string);
}

//substring function
char* substring(char* source_string, char* destination_string, int start, int size){
	
	int source_lenght = strlenght(source_string);
	if(start + size <= source_lenght){
		source_string += start;
		for(int i = 0;i<size; i++){
			destination_string[i] = source_string[i];
		}
		destination_string[size] = '\0';
	}
	return destination_string;
}


void generateCandidateEmails(char* name, char* surname, int birthyear){
	
	char candidate1[MAX_STRING_LENGTH] = "";
	char candidate2[MAX_STRING_LENGTH] = "";
	char candidate3[MAX_STRING_LENGTH] = "";
    char temp[MAX_STRING_LENGTH] = "";
	char ending[MAX_STRING_LENGTH] = "@itu.edu.tr";
   //candidate1 : initial of name + surname + last 2 digits of the year
   
   strconcatenate(substring(name, temp, 0, 1), candidate1);
   strconcatenate(surname, candidate1);
   strconcatenate(inttostring(birthyear%100, temp), candidate1);
   strconcatenate(ending, candidate1);  
	 
	printf("Email Candidate 1: %s\n", candidate1);
	
	//candidate2 : first two from name + first two from surname + random 4-digit number
	strconcatenate(substring(name, temp, 0, 2), candidate2);
	strconcatenate(substring(surname, temp, 0, 2), candidate2);
	strconcatenate(inttostring(rand()%1000, temp), candidate2);
	strconcatenate(ending, candidate2);
	
	printf("Email Candidate 2: %s\n", candidate2);
	
	//candidate3 : surname + name + year
	strconcatenate(surname, candidate3);
	strconcatenate(name, candidate3);
	strconcatenate(inttostring(birthyear, temp), candidate3);
	strconcatenate(ending, candidate3);
	
	printf("Email Candidate 3: %s\n", candidate3);
}
	
int main(){
	char name[MAX_STRING_LENGTH];
	char surname[MAX_STRING_LENGTH];
	int year;
	
	srand(time(NULL));
	
	printf("Enter Your Name: ");
	scanf("%s", name);
	printf("Enter Your Surname: ");
	scanf("%s", surname);
	printf("Enter Your Birthyear: ");
	scanf("%d", &year);
	
	generateCandidateEmails(name, surname, year);
	
	return 0;
}
