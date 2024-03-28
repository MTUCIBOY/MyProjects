#include <math.h>

int sum_day(int term) {
  int day_sum = 0;
  int day_num = 0;
  int term_tmp = 0;

  for (int j = term; j > 0; j -= 12) {
    if (j > 12)
      term_tmp = 12;
    else
      term_tmp = j;

    for (int i = 1; i <= term_tmp; i++) {
      if (i < 8) {
        if (i % 2) {
          day_num = 31;
          day_sum += day_num;
        } else {
          day_num = (i == 2) ? 28 : 30;
          day_sum += day_num;
        }
      } else {
        if (i % 2) {
          day_num = 30;
          day_sum += day_num;
        } else {
          day_num = 31;
          day_sum += day_num;
        }
      }
    }
  }

  return day_sum;
}

int bank_credit(double amount, double term, double percent, double* month_pay,
                double* overpay, double* total) {
  double mps = percent / (100 * term);

  double amount_tmp = amount;

  *month_pay =
      amount * ((mps * pow((1 + mps), term)) / (pow((1 + mps), term) - 1));

  *overpay = 0;

  double overpay_tmp = 0;

  for (double i = 0; i < term + 1; i += 1) {
    overpay_tmp = amount_tmp * mps;
    *overpay += overpay_tmp;
    amount_tmp -= (*month_pay - overpay_tmp);
  }

  *total = *overpay + amount;
}

int bank_deposit(double amount, double term, double percent, int capitalization,
                 double* amount_end, double* income) {
  *amount_end = 0;
  *income = 0;

  if (capitalization == 0) {
    double mps = (percent / 100) / 12;
    *amount_end = amount * pow(1 + mps, term);
    *income = *amount_end - amount;
  } else {
    int day_sum = sum_day((int)term);
    *income = (amount * percent * day_sum / 365) / 100;
    *amount_end = amount + *income;
  }
  return 0;
}
