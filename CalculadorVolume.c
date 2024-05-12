#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>

int main()
{
	
	setlocale(LC_ALL,"Portuguese");
	
	char language[20];
	int option;
	float length, width, high, side, radius;
	float paralelepiped_volume, cube_volume, sphere_volume;
	
	while(1)
	{
		system("cls");
	 	printf("> Portuguese\n");
	 	printf("> English\n\n");
	 	printf("Select your language: ");
	 	scanf("%s", &language);
	 	
	 		if(strcmp(language, "Portuguese") == 0 || strcmp(language, "portuguese") == 0)
	 		{
	 			while(1)
	 			{
 				system("cls");
	 			printf("-------------------------\n");
	 			printf("   CALCULADOR DE VOLUME\n");
	 			printf("-------------------------\n\n");
	 			
	 			printf("1. Paralelepípedo\n");
	 			printf("2. Cubo\n");
	 			printf("3. Esfera\n");
	 			printf("4. Sair\n\n");
	 			
	 			printf("Selecione uma opção: ");
	 			scanf("%d", &option);
	 			
	 			switch(option)
	 			{
	 				case 1:
	 					system("cls");
	 					printf("Opção selecionada: Paralelepípedo.\n\n");
	 					
	 					printf("Valor da altura: ");
	 					scanf("%f", &high);
	 					printf("Valor da largura: ");
	 					scanf("%f", &width);
	 					printf("Valor do comprimento: ");
	 					scanf("%f", &length);
	 					
	 					paralelepiped_volume = high * width * length;
	 					
	 					system("cls");
	 					printf("O volume do paralelepípedo é de %.2fm³\n\n", paralelepiped_volume);
	 					system("pause");
	 					continue;
 					case 2:
 						system("cls");
 						printf("Opção selecionada: Cubo.\n\n");
 						
 						printf("Informe o valor do lado: ");
 						scanf("%f", &side);
 						
 						cube_volume = pow(side, 3);
 						
 						system("cls");
 						printf("O volume do cubo é de %.2fm³\n\n");
 						system("pause");
 						continue;
					case 3:
						system("cls");
						printf("Opção selecionada: Esfera.\n\n");
						
						printf("Informe o valor do raio da esfera: ");
						scanf("%f", &radius);
						
						sphere_volume = (4 * M_PI * pow(radius, 3)) / 3;
						
						system("cls");
						printf("O volume da esfera é de %.2fm³\n\n");
						system("pause");
						continue;
					case 4:
						system("cls");
						printf("Até logo!!!\n\n");
						system("pause");
						break;
					default:
						system("cls");
						printf("Opção inválida. Tente novamente.\n\n");
						system("pause");
						continue;
				 }
				 break;
				 }
			 } else if(strcmp(language, "English") == 0 || strcmp(language, "english") == 0)
			 {
			 	while(1)
	 			{
 				system("cls");
	 			printf("-------------------------\n");
	 			printf("    VOLUME CALCULATOR\n");
	 			printf("-------------------------\n\n");
	 			
	 			printf("1. Paralelepiped\n");
	 			printf("2. Cube\n");
	 			printf("3. Sphere\n");
	 			printf("4. Exit\n\n");
	 			
	 			printf("Select an option: ");
	 			scanf("%d", &option);
	 			
	 			switch(option)
	 			{
	 				case 1:
	 					system("cls");
	 					printf("Selected option: Paralelepiped\n\n");
	 					
	 					printf("High value: ");
	 					scanf("%f", &high);
	 					printf("Width value: ");
	 					scanf("%f", &width);
	 					printf("Length value: ");
	 					scanf("%f", &length);
	 					
	 					cube_volume = high * width * length;
	 					
	 					system("cls");
	 					printf("The paralelepiped volume is: %.2fm³\n\n", paralelepiped_volume);
	 					system("pause");
	 					continue;
 					case 2:
 						system("cls");
 						printf("Selected option: Cube.\n\n");
 						
 						printf("Inform the side value: ");
 						scanf("%f", &side);
 						
 						cube_volume = pow(side, 3);
 						
 						system("cls");
 						printf("The cube volume is: %.2fm³\n\n", cube_volume);
 						system("pause");
 						continue;
					case 3:
						system("cls");
						printf("Selected option: Sphere.\n\n");
						
						printf("Inform the radius value: ");
						scanf("%f", &radius);
						
						sphere_volume = (4 * M_PI * pow(radius, 3)) / 3;
						
						system("cls");
						printf("The sphere volume is: %.2fm³\n\n", sphere_volume);
						system("pause");
						continue;
					case 4:
						system("cls");
						printf("See you later!!!\n\n");
						system("pause");
						break;
					default:
						system("cls");
						printf("Invalid option. Try again.\n\n");
						system("pause");
						continue;
				 }
				 break;
				 }		 	
			 } else
			 {
			 	system("cls");
			 	printf("Invalid option. Try Again.\n\n");
			 	system("pause");
			 	continue;
			 }
			 break;
	}
	
	return 0;
}
