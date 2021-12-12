/**
 * @file equtation.c
 * @author Dan
 * @version 2.0
 * @date 2021-12-12
 */

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

int solve_lin_eq (double b, double c, double *x1)
{
    if (comparison_null(b))
    {
        if (comparison_null(c))
        {  
            return Lin_with_endles_solutions; // lin with endles solution
        }
        else   
        {
            return Lin_with_no_solution; // lin with no solution
        }
    }
    *x1 = -c/b;
    return Lin_with_one_solution; //lin with 1 solution
}

int solve_quadr_eq (double a, double b, double c, double *x1, double *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    if (comparison_null(a))
    {
        return solve_lin_eq(b, c, x1);
    }
    if (comparison_null(b))
    {
        if (comparison_null(c))
        {
            *x1 = 0;
            return One_solution;
        }
        if (a>0 && c>0 || a<0 && c<0)
        {
            return No_solutions;
        }
        *x1 = sqrt(-c/a);
        *x2 = -sqrt(-c/a);
        return Two_solution;
    }
    double dis = 0;
    dis = b*b - 4*a*c;
    if (dis < -zero)
    {
        return No_solutions;
    }
    if (comparison_null(dis))
    {
        *x1 = -b/(2*a);
        return One_solution;
    }
    *x1 = (-b + sqrt(dis))/(2*a);
    *x2 = (-b - sqrt(dis))/(2*a);
    return Two_solution;
}

void print_answer(double x1, double x2, int case_of_equtation)
{
    switch (case_of_equtation)
    {
    case No_solutions:
        printf("Square equtation haven't got any roots\n");   
        break;
    case One_solution:
        printf("Square equtation have got one root\nX = %lf\n", x1);
        break;
    case Two_solution:
        printf("Square equtation have got two roots\nX1 = %lf\nX2 = %lf", x1, x2);
        break;
    case Lin_with_endles_solutions:
        printf("Linear equtation have got infinite roots\n");
        break;
    case Lin_with_no_solution:
        printf("Linear equtation haven't got any roots\n");
        break;
    case Lin_with_one_solution:
        printf("Linear equtation have got one root\nX = %lf\n", x1);
        break;
    }
}
