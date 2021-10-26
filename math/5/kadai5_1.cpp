#include<iostream>
#include<stdio.h>
#include<math.h>

double f1(double x);
double bibun(double a);

double delta(double a){
    return -f1(a)/bibun(a);
}

double f1(double x){
    //return cos(x)+x;
   // return 2*x*x+3*x;
    return cos(x)+log(x);
}

double bibun(double a){
    double h=1.0e-10;
    double dfa;S
    dfa=(f1(h+a)-f1(a))/h;
    //printf("答え:%lf\n",dfa);
    return (f1(h+a)-f1(a))/h;
}

bool hantei(int i,double a){
    const double mnum=1.0e-10;
    const int i_max=100;
    if(i>i_max){
        printf("error");
        return false;
    }else if(mnum>fabs(delta(a))){
        printf("%d回で収束　答え%lf\n",i,a);
        return false;
    }
    return true;
}
void keisan(double a){
    int i=0;
    
     do {
            i++;
            a+=delta(a);
            printf("1:%d回 a:%lf\n",i,a);
        }while(hantei(i,a));

    printf("\n");    
}

int main(){
    double a=1.0;
    double c=3.0;
    keisan(a);
    keisan(c);
    return 0;
}