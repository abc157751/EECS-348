#include <stdio.h>
#include <string.h>

// Define a struct to hold month and sales data
typedef struct {
    char month[10];
    double sales;
} SalesData;

// Function to calculate moving average
void calculateMovingAverage(double sales[], int n, int m, double movingAvg[]) {
    double sum = 0;
    for(int i = 0; i < m; i++) {
        sum += sales[i];
        movingAvg[i] = sum / (i + 1);
    }
    for(int i = m; i < n; i++) {
        sum = sum - sales[i - m] + sales[i];
        movingAvg[i] = sum / m;
    }
}

// Function to sort and print sales from highest to lowest
void printSalesHighToLow(SalesData data[], int n) {
    SalesData temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(data[i].sales < data[j].sales) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month\t\tSales\n");
    for(int i = 0; i < n; i++) {
        printf("%s\t\t$%.2f\n", data[i].month, data[i].sales);
    }
}

int main() {
    SalesData data[12] = {
        {"January", 23458.01}, {"February", 40112.00}, {"March", 56011.85},
        {"April", 37820.88}, {"May", 37904.67}, {"June", 60200.22},
        {"July", 72400.31}, {"August", 56210.89}, {"September", 67230.84},
        {"October", 68233.12}, {"November", 80950.34}, {"December", 95225.22}
    };
    
    double sales[12], movingAvg[12];
    double totalSales = 0, avgSales;
    double minSales = data[0].sales, maxSales = data[0].sales;
    char minMonth[10], maxMonth[10];
    strcpy(minMonth, data[0].month);
    strcpy(maxMonth, data[0].month);
    
    printf("Monthly Sales Report for 2022:\n");
    printf("Month\t\tSales\n");
    for(int i = 0; i < 12; i++) {
        printf("%s\t\t$%.2f\n", data[i].month, data[i].sales);
        sales[i] = data[i].sales;
        totalSales += data[i].sales;
        if(data[i].sales < minSales) {
            minSales = data[i].sales;
            strcpy(minMonth, data[i].month);
        }
        if(data[i].sales > maxSales) {
            maxSales = data[i].sales;
            strcpy(maxMonth, data[i].month);
        }
    }
    
    avgSales = totalSales / 12;
    printf("\nSales Summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", minSales, minMonth);
    printf("Maximum sales: $%.2f (%s)\n", maxSales, maxMonth);
    printf("Average sales: $%.2f\n", avgSales);
    
    calculateMovingAverage(sales, 12, 6, movingAvg);
    printf("\nSix-Month Moving Average Report:\n");
    printf("Month\t\tMoving Average\n");
    for(int i = 5; i < 12; i++) {
        printf("%s\t\t$%.2f\n", data[i].month, movingAvg[i]);
    }
    
    printSalesHighToLow(data, 12);
    
    return 0;
}
