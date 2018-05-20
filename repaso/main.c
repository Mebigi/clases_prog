#include <stdio.h>
#include <limits.h>
int factorial(int );
void insertion(int data[],int len);

int main(void)
{

int valor,result;

int vector[8] = {9,7,6,15,16,5,10,11};

insertion(vector,8);


char saludo1[10]="hola";
char saludo2[10]={'h','o','l','a','\0'};
char saludo3[ ]="hola";


char menu[5][20]={"zorro","tortuga","puma","leon","jirafa"};



int i;
int suma = 0;
int max = INT_MIN; // constante definida en limits.h
int min = INT_MAX; // constante definida en limits.h
printf("El maximo es:%d\n",INT_MIN);
printf("El minimo es:%d\n",INT_MAX);
for(i=0; i<1;i++)
{
int aux;
scanf("%d",&aux);
suma=suma+aux;
if(aux>max)
{
max = aux;
}
if(aux<min)
{
min = aux;
}
}
printf("la suma es:%d\n",suma);
printf("El maximo es:%d\n",max);
printf("El minimo es:%d\n",min);

printf("\nIngrese numero:");
scanf("%d",&valor);
result=factorial(valor);
printf("\nEl factorial de %d es %d",valor,result);





	return 0;
}





int factorial(int n)
{
int resp;
if(n==1)
{
  resp= 1;
}
else if(n==0)
{
  resp= 1;
}
else if(n>1)
{resp=n* factorial(n-1);}

return resp;
}


void insertion(int data[],int len)
{
 int i,j;
 int temp;
 for(i=1;i<len;i++)
 {
temp = data[i];


j=i-1;


while(j>=0 && temp<data[j]) // temp<data[j] o temp>data[j]
{
 data[j+1] = data[j];
 j--;
}
data[j+1]=temp; // inserción

printf("vector en el ciclo %d: [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n", i, data[0],data[1], data[2], data[3], data[4], data[5], data[6], data[7] );

 }

}
