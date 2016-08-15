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
    k = kata_init_values("VII", "IV");
    ck_assert_str_eq(kata_sub(k), "III");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingVIIIandIV)
{
    Kata *k;
    k = kata_init_values("VIII", "IV");
    ck_assert_str_eq(kata_sub(k), "IV");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingVIIIandV)
{
    Kata *k;
    k = kata_init_values("VIII", "V");
    ck_assert_str_eq(kata_sub(k), "III");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingXandI)
{
    Kata *k;
    k = kata_init_values("X", "I");
    ck_assert_str_eq(kata_sub(k), "IX");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingXIIandV)
{
    Kata *k;
    k = kata_init_values("XII", "V");
    ck_assert_str_eq(kata_sub(k), "VII");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingXXXIIandV)
{
    Kata *k;
    k = kata_init_values("XXXII", "V");
    ck_assert_str_eq(kata_sub(k), "XXVII");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingXXXIIandXV)
{
    Kata *k;
    k = kata_init_values("XXXII", "XV");
    ck_assert_str_eq(kata_sub(k), "XVII");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingXXXIIandXVIII)
{
    Kata *k;
    k = kata_init_values("XXXII", "XVIII");
    ck_assert_str_eq(kata_sub(k), "XIV");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingXandIX)
{
    Kata *k;
    k = kata_init_values("X", "IX");
    ck_assert_str_eq(kata_sub(k), "I");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingLandI)
{
    Kata *k;
    k = kata_init_values("L", "I");
    ck_assert_str_eq(kata_sub(k), "XLIX");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingLandV)
{
    Kata *k;
    k = kata_init_values("L", "V");
    ck_assert_str_eq(kata_sub(k), "XLV");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingLandX)
{
    Kata *k;
    k = kata_init_values("L", "X");
    ck_assert_str_eq(kata_sub(k), "XL");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingLandXLIX)
{
    Kata *k;
    k = kata_init_values("L", "XLIX");
    ck_assert_str_eq(kata_sub(k), "I");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingLIandXLIX)
{
    Kata *k;
    k = kata_init_values("LI", "XLIX");
    ck_assert_str_eq(kata_sub(k), "II");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingCandI)
{
    Kata *k;
    k = kata_init_values("C", "I");
    ck_assert_str_eq(kata_sub(k), "XCIX");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingCandV)
{
    Kata *k;
    k = kata_init_values("C", "V");
    ck_assert_str_eq(kata_sub(k), "XCV");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingCandLXVI)
{
    Kata *k;
    k = kata_init_values("C", "LXVI");
    ck_assert_str_eq(kata_sub(k), "XXXIV");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingCIandC)
{
    Kata *k;
    k = kata_init_values("CI", "C");
    ck_assert_str_eq(kata_sub(k), "I");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingDandI)
{
    Kata *k;
    k = kata_init_values("D", "I");
    ck_assert_str_eq(kata_sub(k), "CDXCIX");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingDandV)
{
    Kata *k;
    k = kata_init_values("D", "V");
    ck_assert_str_eq(kata_sub(k), "CDXCV");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingDandCLXVI)
{
    Kata *k;
    k = kata_init_values("D", "CLXVI");
    ck_assert_str_eq(kata_sub(k), "CCCXXXIV");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingDIandD)
{
    Kata *k;
    k = kata_init_values("DI", "D");
    ck_assert_str_eq(kata_sub(k), "I");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingMandI)
{
    Kata *k;
    k = kata_init_values("M", "I");
    ck_assert_str_eq(kata_sub(k), "CMXCIX");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingMandV)
{
    Kata *k;
    k = kata_init_values("M", "V");
    ck_assert_str_eq(kata_sub(k), "CMXCV");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingMandDCLXVI)
{
    Kata *k;
    k = kata_init_values("M", "DCLXVI");
    ck_assert_str_eq(kata_sub(k), "CCCXXXIV");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingMIandM)
{
    Kata *k;
    k = kata_init_values("MI", "M");
    ck_assert_str_eq(kata_sub(k), "I");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingCCCXLIIandCCLXXI)
{
    Kata *k;
    k = kata_init_values("CCCXLII", "CCLXXI");
    ck_assert_str_eq(kata_sub(k), "LXXI");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingMMMMDCCXXandDXCIX)
{
    Kata *k;
    k = kata_init_values("MMMMDCCXX", "DXCIX");
    ck_assert_str_eq(kata_sub(k), "MMMMCXXI");
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingMCCXXXVandMCCXXXIV)
{
    Kata *k;
    k = kata_init_values("MCCXXXV", "MCCXXXIV");
    ck_assert_str_eq(kata_sub(k), "I");
    kata_free(k);
}
END_TEST
// END OF SUBTRACTION TESTS


// BEGINNING OF ERROR CASE TESTS
START_TEST(whenCalcIsSubtractingIandII)
{
    Kata *k;
    k = kata_init_values("I", "II");
    ck_assert_str_eq(kata_sub(k), ""); // Error: output would be less than 1
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsSubtractingIandI)
{
    Kata *k;
    k = kata_init_values("I", "I");
    ck_assert_str_eq(kata_sub(k), ""); // Error: output would be less than 1
    kata_free(k);
}
END_TEST

START_TEST(whenCalcIsAddingMMDCCLXVandMCCXXXV)
{
    Kata *k;
    k = kata_init_values("MMDCCLXV", "MCCXXXV");
    ck_assert_str_eq(kata_add(k), ""); // Error: output would be higher than max value (3999)
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
    tcase_add_test(tc_core, whenCalcIsSubtractingLandI);         // L-I             = XLIX
    tcase_add_test(tc_core, whenCalcIsSubtractingLandV);         // L-V             = XLV
    tcase_add_test(tc_core, whenCalcIsSubtractingLandX);         // L-X             = XL
    tcase_add_test(tc_core, whenCalcIsSubtractingLandXLIX);      // L-XLIX          = I
    tcase_add_test(tc_core, whenCalcIsSubtractingLIandXLIX);     // LI-XLIX         = II
    tcase_add_test(tc_core, whenCalcIsSubtractingCandI);         // C-I             = XCIX
    tcase_add_test(tc_core, whenCalcIsSubtractingCandV);         // C-V             = XCV
    tcase_add_test(tc_core, whenCalcIsSubtractingCandLXVI);      // C-LXVI          = XXXIV
    tcase_add_test(tc_core, whenCalcIsSubtractingCIandC);        // CI-C            = I
    tcase_add_test(tc_core, whenCalcIsSubtractingDandI);         // D-I             = CDXCIX
    tcase_add_test(tc_core, whenCalcIsSubtractingDandV);         // D-V             = CDXCV
    tcase_add_test(tc_core, whenCalcIsSubtractingDandCLXVI);     // D-CLXVI         = CCCXXXIV
    tcase_add_test(tc_core, whenCalcIsSubtractingDIandD);        // DI-D            = I
    tcase_add_test(tc_core, whenCalcIsSubtractingMandI);         // M-I             = CMXCIX
    tcase_add_test(tc_core, whenCalcIsSubtractingMandV);         // M-V             = CMXCV
    tcase_add_test(tc_core, whenCalcIsSubtractingMandDCLXVI);    // M-DCLXVI        = CCCXXXIV
    tcase_add_test(tc_core, whenCalcIsSubtractingMIandM);        // MI-M            = I
    tcase_add_test(tc_core, whenCalcIsSubtractingCCCXLIIandCCLXXI);    // CCCXLII-CCLXXI       = LXXI
    tcase_add_test(tc_core, whenCalcIsSubtractingMMMMDCCXXandDXCIX);   // MMMMDCCXX-DXCIX      = MMMMCXXI
    tcase_add_test(tc_core, whenCalcIsSubtractingMCCXXXVandMCCXXXIV);  // MCCXXXV-MCCXXXIV     = I

    //SUBTRACTION TESTS
    tcase_add_test(tc_core, whenCalcIsSubtractingIandII);        // I-II                       = ""
    tcase_add_test(tc_core, whenCalcIsSubtractingIandI);         // I-I                        = ""
    tcase_add_test(tc_core, whenCalcIsAddingMMDCCLXVandMCCXXXV); // MMDCCLXV+MCCXXXV           = ""

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

