#include "../../src/solver/solver.h"
#include "../../unity/src/unity.h"

void setUp(void)
{
    //do something before tests
}

void tearDown(void)
{
    //do something after tests
}

void test_Somma(void) {
    TEST_ASSERT_EQUAL(15, somma(10, 5));
    TEST_ASSERT_EQUAL(20, somma(10, 5));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_Somma);
    return UNITY_END();
}