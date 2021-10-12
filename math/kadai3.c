#include<stdio.h>

double get_x1(double x2, double x3){ //1行目計算
    return((10-x2-x3)/5);
}
double get_x2(double x1, double x3){//2行目計算
    return ((12.0-x1-x3)/4.0);
}
double get_x3(double x1, double x2){//3行目計算
    return ((13.0-2.0*x1-x2)/3.0);
}

double stop(double num){ //判定
    double a=1-num;
    if(a<0){
        a=-1*a;
    }
    return a;
}
int main(){
    double shousuu=0.000001;//収束範囲設定
    double x1,x2,x3;
    x1=x2=x3=1.0;
    while(stop(get_x1(x2,x3))>shousuu&&stop(get_x2(x1,x3))>shousuu&&stop(get_x3(x1,x2))>shousuu){//収束が確認できたら終了
        //printf("誤差:%lf\n",stop(x1));
        /*以下三行はガウスザイデル法*/
        x1=get_x1(x2,x3);
        x2=get_x2(x1,x3);
        x3=get_x3(x1,x2);
        printf("x1=%.10f,x2=%.10f,x3=%.10f\n",x1,x2,x3);//小数点以下10桁表示
    }
}