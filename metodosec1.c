#include <stdio.h>
#include <math.h>
double funcion1(double x) {
    return sin(x) + cos(x) - pow(x, 2) + 2 * x;
}

double funcion2(double x) {
    return pow(x, 3) - x - 1;
}

double funcion3(double x) {
    return log(x) + pow(x, 2) - 4;
}

int main() {
    double x0, x1, xi, f_x0, f_x1, f_xi, tol;
    int max_iter, iter = 0, seleccion;
    double (*f)(double); 

    printf("Seleccione la funcion:\n");
    printf("1: f(x) = sin(x) + cos(x) - x^2 + 2x\n");
    printf("2: f(x) = x^3 - x - 1\n");
    printf("3: f(x) = log(x) + x^2 - 4\n");
    printf("Ingrese el numero de la funcion: ");
    scanf("%d", &seleccion);

    switch (seleccion) {
        case 1:
            f = funcion1;
            break;
        case 2:
            f = funcion2;
            break;
        case 3:
            f = funcion3;
            break;
        default:
            printf("Opcion no valida. Saliendo...\n");
            return 1;
    }

    printf("Ingrese el valor de x0: ");
    scanf("%lf", &x0);
    printf("Ingrese el valor de x1: ");
    scanf("%lf", &x1);

    
    printf("Ingrese el numero maximo de iteraciones: ");
    scanf("%d", &max_iter);

    tol = 0.0001;

    printf("\nMetodo de la Secante\n");
    printf("Iteracion\tx0\t\tx1\t\txi\t\tf(xi)\t\tError\n");

    do {
        f_x0 = f(x0);
        f_x1 = f(x1);

        xi = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);
        f_xi = f(xi);

        double error = fabs((xi - x1) / xi) * 100;

    
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f%%\n", iter + 1, x0, x1, xi, f_xi, error);

        x0 = x1;
        x1 = xi;
        iter++;

        if (error < tol) {
            break;
        }

    } while (iter < max_iter);

    printf("\nAproximacion de la raiz: %.6f\n", xi);
    printf("Se encontro en %d iteraciones\n", iter);

    return 0;
}
