/* running the CUnit codes:
   gcc cunitTest.c -lcunit*/
#include <iostream>
#include "CUnit/Basic.h"
//#include "credit.cpp"
#include "validation.cpp"
#include "dest.cpp"
using namespace std;

int init_Start(void)
{
   return 0;

}

int init_Clean(void)
{
   return 0;
}

//void test_func(void)
//{
//	return 0;
//}

	
/*
{
     
      CU_ASSERT(add(2,3)==(2+2));
      CU_ASSERT(mul(4.0,2.0)==(8.1));
      CU_ASSERT(checkCredit("kabilan"));
      CU_ASSERT(checkCredit("dm"));
      CU_ASSERT(checkCredit("mrkabilan"));
      CU_ASSERT(checkCredit("dkabilan"));


      // CU_ASSERT(readDoctor(1)==("Available"));
      //CU_ASSERT(readDoctor()==('Unavailable'));
   
} */
void test_func1(void)
{
       CU_ASSERT(checkName("Sanjay"));
       CU_ASSERT(checkName("1sanjay"));
       CU_ASSERT(checkName("Sa@&#&njay"));
       CU_ASSERT(checkName("sanjay"));


}

void test_func2(void)
{
   CU_ASSERT(destinationMenu(1));
   CU_ASSERT(destinationMenu(4));
   CU_ASSERT(destinationMenu(10));
   CU_ASSERT(destinationMenu(8));

}

int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("CUnit_101", init_Start, init_Clean);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "test of checkName(Rohan)", test_func1))
      ||(NULL == CU_add_test(pSuite, "test of destinationMenu(1)", test_func2)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
