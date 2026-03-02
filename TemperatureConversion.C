#include <stdio.h>
/* Lab 4 - Problem 2
 * This program converts temperatures and advises on weather conditions.
 */
// The following functions perform temperature conversions between Celsius, Fahrenheit, and Kelvin.
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

void categorize_temperature(float celsius) {
    if (celsius < 0.0) {
        printf("Category: Freezing\nAdvisory: Put coat and sweats.\n");
    } else if (celsius >= 0.0 && celsius < 10.0) {
        printf("Category: Cold\nAdvisory: Wear a jacket.\n");
    } else if (celsius >= 10.0 && celsius < 25.0) {
        printf("Category: Comfortable\nAdvisory: Shorts are ideal.\n");
    } else if (celsius >= 25.0 && celsius < 35.0) {
        printf("Category: Hot\nAdvisory: Shorts and short sleeve are a must!\n");
    } else if (celsius >= 35.0) {
        printf("Category: Extreme Heat\nAdvisory: Please attend your nearest pool!\n");
    }
}

int main() {
    // Variable declarations for temperature value, current scale, target scale, result, and intermediate Celsius value.
    float val;
    int cur;
    int target;
    float res;
    float c_val;

    printf("Enter the temperature value: ");
    scanf("%f", &val);

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &cur);

    // Kelvin cannot be negative check
    if (cur == 3) {
        if (val < 0) {
            printf("Error: Kelvin cannot be negative!\n");
            return 1;
        }
    }

    printf("Choose the target scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &target);

    if (cur == target) {
        printf("Error: Scales are the same!\n");
        return 1;
    }

   
    if (cur == 1) {
        c_val = val;
        if (target == 2) res = celsius_to_fahrenheit(val);
        if (target == 3) res = celsius_to_kelvin(val);
    } 
    else if (cur == 2) {
        c_val = fahrenheit_to_celsius(val);
        if (target == 1) res = c_val;
        if (target == 3) res = celsius_to_kelvin(c_val);
    } 
    else if (cur == 3) {
        c_val = kelvin_to_celsius(val);
        if (target == 1) res = c_val;
        if (target == 2) res = celsius_to_fahrenheit(c_val);
    }

    printf("\nConverted temperature: %.2f\n", res);
    categorize_temperature(c_val);

    return 0;
}