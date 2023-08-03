#include <stdio.h>
#include <ctype.h>

float soma(float a, float b);
float sub(float a, float b);
float div (float a, float b);
float mult (float a, float b);
float calcula (float a, float b, char op);

int main()
{
	float a, b, c, resultado;
	char op;
		printf("Calculadora\nDigite a operação desejada:");
		scanf("%f %c %f", &a, &op, &b);

		resultado = calcula(a, b, op);
		printf("\nResultado: %.1f\n", resultado);
		printf("Digite um numero para encerrar\n");
		scanf("%f", &c);
		return 0;
}

float calcula(float a, float b, char op)
{
	float resultado;
	
	switch(op)
	{
	case '+':
		resultado = soma(a, b);
		return resultado;
		break;
	case '-':
		resultado = sub(a, b);		
		return resultado;
		break;
	case '/':
		resultado = div(a, b);
		return resultado;
		break;
	case '*':
		resultado = mult(a, b);
		return resultado;
		break;
	
	default:
		printf("Caracter invalido!");

	break;	
	}
}

float soma (float a, float b)
{
	float resultado;
	resultado = a + b;
	return resultado;
}

float sub (float a, float b)
{
	float resultado;
	resultado = a - b;
	return resultado;
}

float div (float a, float b)
{
	float resultado;
	resultado = a / b;
	return resultado;
}

float mult (float a, float b)
{
	float resultado;
	resultado = a * b;
	return resultado;
}

