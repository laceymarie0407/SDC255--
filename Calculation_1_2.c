#include <stdio.h>





/* ------- First Calculation ------- */
void firstCalculation()
{
    int num1, num2, result;

    printf("\n--- First Calculation (Addition) ---\n");
    printf("Insert 2 numbers to add: ");
    scanf("%d %d", &num1, &num2);

    result = num1 + num2;

    printf("Addition: %d + %d = %d\n", num1, num2, result);
}

/* ------- Second Calculation ------- */
void secondCalculation()
{
    int num1, num2, result;

    printf("\n--- Second Calculation (Multiplication) ---\n");
    printf("Insert 2 numbers to multiply: ");
    scanf("%d %d", &num1, &num2);

    result = num1 * num2;

    printf("Multiply: %d and %d\n", num1, num2);
    printf("Result: %d\n", result);
}


int main() 
{ 
	firstCalculation(); 
	secondCalculation(); 
	
	return 0; 
}













