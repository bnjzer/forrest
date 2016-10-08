#include "forrestPrinting.h"
#include <CUnit/CUnit.h>
#include <string.h>

void test_computeBeautifulDistance(){
  char distance[11];
  computeBeautifulDistance(1000, distance);
  CU_ASSERT_EQUAL(0, strcmp("1 km", distance));
  computeBeautifulDistance(2100, distance);
  CU_ASSERT_EQUAL(0, strcmp("2.1 km", distance));
  computeBeautifulDistance(3333, distance);
  CU_ASSERT_EQUAL(0, strcmp("3.333 km", distance));
  computeBeautifulDistance(10000, distance);
  CU_ASSERT_EQUAL(0, strcmp("10 km", distance));
  computeBeautifulDistance(555, distance);
  CU_ASSERT_EQUAL(0, strcmp("555 m", distance));
  computeBeautifulDistance(200, distance);
  CU_ASSERT_EQUAL(0, strcmp("200 m", distance));
}

void test_computeBeautifulDuration(){
  char duration[10];
  computeBeautifulDuration(9, duration);
  CU_ASSERT_EQUAL(0, strcmp("0:00:09", duration));
  computeBeautifulDuration(15, duration);
  CU_ASSERT_EQUAL(0, strcmp("0:00:15", duration));
  computeBeautifulDuration(72, duration);
  CU_ASSERT_EQUAL(0, strcmp("0:01:12", duration));
  computeBeautifulDuration(7200, duration);
  CU_ASSERT_EQUAL(0, strcmp("2:00:00", duration));
  computeBeautifulDuration(36000, duration);
  CU_ASSERT_EQUAL(0, strcmp("10:00:00", duration));
  computeBeautifulDuration(36080, duration);
  CU_ASSERT_EQUAL(0, strcmp("10:01:20", duration));
}

