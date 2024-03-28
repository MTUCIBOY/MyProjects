#ifndef BACK_H
#define BACK_H

#include <math.h>
#include <stdio.h>

double RMT_A(double total_loan_amount, double interest_rate,
             size_t credit_months);
double RMT_D(double total_loan_amount, double interest_rate,
             size_t credit_months, size_t current_month);
double Overpayment(double RMT, double total_loan_amount, size_t credit_months);
double Total_Payment(double RMT, size_t credit_months);

#endif  // BACK_H
