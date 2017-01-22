#include "../include/numarray.h"

void create(numarray *a, int length)
{
  a->_length = length;
  a->_array  = (double *)calloc(length, sizeof(double));
  a->_n      = 0;
}

void append(numarray *a, double value)
{
  int n_index = a->_n;

  if (n_index >= a->_length)
  {
    a->_length *= 2;
    a->_array   = (double *)realloc(a->_array, a->_length * sizeof(double));
  }

  a->_array[n_index] = value;
  a->_n             += 1;
}

void appendFromArray(numarray *a, double *l, int length)
{
  for (int i = 0; i < length; i++)
  {
    append(a, l[i]);
  }
}

double dot(const numarray a, const numarray b)
{
  if (a._n != b._n)
  {
    perror("Cannot dot product 2 arrays with different length");
    exit(1);
  }

  int sum = 0;

  for (int i = 0; i < a._n; i++)
  {
    sum += (a._array[i] * b._array[i]);
  }
  return sum;
}
