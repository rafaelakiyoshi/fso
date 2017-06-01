#include <math.h>
#include <stdio.h>
#include "../include/libseno.h"

double seno(double angulo) {
  double prox = angulo;
  long double condition;
  int i = 1;
  double soma = angulo;
  while(1) {
    prox = (prox * pow((double) (-1), (double) (2 * i - 1)) * angulo * angulo) / (2 * i * (2 * i + 1)) ;
    soma = soma + prox;
    condition = prox;
    if (condition < 0)  condition*= -1;
    if (condition < 0.0000001) return soma;
    i++;
  }
}

double arc_seno(double val_seno) {
  double prox = val_seno;
  int i = 1;
  double soma = val_seno;
  double condition = 0;
  if (val_seno == 0) return 0;
  while(i < 10000) {
    prox = prox * ((pow(val_seno,2) * (2*i - 1) * (2*i - 1)) / ((2 * i) * (2 * i + 1)));
    soma = soma + prox;
    i++;
  }
  return soma;
}
