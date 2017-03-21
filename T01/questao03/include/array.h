#ifndef VETOR_H
#define VETOR_H

typedef struct _array _array, Array;
struct _array {
  int *__array__;
  int length;

  int (*get)(Array*, int);
  int (*push)(Array**, int);
  int (*sort)(Array**, char);
  int (*print)(Array*);
};

int init_array(Array **self);

int array_get(Array *self, int pos);
int array_push(Array **self, int value);
int array_sort(Array **self, char key);
int array_sortCrescent(int *array, int size);
int array_sortDecrescent(int *array, int size);
int array_print(Array *self);

#endif
