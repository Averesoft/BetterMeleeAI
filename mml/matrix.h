/**
 * @file matrix.h
 * @brief Support for matrix and vector operations
 */

/** @example matrixExample.c
 * This demonstrates the basic uses of matrix.h
 */

#ifndef MML_MATRIX_H
#define MML_MATRIX_H

#include "gctypes.h"

/** @brief Set to true when a error occurs in a matrix operation **/
extern bool _matrixError;

/** @brief A vector of 32-bit floating-point values */
typedef struct
{
    float* data; /**< array of floating-point values */
    size_t size; /**< size of @c data */

} Vector;

/** @brief A matrix of 32-bit floating-point values */
typedef struct
{
    float** data; /**< two-dimensional array of floating-point values */
    size_t nRow; /**< number of rows in the matrix */
    size_t nCol; /**< number of columns in the matrix */

} Matrix;

/** Extract a row from @c mat as a @c Vector struct */
#define ROW_VECTOR(mat, ndx)   ((Vector) {mat.data[ndx], mat.nCol})

/**
 * @brief Initialize a Vector. 
 * @ingroup CallsMalloc
 *
 * @param vec - pointer to a Vector struct
 * @param size - number of values in the vector
 *
 * @return @c false if memory allocation fails, @c true otherwise
 */
bool initVector(Vector* vec, size_t size);

/**
 * @brief Initialize a matrix. 
 * @ingroup CallsMalloc
 *
 * @param mat - pointer to a Matrix struct
 * @param numRows - number of rows in the matrix 
 * @param numCols - number of columns in the matrix
 *
 * @return @c false if memory allocation fails, @c true otherwise
 */
bool initMatrix(Matrix* mat, size_t numRows, size_t numCols);

/**
 * @brief Populate the values in a vector
 *
 * This function populates each element in the vector
 * based on @c func. Element @c n will be equal to <tt> func(n) </tt>.
 *
 * @param vec - pointer to a Vector struct
 * @param func - pointer to a function of the form <tt> float foo(u32) </tt>
 *
 * @return None.
 */
void populateVec(Vector* vec, void* func);

/**
 * @brief Populate the values in a matrix
 *
 * This function populates each element in the matrix
 * based on @c func. The element at <tt> [row][col] </tt> will be equal
 * to <tt> func(row, col) </tt>.
 *
 * @param mat - pointer to a Matrix struct
 * @param func - pointer to a function of the form
 *  <tt> float foo(u32, u32) </tt>
 *
 * @return None.
 */
void populateMat(Matrix* mat, void* func);

/**
 * @brief Multiplication of the form <tt> y = Ax </tt>
 *
 * This function multiplies <tt> Ax </tt> and stores the result in @c y.
 *
 * @param y - pointer to Vector struct
 * @param A - pointer to Matrix struct
 * @param x - pointer to Vector struct
 *
 * @return none
 *
 * @note This function uses specific optimizations for the Wii hardware
 * @see http://wiibrew.org/wiki/Paired_single
 */
void matrixVectorProduct(Vector* y, const Matrix* A, const Vector* x);

/**
 * @brief Calculates the dot product of two vectors.
 *
 * @param u - pointer to a Vector struct
 * @param v - pointer to a Vector struct
 *
 * @return The standard dot product of @c u and @c v.
 *
 * @note This function uses specific optimizations for the Wii hardware
 * @see http://wiibrew.org/wiki/Paired_single
 */
float vectorDotProd(const Vector* u, const Vector* v);

#endif
