#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "testForrestParsing.h"
#include "testForrestPrinting.h"

int init_suite1 (void){
  return 0;
}

int clean_suite1 (void){
  return 0;
}

int main(){
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  pSuite = CU_add_suite("Forrest test suite", init_suite1, clean_suite1);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(pSuite, "Test of distance parsing", test_parseDistance)) ||
      (NULL == CU_add_test(pSuite, "Test of duration parsing", test_parseDuration)) ||
      (NULL == CU_add_test(pSuite, "Test of distance format printing", test_computeBeautifulDistance)) ||
      (NULL == CU_add_test(pSuite, "Test of duration format printing", test_computeBeautifulDuration))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_basic_show_failures(CU_get_failure_list());
  CU_cleanup_registry();

  printf("\n");

  return CU_get_error();
}

