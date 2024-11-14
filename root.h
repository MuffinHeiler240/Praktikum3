#define ERROR -1 /* indicate an error */
#define MAX 256 /* maximal number of iterations */
#define EPSFLOAT 1.E-4F /* float precision to reach */
#define EPSDOUBLE 1.E-8 /* double precision to reach */
#define dabs(x) ((x)<0?-(x):(x)) /* absolute value of x */

/*
* calculate the square root of x in single precision .
* @param x a positiv real number.
* @return square root of x (or ERROR)
*/
float rootf (float x);

/*
* calculate the square root of x in double precision .
* @param x a positiv real number.
* @return square root of x (or ERROR)
*/
double rootd(double x);

/* show immediate results or not */
void setShowIterations(int flag);