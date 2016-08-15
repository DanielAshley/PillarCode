
#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "../src/kata.h"

// BEGINNING OF ADDITION TESTS
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

START_TEST(whenCalcIsAddingIIandV)
{
    Kata *k;
    k = kata_init_values("II", "V");
    ck_assert_str_eq(kata_add(k), "VII");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingIVandI)
{
    Kata *k;
    k = kata_init_values("IV", "I");
    ck_assert_str_eq(kata_add(k), "V");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingIVandIII)
{
    Kata *k;
    k = kata_init_values("IV", "III");
    ck_assert_str_eq(kata_add(k), "VII");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingIVandIV)
{
    Kata *k;
    k = kata_init_values("IV", "IV");
    ck_assert_str_eq(kata_add(k), "VIII");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingIVandV)
{
    Kata *k;
    k = kata_init_values("IV", "V");
    ck_assert_str_eq(kata_add(k), "IX");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingVandV)
{
    Kata *k;
    k = kata_init_values("V", "V");
    ck_assert_str_eq(kata_add(k), "X");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingVIandVI)
{
    Kata *k;
    k = kata_init_values("VI", "VI");
    ck_assert_str_eq(kata_add(k), "XII");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingVIIIandVI)
{
    Kata *k;
    k = kata_init_values("VIII", "VI");
    ck_assert_str_eq(kata_add(k), "XIV");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingVIIIandVIII)
{
    Kata *k;
    k = kata_init_values("VIII", "VIII");
    ck_assert_str_eq(kata_add(k), "XVI");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingVIIIandIX)
{
    Kata *k;
    k = kata_init_values("VIII", "IX");
    ck_assert_str_eq(kata_add(k), "XVII");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingIXandIX)
{
    Kata *k;
    k = kata_init_values("IX", "IX");
    ck_assert_str_eq(kata_add(k), "XVIII");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingXandIX)
{
    Kata *k;
    k = kata_init_values("X", "IX");
    ck_assert_str_eq(kata_add(k), "XIX");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingXandX)
{
    Kata *k;
    k = kata_init_values("X", "X");
    ck_assert_str_eq(kata_add(k), "XX");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingXIVandXVII)
{
    Kata *k;
    k = kata_init_values("XIV", "XVII");
    ck_assert_str_eq(kata_add(k), "XXXI");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingXXandXXX)
{
    Kata *k;
    k = kata_init_values("XX", "XXX");
    ck_assert_str_eq(kata_add(k), "L");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingXXandXX)
{
    Kata *k;
    k = kata_init_values("XX", "XX");
    ck_assert_str_eq(kata_add(k), "XL");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingLXXandXX)
{
    Kata *k;
    k = kata_init_values("LXX", "XX");
    ck_assert_str_eq(kata_add(k), "XC");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingLXXIVandXXVII)
{
    Kata *k;
    k = kata_init_values("LXXIV", "XXVII");
    ck_assert_str_eq(kata_add(k), "CI");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingCCandCC)
{
    Kata *k;
    k = kata_init_values("CC", "CC");
    ck_assert_str_eq(kata_add(k), "CD");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingCCandDCC)
{
    Kata *k;
    k = kata_init_values("CC", "DCC");
    ck_assert_str_eq(kata_add(k), "CM");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingMMDCCLXVandMCCXXXIV)
{
    Kata *k;
    k = kata_init_values("MMDCCLXV", "MCCXXXIV");
    ck_assert_str_eq(kata_add(k), "MMMCMXCIX");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingMCCXXXIVandMCCXXXIV)
{
    Kata *k;
    k = kata_init_values("MCCXXXIV", "MCCXXXIV");
    ck_assert_str_eq(kata_add(k), "MMCDLXVIII");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingMMMCMXCVIIIandI)
{
    Kata *k;
    k = kata_init_values("MMMCMXCVIII", "I");
    ck_assert_str_eq(kata_add(k), "MMMCMXCIX");
    kata_free(k);
}
END_TEST
// END OF ADDITION TESTS


// BEGINNING OF SUBTRACTION TESTS
START_TEST(whenCalcIsSubtractingIIandI)
{
    Kata *k;
    k = kata_init_values("II", "I");
    ck_assert_str_eq(kata_sub(k), "I");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingIIIandI)
{
    Kata *k;
    k = kata_init_values("III", "I");
    ck_assert_str_eq(kata_sub(k), "II");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingIVandII)
{
    Kata *k;
    k = kata_init_values("IV", "II");
    ck_assert_str_eq(kata_sub(k), "II");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingVandIV)
{
    Kata *k;
    k = kata_init_values("V", "IV");
    ck_assert_str_eq(kata_sub(k), "I");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingVIIandIV)
{
    Kata *k;
    //printf("Init\n");
    k = kata_init_values("VII", "IV");
    ck_assert_str_eq(kata_sub(k), "III");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingVIIIandIV)
{
    Kata *k;
    //printf("Init\n");
    k = kata_init_values("VIII", "IV");
    ck_assert_str_eq(kata_sub(k), "IV");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingVIIIandV)
{
    Kata *k;
    //printf("Init\n");
    k = kata_init_values("VIII", "V");
    ck_assert_str_eq(kata_sub(k), "III");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingXandI)
{
    Kata *k;
    //printf("Init\n");
    k = kata_init_values("X", "I");
    ck_assert_str_eq(kata_sub(k), "IX");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingXIIandV)
{
    Kata *k;
    //printf("Init\n");
    k = kata_init_values("XII", "V");
    ck_assert_str_eq(kata_sub(k), "VII");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingXXXIIandV)
{
    Kata *k;
    //printf("Init\n");
    k = kata_init_values("XXXII", "V");
    ck_assert_str_eq(kata_sub(k), "XXVII");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingXXXIIandXV)
{
    Kata *k;
    //printf("Init\n");
    k = kata_init_values("XXXII", "XV");
    ck_assert_str_eq(kata_sub(k), "XVII");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingXXXIIandXVIII)
{
    Kata *k;
    //printf("Init\n");
    k = kata_init_values("XXXII", "XVIII");
    ck_assert_str_eq(kata_sub(k), "XIV");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingXandIX)
{
    Kata *k;
    //printf("Init\n");
    k = kata_init_values("X", "IX");
    ck_assert_str_eq(kata_sub(k), "I");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingLandI)
{
    Kata *k;
    //printf("Init\n");
    k = kata_init_values("L", "I");
    ck_assert_str_eq(kata_sub(k), "XLIX");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingLandV)
{
    Kata *k;
    //printf("Init\n");
    k = kata_init_values("L", "V");
    ck_assert_str_eq(kata_sub(k), "XLV");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingLandX)
{
    Kata *k;
    //printf("Init\n");
    k = kata_init_values("L", "X");
    ck_assert_str_eq(kata_sub(k), "XL");
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

    //ADDITION TESTS
    tcase_add_test(tc_core, whenCalcIsAddingIandI);              // I+I             = II
    tcase_add_test(tc_core, whenCalcIsAddingIandII);             // I+II            = III
    tcase_add_test(tc_core, whenCalcIsAddingIIandII);            // II+II           = IV
    tcase_add_test(tc_core, whenCalcIsAddingIandIII);            // I+III           = IV
    tcase_add_test(tc_core, whenCalcIsAddingIIandIII);           // II+III          = V
    tcase_add_test(tc_core, whenCalcIsAddingIIIandIII);          // III+III         = VI
    tcase_add_test(tc_core, whenCalcIsAddingVandI);              // V+I             = VI
    tcase_add_test(tc_core, whenCalcIsAddingIandV);              // I+V             = VI
    tcase_add_test(tc_core, whenCalcIsAddingIIandV);             // II+V            = VII
    tcase_add_test(tc_core, whenCalcIsAddingIVandI);             // IV+I            = V
    tcase_add_test(tc_core, whenCalcIsAddingIVandIII);           // IV+III          = VII
    tcase_add_test(tc_core, whenCalcIsAddingIVandIV);            // IV+IV           = VIII
    tcase_add_test(tc_core, whenCalcIsAddingIVandV);             // IV+V            = IX
    tcase_add_test(tc_core, whenCalcIsAddingVandV);              // V+V             = X
    tcase_add_test(tc_core, whenCalcIsAddingVIandVI);            // VI+VI           = XII
    tcase_add_test(tc_core, whenCalcIsAddingVIIIandVI);          // VIII+VI         = XIV
    tcase_add_test(tc_core, whenCalcIsAddingVIIIandVIII);        // VIII+VIII       = XVI
    tcase_add_test(tc_core, whenCalcIsAddingVIIIandIX);          // VIII+IX         = XVII
    tcase_add_test(tc_core, whenCalcIsAddingIXandIX);            // IX+IX           = XVIII
    tcase_add_test(tc_core, whenCalcIsAddingXandIX);             // X+IX            = XIX
    tcase_add_test(tc_core, whenCalcIsAddingXandX);              // X+X             = XX
    tcase_add_test(tc_core, whenCalcIsAddingXIVandXVII);         // XIV+XVII        = XXXI
    tcase_add_test(tc_core, whenCalcIsAddingXXandXXX);           // XX+XXX          = L
    tcase_add_test(tc_core, whenCalcIsAddingXXandXX);            // XX+XX           = XL
    tcase_add_test(tc_core, whenCalcIsAddingLXXandXX);           // LXX+XX          = XC
    tcase_add_test(tc_core, whenCalcIsAddingLXXIVandXXVII);      // LXXIV+XXVII     = CI
    tcase_add_test(tc_core, whenCalcIsAddingCCandCC);            // CC+CC           = CD
    tcase_add_test(tc_core, whenCalcIsAddingCCandDCC);           // CC+DCC          = CM
    tcase_add_test(tc_core, whenCalcIsAddingMMDCCLXVandMCCXXXIV);   // MMDCCLXV+MCCXXXIV   = MMMCMXCIX
    tcase_add_test(tc_core, whenCalcIsAddingMCCXXXIVandMCCXXXIV);   // MCCXXXIV+MCCXXXIV   = MMCDLXVIII
    tcase_add_test(tc_core, whenCalcIsAddingMMMCMXCVIIIandI);       // MMMCMXCVIII+I       = MMMCMXCIX

    //SUBTRACTION TESTS
    tcase_add_test(tc_core, whenCalcIsSubtractingIIandI);        // II-I            = I
    tcase_add_test(tc_core, whenCalcIsSubtractingIIIandI);       // III-I           = II
    tcase_add_test(tc_core, whenCalcIsSubtractingIVandII);       // IV-II           = II
    tcase_add_test(tc_core, whenCalcIsSubtractingVandIV);        // V-IV            = I
    tcase_add_test(tc_core, whenCalcIsSubtractingVIIandIV);      // VII-IV          = III
    tcase_add_test(tc_core, whenCalcIsSubtractingVIIIandIV);     // VIII-IV         = IV
    tcase_add_test(tc_core, whenCalcIsSubtractingVIIIandV);      // VIII-V          = III
    tcase_add_test(tc_core, whenCalcIsSubtractingXandI);         // X-I             = IX
    tcase_add_test(tc_core, whenCalcIsSubtractingXIIandV);       // XII-V           = VII
    tcase_add_test(tc_core, whenCalcIsSubtractingXXXIIandV);     // XXXII-V         = XXVII
    tcase_add_test(tc_core, whenCalcIsSubtractingXXXIIandXV);    // XXXII-XV        = XVII
    tcase_add_test(tc_core, whenCalcIsSubtractingXXXIIandXVIII); // XXXII-XVIII     = XIV
    tcase_add_test(tc_core, whenCalcIsSubtractingXandIX);        // X-IX            = I
    tcase_add_test(tc_core, whenCalcIsSubtractingLandI);         // L-I              = XLIX
    tcase_add_test(tc_core, whenCalcIsSubtractingLandV);         // L-V              = XLV
    tcase_add_test(tc_core, whenCalcIsSubtractingLandX);         // L-X              = XL

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

