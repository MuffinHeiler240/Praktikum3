#include <stdio.h>
#include "root.h"

int showIterations = 0;

/*
* calculate the square root of x in single precision .
* @param x a positiv real number.
* @return square root of x (or ERROR)
*/
float rootf (float x) {
    float xn = x;    /* Startwert */
    float delta;     /* Unterschied zwischen den letzten beiden Näherungen */
    int n = 0;       /* Iterationszähler */

    if (x < 0)
        return ERROR; /* Fehler bei negativer Eingabe */
    if (x == 0)
        return 0;

    do {
        float xn1 = xn-(xn*xn-x)/(2*xn);   /* Nächste Näherung berechnen */
        delta = (xn1 > xn) ? (xn1 - xn) : (xn - xn1);  /* Betrag der Differenz */
        xn = xn1;    /* Update xn für die nächste Iteration */
        n++;

        /* Ausgabe der Zwischenwerte, falls aktiviert */
        if (showIterations) {
            printf("float  x = %10.2f   k=%4d  ite:%4d    xn:%18.10f    delta:%18.10f\n",x,2,n, xn, delta);
        }

    } while (delta > EPSFLOAT && n < MAX);  /* Abbruchkriterium */

    if (n >= MAX) {
        printf("Keine Konvergenz erreicht!\n");
        return ERROR;
    }

    return xn; /* Quadratwurzel mit gewünschter Genauigkeit */
}

/*
* calculate the square root of x in double precision .
* @param x a positiv real number.
* @return square root of x (or ERROR)
*/
double rootd (double x) {
    double xn = x;    /* Startwert */
    double delta;     /* Unterschied zwischen den letzten beiden Näherungen */
    int n = 0;        /* Iterationszähler */

    if (x < 0)
        return ERROR; /* Fehler bei negativer Eingabe */
    if (x == 0)
        return 0;

    do {
        double xn1 = xn-(xn*xn-x)/(2*xn);   /* Nächste Näherung berechnen */
        delta = (xn1 > xn) ? (xn1 - xn) : (xn - xn1);  /* Betrag der Differenz */
        xn = xn1;    /* Update xn für die nächste Iteration */
        n++;

        /* Ausgabe der Zwischenwerte, falls aktiviert */
        if (showIterations) {
            printf("double x = %10.2f   k=%4d  ite:%4d    xn:%18.10f    delta:%18.10f\n",x,2,n, xn, delta);
        }

    } while (delta > EPSDOUBLE && n < MAX);  /* Abbruchkriterium */

    if (n >= MAX) {
        printf("Keine Konvergenz erreicht!\n");
        return ERROR;
    }

    return xn; /* Quadratwurzel mit gewünschter Genauigkeit */
}

double rootk(double x,int k) {
    double xn = x;    /* Startwert */
    double delta;     /* Unterschied zwischen den letzten beiden Näherungen */
    int n = 0;        /* Iterationszähler */

    if (x < 0)
        return ERROR; /* Fehler bei negativer Eingabe */
    if (x == 0)
        return 0;

    do {
        double xn1 = xn-(power(xn,k)-x)/(k*power(xn,k-1));  /* Nächste Näherung berechnen */
        delta = (xn1 > xn) ? (xn1 - xn) : (xn - xn1);  /* Betrag der Differenz */
        xn = xn1;    /* Update xn für die nächste Iteration */
        n++;

        /* Ausgabe der Zwischenwerte, falls aktiviert */
        if (showIterations) {
            printf("double x = %10.2f   k=%4d  ite:%4d    xn:%18.10f    delta:%18.10f\n",x,k,n, xn, delta);
        }

    } while (delta > EPSDOUBLE && n < MAX);  /* Abbruchkriterium */

    if (n >= MAX) {
        printf("Keine Konvergenz erreicht!\n");
        return ERROR;
    }

    return xn; /* Quadratwurzel mit gewünschter Genauigkeit */
}

double power(double x, int k) {
    double result = 1;
    int i;
    for (i = 0; i < k; i++) {
        result *= x;
    }
    return result;
}

void setShowIterations(int flag) {
    showIterations = flag;
}