#include <stdbool.h>
bool comparison_null (double a);
void scan_coefficients(double *ptr_to_a
                     , double *ptr_to_b
                     , double *ptr_to_c);
int solve_lin_eq (double b, double c, double *x1);
int solve_quadr_eq (double a, double b, double c, double *x1, double *x2);
void print_answer(double x1, double x2, int case_of_equtation);
