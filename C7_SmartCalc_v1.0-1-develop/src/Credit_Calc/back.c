#include "back.h"

double RMT_A(double total_loan_amount, double interest_rate,
             size_t credit_months) {
  double R = interest_rate * 0.01 / 12;
  double temp = pow(1 + R, credit_months);

  return (total_loan_amount * R * temp) / (temp - 1);
}

double RMT_D(double total_loan_amount, double interest_rate,
             size_t credit_months, size_t current_month) {
  double R = interest_rate * 0.01 / 12;
  return total_loan_amount / credit_months +
         total_loan_amount * R * (1 - (current_month - 1.0) / credit_months);
}

double Overpayment(double RMT, double total_loan_amount, size_t credit_months) {
  return RMT * credit_months - total_loan_amount;
}

double Total_Payment(double RMT, size_t credit_months) {
  return RMT * credit_months;
}
