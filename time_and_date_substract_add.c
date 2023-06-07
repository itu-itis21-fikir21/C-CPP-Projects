#include <stdio.h>
#include <stdlib.h>


//define Time,Date,ExtendedTime structure here
//
//
//
typedef struct{
    int hour;
    int minute;
    int second;
}Time;

typedef struct{
    int year;
    int month;
    int day;
}Date;

typedef struct{
    Time* time;
    Date* date;
}ExtendedTime;


int addTime(Time* op1, Time* op2, Time* op3)
{
	int carry;
    op3->second= op1->second + op2->second;
    carry=op3->second / 60;
    op3->second=op3->second % 60;

    op3->minute= op1->minute + op2->minute + carry;
    carry=op3->minute / 60;
    op3->minute=op3->minute % 60;

    op3->hour= op1->hour + op2->hour + carry;
    carry=op3->hour / 24;
    op3->hour=(op3->hour % 24) ;

    return carry;
}

int subtractTime(Time* op1, Time* op2, Time* op3)
{
	int borrow;

    op3->second=op1->second - op2->second;
    op3->second+=60;
    borrow= op3->second/60 -1;
    op3->second= op3->second %60;

    op3->minute=op1->minute - op2->minute + borrow;
    op3->minute+=60;
    borrow= op3->minute/60 -1;
    op3->minute= op3->minute %60;

    op3->hour=op1->hour - op2->hour + borrow;
    op3->hour+=24;
    borrow= op3->hour/24 -1;
    op3->hour= op3->hour %24;

    return borrow;
}

//assuming each month has 30 days

void addDate(Date* op1, Date* op2, Date* op3,int carry){
	op3->day=op1->day + op2->day + carry -1;
    carry=op3->day / 30;
    op3->day = op3->day % 30 +1;

    op3->month=op1->month + op2->month + carry -1;
    carry=op3->month / 12;
    op3->month = op3->month % 12 +1;

    op3->year=op1->year + op2->year + carry ;
}

void subtractDate(Date* op1, Date* op2, Date* op3,int borrow){
	op3->day = op1->day - op2->day + borrow ;
    op3->day+=30;
    borrow = op3->day/30 -1;
    op3->day=op3->day%30;

    op3->month = op1->month - op2->month + borrow;
    op3->month+=12;
    borrow = op3->month/12 -1;
    op3->month=op3->month%12 +1;

    op3->year=op1->year - op2->year + borrow  ;



}


void addExtendedTime(ExtendedTime* op1, ExtendedTime* op2, ExtendedTime* op3){
	int c=addTime(op1->time, op2->time,op3->time);

    addDate(op1->date, op2->date,op3->date,c);
}

void subtractExtendedTime(ExtendedTime* op1, ExtendedTime* op2, ExtendedTime* op3){
	int b=subtractTime(op1->time, op2->time,op3->time);

    subtractDate(op1->date, op2->date,op3->date,b);
}



void printExtendedTime(ExtendedTime *e_time){
	printf("Extended Time is %02d/%02d/%04d %02d:%02d:%02d\n", e_time->date->day, e_time->date->month, e_time->date->year, e_time->time->hour,e_time->time->minute,e_time->time->second);
}

int main()
{
	//create ExtendedTimes, Times and Dates
    ExtendedTime* a;
    a= (ExtendedTime*) malloc(sizeof(ExtendedTime));
    a->time=(Time*) malloc(sizeof(Time));
    a->date=(Date*) malloc(sizeof(Date));
	//fill ExtendedTimes, Times and Dates using user inputs
    printf("Enter timeA:");
    scanf("%d %d %d", &a->time->hour, &a->time->minute,&a->time->second);
    printf("Enter dateA:");
    scanf("%d %d %d", &a->date->year,&a->date->month,&a->date->day);

    ExtendedTime* b;
    b= (ExtendedTime*) malloc(sizeof(ExtendedTime));
    b->time=(Time*) malloc(sizeof(Time));
    b->date=(Date*) malloc(sizeof(Date));
    printf("Enter timeB:");
    scanf("%d %d %d",&b->time->hour, &b->time->minute,&b->time->second);
    printf("Enter dateB:");
    scanf("%d %d %d",&b->date->year,&b->date->month,&b->date->day);

    ExtendedTime* c;
    c= (ExtendedTime*) malloc(sizeof(ExtendedTime));
    c->time=(Time*) malloc(sizeof(Time));
    c->date=(Date*) malloc(sizeof(Date));

    ExtendedTime* d;
    d= (ExtendedTime*) malloc(sizeof(ExtendedTime));
    d->time=(Time*) malloc(sizeof(Time));
    d->date=(Date*) malloc(sizeof(Date));

	//call necessary operations
	addExtendedTime(a,b,c);
	subtractExtendedTime(a,b,d);
	
	printExtendedTime(c);
	printExtendedTime(d);
	//call necessary operations
	return 0;
}