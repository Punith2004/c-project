#include <stdlib.h>

typedef struct vec_int_2d {
  int *element_ptr;
  int row_count;
  int col_count;
} Vec_int_2d;

Vec_int_2d create_2d_vec(int row_count, int col_count);
int get_element_2d_vec(Vec_int_2d vec, int row_index, int col_index);
void set_element_2d_vec(Vec_int_2d vec, int row_index, int col_index,
                        int value);

Vec_int_2d create_2d_vec(int row_count, int col_count) {
  Vec_int_2d return_vec = {
      .element_ptr = (int *)malloc((row_count * col_count) * sizeof(int)),
      .row_count = row_count,
      .col_count = col_count,
  };
  return return_vec;
}

int get_element_2d_vec(Vec_int_2d vec, int row_index, int col_index) {
  return vec.element_ptr[row_index * vec.col_count + col_index];
}

void set_element_2d_vec(Vec_int_2d vec, int row_index, int col_index,
                        int value) {
  vec.element_ptr[row_index * vec.col_count + col_index] = value;
}

// Program to Find the Transpose of a Matrix
#include <stdio.h>
int main() {
  Vec_int_2d a, transpose;
  int r, c, user_input_iterator;
  printf("Enter rows and columns: ");
  scanf("%d %d", &r, &c);
  a = create_2d_vec(r, c);
  transpose = create_2d_vec(c, r);

  printf("\nEnter matrix elements:\n");
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) {
      printf("Enter element a%d%d: ", i + 1, j + 1);
      scanf("%d", &user_input_iterator);
      set_element_2d_vec(a, i, j, user_input_iterator);
    }

  printf("\nEntered matrix: \n");
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) {
      printf("%d  ", get_element_2d_vec(a, i, j));
      if (j == c - 1)
        printf("\n");
    }

  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) {
      set_element_2d_vec(transpose, j, i, (get_element_2d_vec(a, i, j)));
    }

  printf("\nTranspose of the matrix:\n");
  for (int i = 0; i < c; ++i)
    for (int j = 0; j < r; ++j) {
      printf("%d  ", get_element_2d_vec(transpose, i, j));
      if (j == r - 1)
        printf("\n");
    }
  return 0;
}
