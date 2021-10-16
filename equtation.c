#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

double zero = 0.0000000001;
enum case_of_anu_equtation
{
    No_solutions,
    One_solution,
    Two_solution,
    Lin_with_endles_solutions,
    Lin_with_no_solution,
    Lin_with_one_solution
};

bool comparison_null (double a)
{
    if (fabs(a) < zero) return true;
    else return false;
}

void scan_coefficients(double *ptr_to_a
                     , double *ptr_to_b
                     , double *ptr_to_c)
{
    assert(ptr_to_a != NULL);
    assert(ptr_to_b != NULL);
    assert(ptr_to_c != NULL);
    printf("Please, enter three coefficients of square equration\n");
    while (3 != scanf("%lf%lf%lf", ptr_to_a, ptr_to_b, ptr_to_c)) {
        printf("An error with input, try again\n");
        while ('\n' != getchar()) {
        }
     }
    return ;
}

void solve_quadr_eq (double a, double b, double c, double *x1, double *x2, int *case_of_equtation)
{
    if (comparison_null(a))
    {
        if (comparison_null(b))
        {
            if (comparison_null(c))  *case_of_equtation = Lin_with_endles_solutions; // lin with endles solution
            else   *case_of_equtation = Lin_with_no_solution; // lin with no solution
            return;
        }
        *x1 = -c/b;
        *case_of_equtation = Lin_with_one_solution; //lin with 1 solution
        return;
    }
    if (comparison_null(b))
    {
        if (comparison_null(c))
        {
            *case_of_equtation = One_solution;
            *x1 = 0;
            return;
        }
        if (a>0 && c>0 || a<0 && c<0)
        {
            *case_of_equtation = No_solutions;
            return;
        }
        *x1 = sqrt(-c/a);
        *x2 = -sqrt(-c/a);
        return;
    }
    double dis = 0;
    dis = b*b - 4*a*c;
    if (dis < zero)
    {
        *case_of_equtation = No_solutions; // нет решений
        return;
    }
    if (comparison_null(dis)) *case_of_equtation = One_solution; // 1 решение
    *x1 = (-b + sqrt(dis))/(2*a);
    *x2 = (-b - sqrt(dis))/(2*a);
    return;
}

void print_answer(double x1, double x2, int case_of_equtation)
{
    if (case_of_equtation == No_solutions) printf("Square equtation haven't got any roots\n");
    if (case_of_equtation == One_solution) printf("Square equtation have got one root\nX = %lf\n", x1);
    if (case_of_equtation == Two_solution) printf("Square equtation have got two roots\nX1 = %lf\nX2 = %lf", x1, x2);
    if (case_of_equtation == Lin_with_endles_solutions) printf("Linear equtation have got infinite roots\n");
    if (case_of_equtation == Lin_with_no_solution) printf("Linear equtation haven't got any roots\n");
    if (case_of_equtation == Lin_with_one_solution) printf("Linear equtation have got one root\nX = %lf\n", x1);
}

int main() {
    int case_of_equtation = Two_solution;
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    scan_coefficients(&a, &b, &c);
    solve_quadr_eq(a, b, c, &x1, &x2, &case_of_equtation);
    print_answer(x1, x2, case_of_equtation);
    return 0;
}