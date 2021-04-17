#include "unity.h"
#include <inventory_manager.h>

/* Modify these two lines according to the project */

#define PROJECT_NAME "inventory_manager"

/* Prototypes for all the test functions */
void test_additem(void);
void test_displayitem(void);
void test_modifyitem(void);
void test_deleteitem(void);

FILE *fp;
struct item testitem =  {"itemname","manufacturer",15,200};
struct item *itm = &testitem;

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();
  fp = fopen("testfile","w");

/* Run Test functions */
  RUN_TEST(test_additem);
  RUN_TEST(test_modifyitem);
  RUN_TEST(test_displayitem);
  RUN_TEST(test_deleteitem);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void test_additem(void) {
  TEST_ASSERT_EQUAL(0,additem(fp,itm));
  
  }

void test_displayitem(void) {
  TEST_ASSERT_EQUAL(0,displayitem(fp));
  
}

void test_modifyitem(void) {
  TEST_ASSERT_EQUAL(0, modifyitem(fp));
  
}

void test_deleteitem(void) {
  TEST_ASSERT_EQUAL(0, deleteitem(fp));
}
