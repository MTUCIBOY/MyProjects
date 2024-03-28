#include <check.h>

#include "Back/main.h"

const dot V[] = {{1, -1, -1}, {1, -1, 1}, {-1, -1, 1}, {-1, -1, -1},
                 {1, 1, -1},  {1, 1, 1},  {-1, 1, 1},  {-1, 1, -1}};

START_TEST(Test1) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  Points A = {8, mas};

  MovePoints(&A, 0.1, 0, 0);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x + 0.1);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z);
  }
}
END_TEST

START_TEST(Test2) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  Points A = {8, mas};

  MovePoints(&A, -0.1, 0, 0);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x - 0.1);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z);
  }
}
END_TEST

START_TEST(Test3) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  Points A = {8, mas};

  MovePoints(&A, 0, 0.1, 0);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y + 0.1);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z);
  }
}
END_TEST

START_TEST(Test4) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  Points A = {8, mas};

  MovePoints(&A, 0, -0.1, 0);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y - 0.1);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z);
  }
}
END_TEST

START_TEST(Test5) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  Points A = {8, mas};

  MovePoints(&A, 0, 0, -0.1);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z - 0.1);
  }
}
END_TEST

START_TEST(Test6) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  Points A = {8, mas};

  MovePoints(&A, 0, 0, 0.1);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z + 0.1);
  }
}
END_TEST

START_TEST(Test7) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  Points A = {8, mas};

  zoom(&A, 0.1);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x * 1.1);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y * 1.1);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z * 1.1);
  }
}
END_TEST

START_TEST(Test8) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  Points A = {8, mas};

  zoom(&A, -0.1);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x * 0.9);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y * 0.9);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z * 0.9);
  }
}
END_TEST

START_TEST(Test9) {
  double degree = (15 * M_PI) / 180.0;
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  Points A = {8, mas};

  turn(&A, 0, 0, 15);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x,
                       V[i].x * cos(degree) + V[i].y * sin(degree));
    ck_assert_float_eq(A.coordinates[i].y,
                       V[i].x * -sin(degree) + V[i].y * cos(degree));
    ck_assert_float_eq(A.coordinates[i].z, V[i].z);
  }
}
END_TEST

START_TEST(Test10) {
  double degree = (15 * M_PI) / 180.0;
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  Points A = {8, mas};

  turn(&A, 15, 0, 0);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x);
    ck_assert_float_eq(A.coordinates[i].y,
                       V[i].z * -sin(degree) + V[i].y * cos(degree));
    ck_assert_float_eq(A.coordinates[i].z,
                       V[i].z * cos(degree) + V[i].y * sin(degree));
  }
}
END_TEST

START_TEST(Test11) {
  double degree = (15 * M_PI) / 180.0;
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  Points A = {8, mas};

  turn(&A, 0, 15, 0);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x,
                       V[i].x * cos(degree) + V[i].z * sin(degree));
    ck_assert_float_eq(A.coordinates[i].y, V[i].y);
    ck_assert_float_eq(A.coordinates[i].z,
                       V[i].x * -sin(degree) + V[i].z * cos(degree));
  }
}
END_TEST

START_TEST(Test12) {
  dot V1[] = {{10, -3, -2},  {1, -2, 3}, {-4, -5, 6}, {-7, -8, -9},
              {10, 11, -12}, {1, 2, 3},  {-4, 5, 6},  {-7, 8, -9}};
  Points A = {8, V1};
  double nums[2];

  minmax(&A, nums, 0);
  ck_assert_double_eq(-7, nums[0]);
  ck_assert_double_eq(10, nums[1]);
  minmax(&A, nums, 1);
  ck_assert_double_eq(-8, nums[0]);
  ck_assert_double_eq(11, nums[1]);
  minmax(&A, nums, 2);
  ck_assert_double_eq(-12, nums[0]);
  ck_assert_double_eq(6, nums[1]);
}
END_TEST

START_TEST(Test13) {
  dot V1[] = {{10, -3, -2},  {1, -2, 3}, {-4, -5, 6}, {-7, -8, -9},
              {10, 11, -12}, {1, 2, 3},  {-4, 5, 6},  {-7, 8, -9}};
  Points A = {8, V1};

  CenterAndScaleCoords(&A);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_double_ge(A.coordinates[i].x, -1);
    ck_assert_double_ge(A.coordinates[i].y, -1);
    ck_assert_double_ge(A.coordinates[i].z, -1);
    ck_assert_double_le(A.coordinates[i].x, 1);
    ck_assert_double_le(A.coordinates[i].y, 1);
    ck_assert_double_le(A.coordinates[i].z, 1);
  }
}

START_TEST(Test14) {
  Points *V_value = NULL;
  Facets *F_value = NULL;

  parser("objects/cube.objs", &V_value, &F_value);
  ck_assert_double_eq(V_value->coordinates[0].x, 0);
  ck_assert_double_eq(V_value->coordinates[0].y, 0);
  ck_assert_double_eq(V_value->coordinates[0].z, 0);
  ck_assert_double_eq(V_value->coordinates[1].x, 0);
  ck_assert_double_eq(V_value->coordinates[1].y, 0);
  ck_assert_double_eq(V_value->coordinates[1].z, 2);
  ck_assert_double_eq(V_value->coordinates[2].x, 0);
  ck_assert_double_eq(V_value->coordinates[2].y, 2);
  ck_assert_double_eq(V_value->coordinates[2].z, 0);
  ck_assert_double_eq(V_value->coordinates[3].x, 0);
  ck_assert_double_eq(V_value->coordinates[3].y, 2);
  ck_assert_double_eq(V_value->coordinates[3].z, 2);
  ck_assert_double_eq(V_value->coordinates[4].x, 2);
  ck_assert_double_eq(V_value->coordinates[4].y, 0);
  ck_assert_double_eq(V_value->coordinates[4].z, 0);
  ck_assert_double_eq(V_value->coordinates[5].x, 2);
  ck_assert_double_eq(V_value->coordinates[5].y, 0);
  ck_assert_double_eq(V_value->coordinates[5].z, 2);
  ck_assert_double_eq(V_value->coordinates[6].x, 2);
  ck_assert_double_eq(V_value->coordinates[6].y, 2);
  ck_assert_double_eq(V_value->coordinates[6].z, 0);
  ck_assert_double_eq(V_value->coordinates[7].x, 2);
  ck_assert_double_eq(V_value->coordinates[7].y, 2);
  ck_assert_double_eq(V_value->coordinates[7].z, 2);

  ck_assert_int_eq(F_value->facet_matrix[0], 0);
  ck_assert_int_eq(F_value->facet_matrix[1], 6);
  ck_assert_int_eq(F_value->facet_matrix[2], 6);
  ck_assert_int_eq(F_value->facet_matrix[3], 4);
  ck_assert_int_eq(F_value->facet_matrix[4], 0);
  ck_assert_int_eq(F_value->facet_matrix[5], 2);
  ck_assert_int_eq(F_value->facet_matrix[6], 2);
  ck_assert_int_eq(F_value->facet_matrix[7], 6);
  ck_assert_int_eq(F_value->facet_matrix[8], 0);
  ck_assert_int_eq(F_value->facet_matrix[9], 3);
  ck_assert_int_eq(F_value->facet_matrix[10], 3);
  ck_assert_int_eq(F_value->facet_matrix[11], 2);
  ck_assert_int_eq(F_value->facet_matrix[12], 0);
  ck_assert_int_eq(F_value->facet_matrix[13], 1);
  ck_assert_int_eq(F_value->facet_matrix[14], 1);
  ck_assert_int_eq(F_value->facet_matrix[15], 3);
  ck_assert_int_eq(F_value->facet_matrix[16], 2);
  ck_assert_int_eq(F_value->facet_matrix[17], 7);
  ck_assert_int_eq(F_value->facet_matrix[18], 7);
  ck_assert_int_eq(F_value->facet_matrix[19], 6);
  ck_assert_int_eq(F_value->facet_matrix[20], 2);
  ck_assert_int_eq(F_value->facet_matrix[21], 3);
  ck_assert_int_eq(F_value->facet_matrix[22], 3);
  ck_assert_int_eq(F_value->facet_matrix[23], 7);
  ck_assert_int_eq(F_value->facet_matrix[24], 4);
  ck_assert_int_eq(F_value->facet_matrix[25], 6);
  ck_assert_int_eq(F_value->facet_matrix[26], 6);
  ck_assert_int_eq(F_value->facet_matrix[27], 7);
  ck_assert_int_eq(F_value->facet_matrix[28], 4);
  ck_assert_int_eq(F_value->facet_matrix[29], 7);
  ck_assert_int_eq(F_value->facet_matrix[30], 7);
  ck_assert_int_eq(F_value->facet_matrix[31], 5);
  ck_assert_int_eq(F_value->facet_matrix[32], 0);
  ck_assert_int_eq(F_value->facet_matrix[33], 4);
  ck_assert_int_eq(F_value->facet_matrix[34], 4);
  ck_assert_int_eq(F_value->facet_matrix[35], 5);
  ck_assert_int_eq(F_value->facet_matrix[36], 0);
  ck_assert_int_eq(F_value->facet_matrix[37], 5);
  ck_assert_int_eq(F_value->facet_matrix[38], 5);
  ck_assert_int_eq(F_value->facet_matrix[39], 1);
  clean_points_and_facets(&V_value, &F_value);
}
END_TEST

int main() {
  Suite *suite = suite_create("Unit");
  TCase *tcase = tcase_create("Tests");
  SRunner *srunner = srunner_create(suite);
  int counted_errors = 0;

  suite_add_tcase(suite, tcase);

  tcase_add_test(tcase, Test1);
  tcase_add_test(tcase, Test2);
  tcase_add_test(tcase, Test3);
  tcase_add_test(tcase, Test4);
  tcase_add_test(tcase, Test5);
  tcase_add_test(tcase, Test6);
  tcase_add_test(tcase, Test7);
  tcase_add_test(tcase, Test8);
  tcase_add_test(tcase, Test9);
  tcase_add_test(tcase, Test10);
  tcase_add_test(tcase, Test11);
  tcase_add_test(tcase, Test12);
  tcase_add_test(tcase, Test13);
  tcase_add_test(tcase, Test14);

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? 0 : 1;
}
