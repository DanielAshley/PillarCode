
#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "../src/kata.h"

START_TEST(whenCalcIsAddingIandI)
{
    Kata *k;
    k = kata_init_values("I", "I");
    ck_assert_str_eq(kata_add(k), "II");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingIandII)
{
    Kata *k;
    k = kata_init_values("I", "II");
    ck_assert_str_eq(kata_add(k), "III");
    kata_free(k);
}
END_TEST


START_TEST(whenCalcIsAddingIIandII)
{
    Kata *k;
    k = kata_init_values("II", "II");
    ck_assert_str_eq(kata_add(k), "IV");
    kata_free(k);
}
END_TEST


START_TEST(whenCalcIsAddingIandIII)
{
    Kata *k;
    k = kata_init_values("I", "III");
    ck_assert_str_eq(kata_add(k), "IV");
    kata_free(k);
}
END_TEST


START_TEST(whenCalcIsAddingIIandIII)
{
    Kata *k;
    k = kata_init_values("II", "III");
    ck_assert_str_eq(kata_add(k), "V");
    kata_free(k);
}
END_TEST


START_TEST(whenCalcIsAddingIIIandIII)
{
    Kata *k;
    k = kata_init_values("III", "III");
    ck_assert_str_eq(kata_add(k), "VI");
    kata_free(k);
}
END_TEST


START_TEST(whenCalcIsAddingVandI)
{
    Kata *k;
    k = kata_init_values("V", "I");
    ck_assert_str_eq(kata_add(k), "VI");
    kata_free(k);
}
END_TEST


START_TEST(whenCalcIsAddingIandV)
{
    Kata *k;
    k = kata_init_values("I", "V");
    ck_assert_str_eq(kata_add(k), "VI");
    kata_free(k);
}
END_TEST


Suite * kata_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Kata");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, whenCalcIsAddingIandI);         // I+I        = II
    tcase_add_test(tc_core, whenCalcIsAddingIandII);        // I+II       = III
    tcase_add_test(tc_core, whenCalcIsAddingIIandII);       // II+II      = IV
    tcase_add_test(tc_core, whenCalcIsAddingIandIII);       // I+III      = IV
    tcase_add_test(tc_core, whenCalcIsAddingIIandIII);      // II+III     = V
    tcase_add_test(tc_core, whenCalcIsAddingIIIandIII);     // III+III    = VI
    tcase_add_test(tc_core, whenCalcIsAddingVandI);         // V+I        = VI
    tcase_add_test(tc_core, whenCalcIsAddingIandV);         // I+V        = VI
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

