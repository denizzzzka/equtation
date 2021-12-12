/**
 * @file equtation.h
 * @author Dan
 * @version 2.0
 * @date 2021-12-12
 */

#include <stdbool.h>

/**
 * This function compare value with null
 * @param a value to compare
 * @return true if value +- = 0
 * @return false if value =! 0
 */
bool comparison_null (double a);

/**
 * scan input 
 * @param ptr_to_a coefficient of x^2 
 * @param ptr_to_b coefficient of x^1
 * @param ptr_to_c coefficient of x^0 
 */
void scan_coefficients(double *ptr_to_a
                     , double *ptr_to_b
                     , double *ptr_to_c);

/**
 * Solve equation with  coefficient of x^2 == 0 and write answer in x1
 * @param b coefficient of x^1
 * @param c coefficient of x^0 
 * @param x1 virable to write
 * @return type of equation 
 */
int solve_lin_eq (double b, double c, double *x1);

/**
 * Solve equation with  coefficient of x^2 =! 0 and write answer in x1 and x2 
 * @param a coefficient of x^2 
 * @param b coefficient of x^1
 * @param c coefficient of x^0 
 * @param x1 virable to write
 * @param x2 virable to write
 * @return type of equation 
 */
int solve_quadr_eq (double a, double b, double c, double *x1, double *x2);

/**
 * print answer of equation  
 * @param x1 first answare
 * @param x2 second answare
 * @param case_of_equtation type of equation  
 */
void print_answer(double x1, double x2, int case_of_equtation);
