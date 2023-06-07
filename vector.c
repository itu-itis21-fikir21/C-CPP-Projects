
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//define vector structure here
typedef struct {
    int x;
    int y;
}Vector;

void printVector(Vector* vec)
{
    printf("%di + %dj\n",vec->x,vec->y);
}

Vector* add(Vector *v1, Vector *v2)
{
	Vector *v =(Vector*) malloc(sizeof(Vector));
    v->x=v1->x + v2->x;
    v->y=v1->y + v2->y;
    return v;
}

Vector* subtract(Vector *v1, Vector *v2)
{
	Vector *v =(Vector*) malloc(sizeof(Vector));
    v->x=v1->x - v2->x;
    v->y=v1->y - v2->y;

    return v;
}

double magnitudeOfVector(Vector* vec)
{
	double magnitude = 0.0;
    magnitude=sqrt((vec->x)*(vec->x) + (vec->y)*(vec->y));
    return magnitude;
}

double angleOfVector(Vector* vec)
{
	double h= vec->y*1.0 / vec->x*1.0;

    return atan(h);
}

double angleBetweenVectors(Vector* vec1,Vector* vec2)
{
	double angle1=angleOfVector(vec1);
	double angle2=angleOfVector(vec2);

    return fabs(angle1 - angle2);
}

int dot_product(Vector *v1, Vector *v2)
{
	double res=magnitudeOfVector(v1) * magnitudeOfVector(v2) * cos(angleBetweenVectors(v1,v2));
    return (int)res;
}

int main()
{
	//create vectors
	//fill vectors using user inputs
    Vector *vec1;
    Vector *vec2;
    Vector *res;
    //int x;
    //int y;

    vec1= (Vector*) malloc(sizeof(Vector));
    vec2= (Vector*) malloc(sizeof(Vector));
	printf("Enter vec1:");
    scanf("%d %d",&vec1->x,&vec1->y);
	printf("Enter vec2:");
    scanf("%d %d",&vec2->x,&vec2->y);

	printVector(vec1);
	printVector(vec2);

	//call necessary operations
    res= subtract(vec1,vec2);

	printf("vec1 - vec2 = %di + %dj\n", res->x , res->y);
	free(res);
    res=NULL;

	//call necessary operations
    res = add(vec1,vec2);
	printf("vec1 + vec2 = %di + %dj\n", res->x , res->y);
	free(res);
    res=NULL;

	printf("Angle of vec1: %f\n", angleOfVector(vec1));
	printf("Angle of vec2: %f\n", angleOfVector(vec2));
	
	printf("Angle between vec1 and vec2: %f\n", angleBetweenVectors(vec1,vec2));
	
	printf("Magnetude of vec1 : %f\n", magnitudeOfVector(vec1));
	printf("Magnetude of vec2 : %f\n", magnitudeOfVector(vec2));
	
	printf("vec1 * vec2 = %d\n", dot_product(vec1, vec2));
	
	//call necessary operations
    free(vec1);
    free(vec2);
	return 0;
}


