#include <stdio.h>
#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/Automated.h>
#include <numarray.h>

int init_suite_success(void) {
  return 0;
}

int init_suite_failure(void) {
  return -1;
}

int clean_suite_success(void) {
  return 0;
}

int clean_suite_failure(void) {
  return -1;
}

void test_create(void)
{
  numarray a;

  create(&a, 3);

  CU_ASSERT(3 == a._length);
  CU_ASSERT(NULL != a._array);
  CU_ASSERT(0 == a._n);
}

void test_add1(void)
{
  numarray a;

  create(&a, 3);

  append(&a, 0.1);

  CU_ASSERT(3 == a._length);
  CU_ASSERT(1 == a._n);
  CU_ASSERT(0.1 == a._array[0]);
}

void test_add2(void)
{
  numarray a;

  create(&a, 3);

  append(&a, 0.1);
  append(&a, 0.2);
  append(&a, 0.3);
  append(&a, 0.5);

  CU_ASSERT(6 == a._length);
  CU_ASSERT(4 == a._n);
  CU_ASSERT(0.1 == a._array[0]);
  CU_ASSERT(0.2 == a._array[1]);
  CU_ASSERT(0.3 == a._array[2]);
  CU_ASSERT(0.5 == a._array[3]);
}

void test_add3(void)
{
  numarray a;
  double l[5] = {0.1, 0.2, 0.3, 0.4, 0.5};

  create(&a, 3);

  appendFromArray(&a, l, 5);

  CU_ASSERT(6 == a._length);
  CU_ASSERT(5 == a._n);
  CU_ASSERT(0.1 == a._array[0]);
  CU_ASSERT(0.2 == a._array[1]);
  CU_ASSERT(0.3 == a._array[2]);
  CU_ASSERT(0.4 == a._array[3]);
  CU_ASSERT(0.5 == a._array[4]);
}

void test_dot1(void)
{
  numarray a;
  numarray b;

  create(&a, 3);
  create(&b, 3);

  append(&a, 1);
  append(&a, 2);
  append(&a, 1);

  append(&b, 2);
  append(&b, 3);
  append(&b, 4);

  CU_ASSERT(12 == dot(a, b));
}

int main()
{
  CU_pSuite pSuite = NULL;

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

  /* add a suite to the registry */
  pSuite =
    CU_add_suite("Suite_numarray", init_suite_success, clean_suite_success);

  if (NULL == pSuite)
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* add the tests to the suite */
  if ((NULL == CU_add_test(pSuite, "successful_test_create", test_create)) ||
      (NULL == CU_add_test(pSuite, "successful_test_add1", test_add1)) ||
      (NULL == CU_add_test(pSuite, "successful_test_add2", test_add2)) ||
      (NULL == CU_add_test(pSuite, "successful_test_add3", test_add3)) ||
      (NULL == CU_add_test(pSuite, "successful_test_dot1", test_dot1)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Run all tests using the basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /* Run all tests using the console interface */
  CU_console_run_tests();

  /* Clean up registry and return */
  CU_cleanup_registry();
  return CU_get_error();
}
