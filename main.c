#include <stdio.h>
#include "root.h"
#include <math.h>
#include <string.h>

int showIter = 0;

void calcSquareRootTable() {
    double x;

    printf("   x  |  root f   |  root d   |  err\n");
    printf("------+-----------+-----------+---------\n");

    for(x=0; x<=4; x+=0.25) {
        double d, err;
        float f;

        f = rootf(x);
        d = rootd(x);

        if(showIter == 0) {
            if(f == ERROR || d == ERROR) {
                printf("%.2f | Bei der Berechnung kam es zu einem Fehler! \n",x);
            }
            else {
                err = d-f;
                printf(" %.2f |%.8f |%.8f | %.2e \n",x,f,d,err);
            }

            if( fmod(x, 1.0) == 0.75)
                printf("------+-----------+-----------+---------\n");
        }


    }
}

int main(int argc, char** argv) {
    if (argc > 1 && strcmp(argv[1], "-s") == 0) {
        showIter = 1;
        setShowIterations(1);
    }
    calcSquareRootTable();
    return 0;
}

