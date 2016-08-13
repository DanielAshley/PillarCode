
#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "../src/kata.h"

START_TEST(whenCalcIsAddingIandI)
{
    Kata *k;
    k = kata_init_values("I", "I");
    ck_assert_str_eq(kata_add(k), "II");
}
END_TEST

START_TEST(whenCalcIsAddingIandII)
{
    Kata *k;
    k = kata_init_values("I", "II");
    ck_assert_str_eq(kata_add(k), "III");
}
END_TEST

Suite * kata_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Kata");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, whenCalcIsAddingIandI);
    tcase_add_test(tc_core, whenCalcIsAddingIandII);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = kata_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

