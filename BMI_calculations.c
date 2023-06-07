#include <stdio.h>
#include <stdlib.h>

struct yap {
  char cdizi1[20]; // �sim
  char cdizi2[20]; // Soyad�
  int id;    // Ya��
  int boy,w,c;
} ydizi[5];


int main(void)
{
  int id,boy,w,c, cinsiyet;
  double BMR, BFP, BMI, DWI,a;
  char cdizi[20];
  
  for(int i=0; i<5; i++ ){
  	   printf("Erkek icin 1'i Kadin icin 2'yi tuslayiniz. ");
       scanf("%d", &cinsiyet);
       ydizi[i].c=cinsiyet;
       printf("Adi: ");
       fgets(ydizi[i].cdizi1, 20, stdin);
       printf("Soyadi: ");
       fgets(ydizi[i].cdizi1, 20, stdin);
       printf("Yasi: ");
       fgets(cdizi, 20, stdin);
       ydizi[i].id = (int) atoi(cdizi);
       printf("Boy: ");
       fgets(cdizi,20, stdin);
       ydizi[i].boy = atoi(cdizi);
		   printf("Agirlik: ");
       fgets(cdizi,20, stdin);
       ydizi[i].w = atoi(cdizi);
       
       

       printf("\n");
      
  
	   if(ydizi[i].c == 1 ){
  		  BMI = 5;
  			BMR = 13.397*(double)ydizi[i].w+4.799*(double)ydizi[i].boy-5.677*(double)ydizi[i].id+88.362;
  			BFP = 1.2*BMI + 0.23*(double)ydizi[i].id-16.2;
  			printf("%s %s %d %d %d %.2f %.2f %.2f\n", ydizi[i].cdizi1, ydizi[i].cdizi2, ydizi[i].id, ydizi[i].boy, ydizi[i].w, BMR , BFP, BMI);
  		}
   
	   else if(ydizi[i].c == 2){
		
      BMI = 5;
		  BMR = 9.247*(double)ydizi[i].w+3.098*(double)ydizi[i].boy-4.33*(double)ydizi[i].id+447593;
		  BFP = 1.2*BMI+0.23*(double)ydizi[i].id-5.4;
		  printf("%s %s %d %d %d %.2f %.2f %.2f\n", ydizi[i].cdizi1, ydizi[i].cdizi2, ydizi[i].id, ydizi[i].boy, ydizi[i].w, BMR , BFP, BMI);	
	
		
    }
  }

  return 0;
}

