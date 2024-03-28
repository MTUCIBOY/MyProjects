#include "back.h"

enum period { DAY = 0, MONTH = 1 };

double deposit(double amount, double procent, size_t type) {
  switch (type) {
    case DAY:
      procent /= 365;
      break;
    case MONTH:
      procent /= 12;
      break;
  }

  return (amount / 100) * procent;
}

double taxies(double earn, double S0) {
  double tax = earn - S0;

  if (tax > 0)
    tax *= 0.13;
  else
    tax = 0;

  return tax;
}
