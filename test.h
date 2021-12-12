/**
 * @file test.h
 * @author Dan
 * @version 2.0
 * @date 2021-12-12
 */

/**
 * test how all is working on input equation with endless answer
 * @return true if all is working
 * @return false if not working
 */
bool Test_solve_quadr_eq_endles();

/**
 * test how all is working on input lin equation with no answer
 * @return true if all is working
 * @return false if not working
 */
bool Test_solve_quadr_eq_lin_no();

/**
 * test how all is working on input lin equation with one answer
 * @return true if all is working
 * @return false if not working
 */
bool Test_solve_quadr_eq_lin_one();

/**
 * test how all is working on input square equation with no answer
 * @return true if all is working
 * @return false if not working
 */
bool Test_solve_quadr_eq_quadr_no();

/**
 * test how all is working on input square equation with one answer
 * @return true if all is working
 * @return false if not working
 */
bool Test_solve_quadr_eq_quadr_one();

/**
 * test how all is working on input square equation with two answer
 * @return true if all is working
 * @return false if not working
 */
bool Test_solve_quadr_eq_quadr_two();

/**
 * stop program if any previos function return false
 */
void Run_all_tests ();