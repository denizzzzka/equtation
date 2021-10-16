#include "equtation.c"

int main() {
    int case_of_equtation = Two_solution;
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    scan_coefficients(&a, &b, &c);
    solve_quadr_eq(a, b, c, &x1, &x2, &case_of_equtation);
    print_answer(x1, x2, case_of_equtation);
    return 0;
}
