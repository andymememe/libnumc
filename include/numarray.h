#ifndef LIBNUM
#define LIBNUM

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double *_array;
  int     _length;
  int     _n;
} numarray;

void   create(numarray *,
              int);
void   append(numarray *,
              double);
void   appendFromArray(numarray *,
                       double *,
                       int);
double dot(const numarray,
           const numarray);

#endif /* ifndef LIBNUM */
