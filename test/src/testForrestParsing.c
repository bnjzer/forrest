#include "forrestParsing.h"
#include <CUnit/CUnit.h>

void test_parseDistance() {
  int parsedMeters;
  parseDistance("1km", &parsedMeters);
  CU_ASSERT_EQUAL(1000, parsedMeters);
  parseDistance("1km 500", &parsedMeters);
  CU_ASSERT_EQUAL(1500, parsedMeters);
  parseDistance("21km2m", &parsedMeters);
  CU_ASSERT_EQUAL(21002, parsedMeters);
  parseDistance("1500 m", &parsedMeters);
  CU_ASSERT_EQUAL(1500, parsedMeters);
  parseDistance("100m", &parsedMeters);
  CU_ASSERT_EQUAL(100, parsedMeters);
  parseDistance("400", &parsedMeters);
  CU_ASSERT_EQUAL(400, parsedMeters);
  parseDistance("3 km 5 0 0 m", &parsedMeters);
  CU_ASSERT_EQUAL(3500, parsedMeters);
}

void test_parseDuration() {
  int parsedDuration;
  parseDuration("1h", &parsedDuration);
  CU_ASSERT_EQUAL(3600, parsedDuration);
  parseDuration("2h3m", &parsedDuration);
  CU_ASSERT_EQUAL(7380, parsedDuration);
  parseDuration("45s", &parsedDuration);
  CU_ASSERT_EQUAL(45, parsedDuration);
  parseDuration("72", &parsedDuration);
  CU_ASSERT_EQUAL(72, parsedDuration);
  parseDuration("3h5s", &parsedDuration);
  CU_ASSERT_EQUAL(10805, parsedDuration);
  parseDuration("1h5", &parsedDuration);
  CU_ASSERT_EQUAL(3900, parsedDuration);
  parseDuration("2 h 5m 1 3s", &parsedDuration);
  CU_ASSERT_EQUAL(7513, parsedDuration);
}

