#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void printMenu(void){
   printf("\n1.-Root by Newton method\n");
   printf("2.-Root by bisection method \n");
   printf("3.-Simpson 1/3 integration\n");
   printf("4.-Higher order derivative\n");
   printf("5.-Salir\n");
}

int factorial(int n){
   if(n >=1){
   return n*factorial(n-1);
   }
   else return 1;
}

double combinations(int elements,int combinations){
   return factorial(elements)/(factorial(combinations)*factorial(elements-combinations));

}
void printPoly(int PolyOrder, double *Coeficients){
   int i, power;

   printf("Tu polinomio es:\n");
   for (i=0; i<= PolyOrder; i++){
      power=i;
      printf("%.2lfx^%d ", Coeficients[i], power++);
      if ( Coeficients[i+1] > 0 && i < PolyOrder)  printf(" + ");
 
   }
}

double functionEvaluate(int PolyOrder, double *Coeficients,double xInitial){
      double polySumY = 0.0;
      int i;
            for (i=0;i<= PolyOrder;i++){
               polySumY +=  Coeficients[i]*pow(xInitial,i);
            }
      return polySumY;

}
double Derivative(int PolyOrder, double *Coeficients, double error, double xInitial, int DerivativeOrder){
   int i;
   double Derivative=0.0, xEvaluate;
   for (i=0; i<=DerivativeOrder; i++){
         xEvaluate = xInitial + i * error;
         Derivative += (1/pow(error,DerivativeOrder))*pow(-1,i+DerivativeOrder)*combinations(DerivativeOrder,i)*functionEvaluate(PolyOrder, Coeficients, xEvaluate);
   }
      return Derivative;
}



double NewtonRoot(double error, double xInitial, double *Coeficients, int PolyOrder){
   double polySumY, polyDerivative, nextX;
   int i;
         do{ 
            polySumY = functionEvaluate(PolyOrder,Coeficients,xInitial);
            polyDerivative = Derivative(PolyOrder,Coeficients,error,xInitial,1);

            printf("f(x):%lf\n df(x): %lf\n",polySumY,polyDerivative);

            nextX = xInitial - (polySumY/polyDerivative);
            xInitial = nextX;
            }
         while(fabs(polySumY)>=error);
   return xInitial;
}


int main(int argc, char *argv[])
{
   double a[100];
   int i,j, N,option,qw,wq,Inx;//polynomial
   
   double xInitial, xRoot, polyDerivative,error,nextX,polySumY; //1st menu
   
   double q,b,c,ty,polySum1, polySum2; //2nd menu
    
   double  h, polySum3,it=0.0; //3rd menu
   

   printf("Ingresa el orden del polinomio\n");
   scanf("%d", &N);

   printf("Ingresa %d coeficientes\n",N+1);
   for (i=0;i <= N;i++)
   {
     printf("For x^%d: ", i); 
     scanf("\n%lf",&a[i]);
   }
   
 


   do{
      printPoly(N,  a);
      printMenu();
      scanf("%d",&option);

      switch(option){
               case 1: 
                     printf("Ingresa el valor de x\n");
                     scanf("%lf", &xInitial);
                     printf("Ingresa el valor del error\n");
                     scanf("%lf",&error);
                     

                     xRoot = NewtonRoot(error,xInitial,a,N);

                     printf("Tu valor de x es: %lf\n",xRoot);

                     break;
                           
                           
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
                       
                        polySum1 = functionEvaluate(N,a,q);
                        polySum2 = functionEvaluate(N,a,c);

                         if (polySum1 == polySum2){
                           break;
                        }

                        if((polySum1 > 0 && polySum2 > 0) ||(polySum1 < 0 && polySum2 < 0) ){
                           q = c;}
                        else {
                           b = c;}


                        printf("q: %lf\nb: %lf\n",q,b);
                        printf("polySum1: %lf\npolySum2: %lf\n",polySum1,polySum2);

                        }while (fabs(polySum2)>=ty );
                        if (fabs(polySum2)>ty){
                           printf("No roots found in given range\n");
                        }else{
                        printf("La raiz en x es:%f\n",c);                    
                        }
                     break;
                             
               case 3:
                     it=0.0;
                     printf("Numero de interacciones?\n");
                     scanf("%d",&Inx);
                     printf("Entre que intervalo?\n");
                     printf("a:  ");scanf("%lf",&q); 
                     printf("b:  ");scanf("%lf",&b);
                     h=(b-q)/Inx;
                     for(j=0;j<Inx;j++){
                        polySum1=0.0;
                        polySum2=0.0;
                        polySum3=0.0; 
                        for (i=0;i<= N;i++){
                              polySum1 = polySum1 + a[i]*pow(q,i);}
                                              
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
                        
                        case 4:
                             polyDerivative=0.0;
                             printf("Ingresa el valor de x\n");
                         scanf("%lf", &xInitial);
   
                          printf("Ingresa el valor del error\n");
                           scanf("%lf",&error);

                           printf("Ingresa el orden de la derivada\n");
                           scanf("%lf",&it);

                           polyDerivative = Derivative(N,a,error,xInitial,it);
                           printf("El valor de la derivada evaluada es: %lf \n",polyDerivative);             
                        break;
                        
}}while(option != 5);
 
  return 0;
}
