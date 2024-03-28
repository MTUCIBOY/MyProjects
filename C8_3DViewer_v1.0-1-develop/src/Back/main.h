/*!
 * \file
 * \brief Back headerfile.
 *
 * \details Here all libs, structs and declaration functions used in back part
 * of project
 *
 * Move functions are used to MovePoints the shape along the OX, OY and OZ axes.
 * The functions take a pointer to a variable of dots type, cyclically change
 * the Points.
 *
 * Turn functions are used to rotate the figure. If the rotation is along
 * the OZ axis, then X and Y Points change, if OY, then XZ and if OX, then YZ.
 * The functions take a pointer to a variable of the dots type.
 *
 * The zoom functions are used to change the scale of the figure. They take a
 * pointer to a variable of the dots type.
 */
#ifndef MAIN_H
#define MAIN_H

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
 * \brief substructure for Points struct.
 *  Used for store coordinates from .obj file
 */
typedef struct {
  double x;
  double y;
  double z;
} dot;

/*!
 * \brief Structure for storing V variables from .obj file
 *
 * \param quantity - num of points
 * \param coordinates - pointer of dot mas.
 */
typedef struct {
  unsigned int quantity;
  dot *coordinates;
} Points;

/*!
 * \brief Structure for storing F variables from .obj file
 *
 * \param quantity - num of Poin
 * ts
 * \param facet_matrix - matrix of vactors for F variables
 */
typedef struct {
  unsigned int quantity;
  unsigned int lines_quantity;
  int *facet_matrix;
} Facets;

/*!
 * \brief Move function
 *
 * \param A - pointer on coordinates
 * \param x - MovePoints value OX axis
 * \param y - MovePoints value OY axis
 * \param z - MovePoints value OZ axis
 */
void MovePoints(Points *A, double x, double y, double z);
/*!
 * \brief Turn function
 *
 * \param A - pointer on coordinates
 * \param OX - degree by which the figure should be rotated along the OX axis
 * \param OY - degree by which the figure should be rotated along the OY axis
 * \param OZ - degree by which the figure should be rotated along the OZ axis
 */
void turn(Points *A, double OX, double OY, double OZ);
/*!
 * \brief Zoom function
 *
 * \param A - pointer on coordinates
 * \param scale - value scale + 1; scale < 1 == zoom out; scale > 1 == zoom in
 */
void zoom(Points *A, double scale);
/*!
 * \brief Function for finding minimal and maximal value of coordinate
 *
 * \param A - pointer on coordinates
 * \param nums - pointer on result; nums[0] - min, nums[1] - max
 * \paran axis - which axis coords; 0 - OX, 1 - OY, 2 - OZ
 */
void minmax(Points *A, double *nums, size_t axis);
/*!
 * \brief Function for center our figure and scale it on 0.7
 *
 * \param A - pointer on coordinates
 */
void CenterAndScaleCoords(Points *A);

/*!
 * \brief Parser function that reads information from an object file
 *
 * \param filename - name of file
 * \param to_put_points - pointer on Points, read V string
 * \param to_put_facets - pointer on Facets, read F string
 */
void parser(char *filename, Points **to_put_points, Facets **to_put_facets);

/*!
 * \brief Free function for Points and Facets structs
 */
void clean_points_and_facets(Points **to_put_points, Facets **to_put_facets);

#endif  // MAIN_H
