#include <stdio.h>

struct SalesPerson {
    char initial;
    char *name;
    double totalSales;
};

int main(void) {
    struct SalesPerson salespersons[] = {
        {'D', "Danielle", 0},
        {'E', "Edward", 0},
        {'F', "Francis", 0}
    };

    double grandTotal = 0;
    char highestSalesPerson = ' ';
    double highestTotal = 0;

    while (1) {
        char initial;
        printf("Enter salesperson's initial (or 'Z' to exit): ");
        scanf(" %c", &initial);
        initial = toupper(initial);

        if (initial == 'Z') {
            break;
        }

        int validInitial = 0;

        for (int i = 0; i < 3; i++) {
            if (salespersons[i].initial == initial) {
                validInitial = 1;
                printf("Enter the total amount for %s: ", salespersons[i].name);
                double saleAmount;
                scanf("%lf", &saleAmount);
                salespersons[i].totalSales += saleAmount;
                grandTotal += saleAmount;

           FILE *file = fopen("sales_data.txt", "a");
                if (file == NULL) {
                    printf("Error opening file.\n");
                    return 1;  
                }

                fprintf(file, "%c %.2f\n", initial, saleAmount);

                fclose(file);

                if (saleAmount > highestTotal) {
                    highestTotal = saleAmount;
                    highestSalesPerson = initial;
                }
                break;
            }
        }

        if (!validInitial) {
            printf("Error, invalid salesperson selected, please try again\n");
            continue;
        }
    }

    printf("Grand Total: $%.0lf\n", grandTotal);
    printf("Highest Sale: %c\n", highestSalesPerson);

    return 0;
}