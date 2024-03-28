#include "main.h"

// Function to open a file and return a pointer to it.
FILE *open_file(const char *file_name) {
  FILE *file_pointer = fopen(file_name, "r");
  if (file_pointer == NULL) {
    perror("Error opening file");
    fprintf(stderr, "Failed to open file: %s\n", file_name);
  }
  return file_pointer;
}

// Function to count the number of points and facets in a file.
bool get_quantity_of_points_and_facets(FILE *file_pointer,
                                       Points **to_put_points,
                                       Facets **to_put_facets) {
  if (file_pointer == NULL) {
    return false;
  }

  int facets_in_lines = 0;
  char buffer[100] = {0};
  (*to_put_points)->quantity = 0;
  (*to_put_facets)->quantity = 0;

  while (fgets(buffer, sizeof(buffer), file_pointer)) {
    if (buffer[0] == 'v' && buffer[1] == ' ') {
      (*to_put_points)->quantity++;
    } else if (buffer[0] == 'f' && buffer[1] == ' ') {
      char *token = strtok(buffer + 2, " ");
      while (token != NULL) {
        if (isdigit(token[0])) {
          facets_in_lines++;
          (*to_put_facets)->quantity += 2;
        }
        token = strtok(NULL, " ");
      }
      if (facets_in_lines >= 2) {
        (*to_put_facets)->quantity -= 2;
      }
      facets_in_lines = 0;
    }
  }
  return true;
}

// Function to allocate memory for points and facets based on their quantities.
bool allocate_points_and_facets(char *file_name, Points **to_put_points,
                                Facets **to_put_facets) {
  FILE *file_pointer = open_file(file_name);
  if (!file_pointer) {
    return false;
  }

  if (get_quantity_of_points_and_facets(file_pointer, &(*to_put_points),
                                        &(*to_put_facets))) {
    (*to_put_points)->coordinates =
        (dot *)malloc(sizeof(dot) * (*to_put_points)->quantity);
    (*to_put_facets)->facet_matrix =
        (int *)malloc(sizeof(int) * ((*to_put_facets)->quantity * 2));
    if (!(*to_put_facets)->facet_matrix) {
      fprintf(stderr, "Failed to allocate memory for facet matrix\n");
      exit(1);
    }
  }
  fclose(file_pointer);  // Close the file after reading the quantities
  return true;
}

char *dtoc(char *str) {
  char *head_str = str;
  while (*str) {
    if (*str == '.') {
      *str = ',';
      break;
    }
    str++;
  }

  return head_str;
}

dot parsing_str(char str[]) {
  dot result;
  strtok(str, "  ");
  result.x = atof(dtoc(strtok(NULL, "  ")));
  result.y = atof(dtoc(strtok(NULL, "  ")));
  result.z = atof(dtoc(strtok(NULL, "  ")));

  return result;
}

// Function to fill the allocated structures with point and facet data from the
// file.
bool fill_points_and_facets(char *filename, Points *to_put_points,
                            Facets *to_put_facets) {
  FILE *file_pointer = open_file(filename);
  if (!file_pointer) {
    return false;
  }

  char buffer[100] = {100};
  int index_of_facets = 0, index_of_points = 0;

  while (fgets(buffer, sizeof(buffer), file_pointer)) {
    if (buffer[0] == 'v' && buffer[1] == ' ') {
      to_put_points->coordinates[index_of_points++] = parsing_str(buffer);
    } else if (buffer[0] == 'f' && buffer[1] == ' ') {
      char *token = strtok(buffer + 2, " ");
      int previous = atoi(token) - 1;
      token = strtok(NULL, " ");
      while (token != NULL) {
        int current = atoi(token) - 1;
        to_put_facets->facet_matrix[index_of_facets++] = previous;
        to_put_facets->facet_matrix[index_of_facets++] = current;
        previous = current;
        token = strtok(NULL, " ");
      }
    }
  }
  fclose(file_pointer);  // Close the file after processing
  return true;
}

void clean_points_and_facets(Points **to_put_points, Facets **to_put_facets) {
  if (to_put_points && *to_put_points) {  // Check if the pointer and the
                                          // pointed-to data are valid
    free(
        (*to_put_points)
            ->coordinates);  // Free the dynamically allocated coordinates array
    free(*to_put_points);    // Free the Points structure itself
    *to_put_points = NULL;   // Set the caller's pointer to NULL
  }
  if (to_put_facets && *to_put_facets) {   // Check if the pointer and the
                                           // pointed-to data are valid
    free((*to_put_facets)->facet_matrix);  // Free the dynamically allocated
                                           // facet_matrix array
    free(*to_put_facets);                  // Free the Facets structure itself
    *to_put_facets = NULL;                 // Set the caller's pointer to NULL
  }
}

void parser(char *filename, Points **to_put_points, Facets **to_put_facets) {
  *to_put_points = (Points *)malloc(sizeof(Points));
  (*to_put_points)->quantity = 0;
  *to_put_facets = (Facets *)malloc(sizeof(Facets));
  (*to_put_facets)->quantity = 0;
  allocate_points_and_facets(filename, to_put_points, to_put_facets);
  fill_points_and_facets(filename, *to_put_points, *to_put_facets);
}

/* void print_Points(Points *A) {
  printf("Point quantity: %d\n", A->quantity);
  for (unsigned int i = 0; i < A->quantity; i++)
    printf("%d: %lf %lf %lf\n", i, A->coordinates[i].x, A->coordinates[i].y,
           A->coordinates[i].z);
  printf("\n");
}

void print_Facetes(Facets *A) {
  printf("Facets quantity: %d\n", A->quantity);
  for (unsigned int i = 0; i < A->quantity; i += 4) {
    printf("%d: %d %d %d %d\n", i / 4, A->facet_matrix[i],
           A->facet_matrix[i + 1], A->facet_matrix[i + 2],
           A->facet_matrix[i + 3]);
  }
  printf("\n");
} */
