#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
 
 int i,j,k,l,m,n,z,tmp,x,y;
 int B[10],C[50][2],D[200],E[50];
 char A[10],F[10];
 
 printf("Anahtar sayisini giriniz\n");
 scanf("%d",&n);
 printf("Harfleri giriniz\n");
 i=1;
 scanf("%s",&A[i]);
 printf("Anahtarin frekanslarini giriniz\n");
 for(i=1;i<=n;i++){
  scanf("%d",&B[i]);
  C[i][1]=B[i];
  C[i][2]=1;
 }
 printf("Aranilan kelimenin boyutunu giriniz\n");
 scanf("%d",&z);
 j=1;
 printf("Kelimeyi giriniz\n");
 scanf("%s",&F[j]);
 
 i=1;
 j=2;
 m=n;
 
 while(j<=m){
  
  tmp=C[i][1]+C[j][1];
  k=j+1;
  
  while((C[k][1]<tmp)&&(k<=m)){
   k++;
  }
  
  if(k<=m){
   for(l=m;l>=k;l--){
    C[l+1][1]=C[l][1];
    C[l+1][2]=C[l][2];
   }
  }
  m=m+1;
  C[k][1]=tmp;
  C[k][2]=0;
  i=i+2;
  j=j+2;
 }
 for(i=1;i<200;i++){
  D[i]=0;
 }
 i=1;
 while(m>0){
  if(D[i]==0){
   D[i]=C[m][1];
   y=C[m][2];
   m--;
   if(y==1){
    x=2*i;
    D[x]=-1;
    D[x+1]=-1;
   }
  }
  else
  {
   x=2*i;
   D[x]=-1;
   D[x+1]=-1;  
  }
  i++;
 }
  
 j=1;
 while(z>0){
  i=1;
  while(F[z]!=A[i]){
   i++;
  }
  k=1;
  while(B[i]!=D[k]){
   k++;
  }
  while(k>1){
   x=k%2;
   if(x==1){
    k=(k-1)/2;
    E[j]=0;
   }
   else
   {
    k=k/2;
    E[j]=1;
   }
   j++;
  }
  z--;
 }
 j--;
 for(i=j;i>0;i--){
  printf("%d",E[i]);
 }
 printf("\n");

 system("pause");
 return 0;
}
