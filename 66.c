#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f (double x) {
  return x*x-4;
}

double df(double x){
  return 2*x;
}

double bisection_method (double a, double b) {
  double c;
  while (fabs(a - b) > 1e-10) {
    c = (a + b) / 2;
    if (f(c) == 0) { break; }
    if (f(a) * f(c) < 0) { b = c; }
    if (f(a) * f(c) > 0) { a = c; }
  }
  return c;
}

void newtonMethod(double a, double eps, double *result, double *num)
{
    int i=0;
    double ah;
 
    while(i<100000) {
        i++;
        ah = a - f(a)/df(a);
        // 収束条件を満たせばループ終了
        if(abs(ah - a)<eps) break;
        a = ah;
    }
    *result = a;
    *num = i; 
}

int main (void) {
  double alpha, result, num;
  alpha = bisection_method(-5, 0.3);
  printf("二分法での結果\nx = %f\n", alpha);


  // ニュートン法(初期値, 収束条件)
  newtonMethod(1.0, 1.0e-5, &result, &num);
 
  // 結果表示
  printf("ニュートン方での解\nx = : %f(収束回数%f 回)\n", result, num); // 解：2.000000(収束回数0 回)
  
  return 0;
}