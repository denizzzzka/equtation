/**
 * @file test.c
 * @author Dan
 * @version 2.0
 * @date 2021-12-12
 */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "equtation.h"

enum case_of_anu_equtation
{
    No_solutions,
    One_solution,
    Two_solution,
    Lin_with_endles_solutions,
    Lin_with_no_solution,
    Lin_with_one_solution
};

bool Test_solve_quadr_eq_endles()
{
    int case_of_equtation;
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    case_of_equtation = solve_quadr_eq(a, b, c, &x1, &x2);
    if (case_of_equtation == Lin_with_endles_solutions){
        return true;
    }
    return false;
}

bool Test_solve_quadr_eq_lin_no()
{
    int case_of_equtation;
    double a = 0, b = 0, c = 1;
    double x1 = 0, x2 = 0;
    case_of_equtation = solve_quadr_eq(a, b, c, &x1, &x2);
    if (case_of_equtation == Lin_with_no_solution){
        return true;
    }
    return false;
}

bool Test_solve_quadr_eq_lin_one()
{
    int case_of_equtation;
    double a = 0, b = 5, c = 10;
    double x1 = 0, x2 = 0;
    case_of_equtation = solve_quadr_eq(a, b, c, &x1, &x2);
    if (case_of_equtation == Lin_with_one_solution && x1 == -2){
        return true;
    }
    return false;
}

bool Test_solve_quadr_eq_quadr_no()
{
    int case_of_equtation;
    double a = 1, b = 0, c = 100;
    double x1 = 0, x2 = 0;
    case_of_equtation = solve_quadr_eq(a, b, c, &x1, &x2);
    if (case_of_equtation == No_solutions){
        a=100;
        b=59;
        c=9;
        case_of_equtation = solve_quadr_eq(a, b, c, &x1, &x2);
        if (case_of_equtation == No_solutions){
            return true;
        }
    }
    return false;
}

bool Test_solve_quadr_eq_quadr_one()
{
    int case_of_equtation;
    double a = 1, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    case_of_equtation = solve_quadr_eq(a, b, c, &x1, &x2);
    if (case_of_equtation == One_solution && x1 == 0){
        a=1;
        b=4;
        c=4;
        case_of_equtation = solve_quadr_eq(a, b, c, &x1, &x2);
        if (case_of_equtation == One_solution && x1 == -2){
            return true;
        }
    }
    return false;
}

bool Test_solve_quadr_eq_quadr_two()
{
    int case_of_equtation;
    double a = 1, b = 0, c = -100;
    double x1 = 0, x2 = 0;
    case_of_equtation = solve_quadr_eq(a, b, c, &x1, &x2);
    if (case_of_equtation == Two_solution && x1 == 10  && x2 == -10){
        a=1;
        b=1;
        c=-12;
        case_of_equtation = solve_quadr_eq(a, b, c, &x1, &x2);
        if (case_of_equtation == Two_solution && x1 == 3 && x2 == -4){
            return true;
        }
    }
    return false;
}

void Run_all_tests ()
{
   assert (true == Test_solve_quadr_eq_endles());
   assert (true == Test_solve_quadr_eq_lin_no());
   assert (true == Test_solve_quadr_eq_lin_one());
   assert (true == Test_solve_quadr_eq_quadr_no());
   assert (true == Test_solve_quadr_eq_quadr_one());
   assert (true == Test_solve_quadr_eq_quadr_two());
   printf("All is working\n");
   return;
}
// hi