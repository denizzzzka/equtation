#include "equtation.h"
/**
 * @file main.c
 * @author Dan
 * @version 2.0
 * @date 2021-12-12
 */
#include "test.h"

int main() {
    Run_all_tests();
    int case_of_equtation;
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    scan_coefficients(&a, &b, &c);
    case_of_equtation = solve_quadr_eq(a, b, c, &x1, &x2);
    print_answer(x1, x2, case_of_equtation);
    return 0;
}
