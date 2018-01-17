#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
   double a[10];
   int i,j, N,power,o,qw,wq,Inx;//polynomial
   
   double x, polyD=0.0,e,gx=0.0,polySum=0.0; //1st menu
   
    double q,b,c,ty,polySum1, polySum2; //2nd menu
    
    double  h, polySum3,it=0.0; //3rd menu



   printf("Ingresa el orden del polinomio\n");
   scanf("%d", &N);
   

   printf("Ingresa %d coeficientes\n",N+1);
   for (i=0;i <= N;i++)
   {
     scanf("%lf",&a[i]);
   }
  
   
   power=N;
   
  
   printf("Tu polinomio es:\n");
   for (i=0;i<= N;i++)
   {j=i;
      if (power < 0)
      {
	 break;
      }

         if (a[i] > 0)
	   printf(" + ");
      
	  
      printf("%.2lfx^%d ",a[i],j++);
 
   }
   
   
   
   do{printf("\n1.-Raiz de Newton\n");
   printf("2.-Raiz por biseccion\n");
   printf("3.-Integrar por 1/3 de Simpson\n");
   printf("4.-1er Derivada en x\n");
   printf("5.-2da Derivada en x\n");
   printf("6.-3er Derivada en x\n");
   printf("7.-4ta Derivada en x\n");
   printf("8.-Salir\n");
   scanf("%d",&o);
         switch(o){
                   case 1: 
                        printf("Ingresa el valor de x\n");
                         scanf("%lf", &x);
   
                          printf("Ingresa el valor del error\n");
                           scanf("%lf",&e);
                       
                        
                          do{ 
                              x+=gx;
                                           //printf("x=%lf\n",x);  
                                           polySum=0.0;
                                           polyD=0.0; 

                                 for (i=0;i<= N;i++)
                                 {
                               polySum = polySum + a[i]*pow(x,i);
                                 //printf("%lf\n",polySum);
                                 }

                              
                                for(i=0;i<=N;i++)
                                                   {
                                                   polyD=(a[i]*pow((x+e),i)-a[i]*pow((x-e),i))/(2*e)    ;            
                                                   //printf("%lf\n",polyD);
                                                   }
                                                  
                                                   
                                           gx=-1*(polySum/polyD);
                                           //printf("gx=%lf\n",gx);
                                           
                                                     
                                           }while(fabs(polySum)>e );
                                          
                                           printf("Tu valor de x es: %lf\n",x);
                                           printf("Tu valor de y es: %lf\n",polySum);
                                          
                        break;
                        system("PAUSE");
                           system("cls");
                           
                           
                        case 2:
                             printf("Dame el intervalo [a,b]\n");
                             printf("Dame a:\n");
                             scanf("%lf",&q);
                             printf("Dame b:\n");
                             scanf("%lf",&b);
                             printf("Dame la tolerancia en y\n");
                             scanf("%lf",&ty);
                             do{            
                                              c=(q+b)/2;
                                             polySum1=0.0;
                                             polySum2=0.0;
                                             for (i=0;i<= N;i++)
                                             {
                                              polySum1 = polySum1 + a[i]*pow(q,i);
                                              //printf("1=%lf\n",polySum1);
                                              }
                                              for (i=0;i<= N;i++)
                                             {
                                              polySum2 = polySum2 + a[i]*pow(c,i);
                                              //printf("2=%lf\n",polySum);
                                              }
                                            
                                            
                                         if(polySum1>0){
                                                     if(polySum2>0){
                                                                q=c;       
                                                                }
                                                     else{b=c;
                                                         }       
                                                      }
                                          else{
                                               if(polySum2>0){
                                                          b=c;
                                                          }
                                               else{
                                                    q=c;
                                                    }            
                                                    }
                                                    }while (fabs(polySum2)>=ty );
                                                    printf("La raiz en x es:%f\n",c);
                                              
                        break;
                        system("PAUSE");
                           system("cls");
                             
                             case 3:
                                  it=0.0;
                                  printf("Numero de interacciones?\n");
                        scanf("%d",&Inx);
                        printf("Entre que intervalo?\n");
                        printf("a:  ");scanf("%lf",&q); 
                        printf("b:  ");scanf("%lf",&b);

                       

                        h=(b-q)/Inx;
                        
                                                
                                              
                        for(j=0;j<Inx;j++)
                        {polySum1=0.0;
                                           polySum2=0.0;
                                           polySum3=0.0; 
                                           
                                            for (i=0;i<= N;i++)
                                             {
                                              polySum1 = polySum1 + a[i]*pow(q,i);
                                              //printf("1=%lf\n",polySum1);
                                              }
                                              
                                              for (qw=0;qw<= N;qw++)
                                             {
                                              polySum2 = polySum2 + a[qw]*pow(((q+b)/2),qw);
                                              //printf("2=%lf\n",polySum2);
                                              }
                                             
                                                 for (wq=0;wq<= N;wq++)
                                             {
                                              polySum3 = polySum3 + a[wq]*pow(b,wq);
                                              //printf("3=%lf\n",polySum3);
                                              }
                                              
                        it+=((h/3.0)*(polySum1+4*polySum2+polySum3))/2.0;
                        //printf("%lf\n",it); 
               
                        } 
                        printf("%lf\n",it);  
                                           
                        break;
                        system("PAUSE");
                           system("cls");
                        
                        case 4:
                             polyD=0.0;
                             printf("Ingresa el valor de x\n");
                         scanf("%lf", &x);
   
                          printf("Ingresa el valor del error\n");
                           scanf("%lf",&e);
                                for(i=0;i<=N;i++)
                                                   {
                                                   polyD+=(a[i]*pow((x+e),i)-a[i]*pow((x-e),i))/(2*e)    ;            
                                                   //printf("%lf\n",polyD);
                                                   }     
                                                  printf("El valor de la derivada evaluada es: %lf \n",polyD);             
                        break;
                        system("PAUSE");
                           system("cls");
                           case 5:
                             polyD=0.0; 
                             printf("Ingresa el valor de x\n");
                         scanf("%lf", &x); 
                        printf("Ingresa el error\n");
                           scanf("%lf",&e);
                                for(i=0;i<=N;i++)
                                                   {
                                                   polyD+=(a[i]*pow((x+e),i)-2*a[i]*pow((x),i)+a[i]*pow((x-e),i))/(pow(e,2.0))    ;            
                                                   //printf("%lf\n",polyD);
                                                   }
                                                    printf("El valor de la derivada evaluada es: %lf \n",polyD);                    
                        break;
                        system("PAUSE");
                           system("cls");
                           case 6:
                 polyD=0.0;
                 printf("Ingresa el valor de x\n");
                         scanf("%lf", &x);
                             printf("Ingresa el valor del error\n");
                           scanf("%lf",&e);
                                for(i=0;i<=N;i++)
                                                   {
                                                   polyD+=(a[i]*pow((x+2*e),i)-2*a[i]*pow((x+e),i)+2*a[i]*pow((x-e),i)-a[i]*pow((x-2*e),i));
                                                   polyD=polyD/(2*pow(e,3.0));                
                                                   //printf("%lf\n",polyD);
                                                   }
                                                    printf("El valor de la derivada evaluada es: %lf \n",polyD); 
                                                    break;
                        system("PAUSE");
                           system("cls");
                                                   
                          case 7:
                                 polyD=0.0;
                                 printf("Ingresa el valor de  x\n");
                         scanf("%lf", &x);
                             printf("Ingresa el valor del error\n");
                           scanf("%lf",&e);
                                for(i=0;i<=N;i++)
                                                   {
                                                   polyD+=(a[i]*pow((x+2*e),i)-4*a[i]*pow((x+e),i)+6*a[i]*pow((x),i)-4*a[i]*pow((x-e),i)+a[i]*pow((x-2*e),i))/(pow(e,4.0))    ;            
                                                   //printf("%lf\n",polyD);
                                                   }                            
                         printf("El valor de la derivada evaluada es: %lf \n",polyD); 
                          break;
                        system("PAUSE");
                           system("cls");
                        
}}while(o != 8);
 
   system("PAUSE");	
  return 0;
}
