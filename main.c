#include <stdio.h>
#include "root.h"
#include <math.h>
#include <string.h>

int showIter = 0;

void calcSquareRootTable() {
    double x;

    if (showIter == 0) {
        printf("   x  |  root f   |  root d   |  err\n");
        printf("------+-----------+-----------+---------\n");
    }

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
                printf(" %.2f |%.8f |%.8f | %+4.2e \n",x,f,d,err);
            }

            if( fmod(x, 1.0) == 0.75)
                printf("------+-----------+-----------+---------\n");
        }


    }
}

void calcNthRootTable() {
    int i;
    double x;
    x = 100000.00;

    while(x<10000000) {
        for(i=2;i<=8;i++) {
            double root = rootk(x,i);
            double err = power(root,i) - x;
            if(showIter == 0) {
                printf("%d-th root( %10.2f ) = %25.16f  probe: %+2.3e\n",i,x,root,err);
            }
        }
        x*=10;
        printf("\n");
    }

}

int main(int argc, char** argv) {
    if (argc > 1 && strcmp(argv[1], "-s") == 0) {
        showIter = 1;
        setShowIterations(1);
    }
    calcSquareRootTable();

    printf("\n");

    calcNthRootTable();
    return 0;
}

