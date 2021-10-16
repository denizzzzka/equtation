#include <stdio.h>
#include <assert.h>
#include <math.h>
// double * [_ _ _ _ _ _ _ _]  ptr_to_a = &a;
// double ** [_ _ _ _ _ _ _ _] ptr_to_ptr_to_a = &ptr_to_a;

void scan_coefficients(double *ptr_to_a
                     , double *ptr_to_b
                     , double *ptr_to_c)
{
    // scanf -- функция со своим буфером
    // ['a''\n'-----------------]
    printf("Please, enter three coefficients of square equration\n");
    while (3 != scanf("%lf%lf%lf", ptr_to_a, ptr_to_b, ptr_to_c)) {
        printf("An error with input, try again\n");
        while ('\n' != getchar()) {
        }
     }
    assert(ptr_to_a != NULL);
    assert(ptr_to_b != NULL);
    assert(ptr_to_c != NULL);
    return ;
}

void solve_quadr_eq (double a, double b, double c, double *x1, double *x2, int *case_of_equtation)
{
    if (fabs(a) < 0.00000001)
    {
        if (fabs(b) < 0.00000001)
        {
            if (fabs(c) < 0.00000001)  *case_of_equtation = 3; // lin with endles solution
            else   *case_of_equtation = 4; // lin with no solution
            return;
        }
        *x1 = -c/b;
        *case_of_equtation = 5; //lin with 1 solution
        return;
    }
    if (fabs(b) < 0.00000001)
    {
        if (fabs(c) < 0.00000001)
        {
            *case_of_equtation = 1;
            *x1 = 0;
            return;
        }
        if (a>0 && c>0 || a<0 && c<0)
        {
            *case_of_equtation = 0;
            return;
        }
        *x1 = sqrt(-c/a);
        *x2 = -sqrt(-c/a);
        return;
    }
    double dis = 0;
    dis = b*b - 4*a*c;
    if (dis < -0.00000001)
    {
        *case_of_equtation = 0 ; // нет решений
        return;
    }
    if (dis < 0.00000001) *case_of_equtation = 1; // 1 решение
    *x1 = (-b + sqrt(dis))/(2*a);
    *x2 = (-b - sqrt(dis))/(2*a);
    return;
}

void print_answer(double x1, double x2, int case_of_equtation)
{
    if (case_of_equtation == 0) printf("Square equtation haven't got any roots\n");
    if (case_of_equtation == 1) printf("Square equtation have got one root\nX = %lf\n", x1);
    if (case_of_equtation == 2) printf("Square equtation have got two roots\nX1 = %lf\nX2 = %lf", x1, x2);
    if (case_of_equtation == 3) printf("Linear equtation have got infinite roots\n");
    if (case_of_equtation == 4) printf("Linear equtation haven't got any roots\n");
    if (case_of_equtation == 5) printf("Linear equtation have got one root\nX = %lf\n", x1);
}

int main() {
    int case_of_equtation = 2;
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    scan_coefficients(&a, &b, &c);
    solve_quadr_eq(a, b, c, &x1, &x2, &case_of_equtation);
    print_answer(x1, x2, case_of_equtation);
    return 0;
}
