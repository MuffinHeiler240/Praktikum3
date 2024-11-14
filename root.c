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
        float xn1 = (xn + x / xn) / 2;   /* Nächste Näherung berechnen */
        delta = (xn1 > xn) ? (xn1 - xn) : (xn - xn1);  /* Betrag der Differenz */
        xn = xn1;    /* Update xn für die nächste Iteration */
        n++;

        /* Ausgabe der Zwischenwerte, falls aktiviert */
        if (showIterations) {
            printf("float  x = %.2f   ite:%d    xn:%.6f        delta:%.8f\n", x, n, xn, delta);
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
        double xn1 = (xn + x / xn) / 2;   /* Nächste Näherung berechnen */
        delta = (xn1 > xn) ? (xn1 - xn) : (xn - xn1);  /* Betrag der Differenz */
        xn = xn1;    /* Update xn für die nächste Iteration */
        n++;

        /* Ausgabe der Zwischenwerte, falls aktiviert */
        if (showIterations) {
            printf("double x = %.2f   ite:%d    xn:%.10f    delta:%.10f\n",x, n, xn, delta);
        }

    } while (delta > EPSFLOAT && n < MAX);  /* Abbruchkriterium */

    if (n >= MAX) {
        printf("Keine Konvergenz erreicht!\n");
        return ERROR;
    }

    return xn; /* Quadratwurzel mit gewünschter Genauigkeit */
}

void setShowIterations(int flag) {
    showIterations = flag;
}