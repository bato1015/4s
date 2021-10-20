#include<iostream>
#include<math.h>

//2x^2+3xの解
float f1(float x){
    return 2*x*x+3*x;
}
float df1(float x){
    return 4*x+3;
}
float Newton(float a){
    float x=0;
    x=a-f1(a)/df1(a); //微分のずれなされている
    printf("%lf\n",x);
    return x;
}
int main(){
int i=0;
float a=3;
    do{
      a= Newton(a);
   
    }(i<14)

    return 0;
}