#include <stdio.h>
#include <math.h>

// The function f(x) = x - sin(x)
double f(double x) {
  return x - sin(x);
}

// The derivative of f(x)
double df(double x) {
  return 1 - cos(x);
}

int main() {
  double x, y;

  // Initialize the starting value for x
  x = 0.5;

  // Use the Newton-Raphson method to find a root of the function
  while (1) {
    y = x - f(x) / df(x);
    if (fabs(y - x) < 0.00001) {
      break;
    }
    x = y;
  }

  // Print the result
  printf("A root of the function is %lf\n", y);

  return 0;
}
