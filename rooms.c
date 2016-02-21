#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int Forest(){
	system("cls");
	char direction;

	printf("You are in a forest. \nAt south, you see that the road drives to a city.\nAt west, a high hill.\nAt north, the road vanishes in the distance\nAt east, only the sea.\n");

	
	do{
		fflush(stdin);
		scanf("%c", &direction);
		
		switch (direction)
		{
		case 's':
			return road;
		case 'n':
			printf("The road vanishes in the distance.\nBetter no to follow it\n");
			break;
		case 'w':
			printf("You can't climb at that mountain\n");
			break;
		case 'e':
			printf("The sea looks grey and unpeaceful\n");
			break;
		default:
			printf("You have entered an invalid command\n");
			break;

		}
	} while (1);
}

int Road(){
	system("cls");
	char direction;
	printf("You are in a high road. \nAt north, there's a mass of gothic buildings. \nAt south, the sea, and a small beach. \nAt west, a way to a big dock. \nAt east, the road that drives to the forest\n");
	

	do{
		fflush(stdin);
		scanf("%c", &direction);

		switch (direction)
		{
		case 's':
			return beach;
		case 'n':
			return centre;
		case 'w':
			return dock;
		case 'e':
			return forest;
		default:
			printf("You have entered an invalid command\n");
			break;

		}
	} while (1);


}

int Beach(){
	system("cls");
	char direction;
	printf("The beach is small and it's full of rocks\nYou can only see the main road, at north, and the wide open sea, at south.\n");


	do{
		fflush(stdin);
		scanf("%c", &direction);

		switch (direction)
		{
		case 's':
			printf("You look at the sea. The horizon is cloudy, and the water, grey.\nYou feel a little relief for stay in land,\nbut the cold and ferocious wind spreads it.\n");
			break;
		case 'n':
			return road;
		case 'w':
			printf("There's a wall of rock.\n");
			break;
		case 'e':
			printf("There's a wall of rock.\n");
			break;
		default:
			printf("You have entered an invalid command\n");
			break;

		}
	} while (1);


}

int Dock(){
	system("cls");
	char direction;
	printf("The dock is really impressive.\nThere are enourmous woody ships in all directions except for the east.\n");


	do{
		fflush(stdin);
		scanf("%c", &direction);

		switch (direction)
		{
		case 's':
			printf("The big boats seems old and abandoned. Better not try to go into.\n");
			break;
		case 'n':
			printf("The big boats seems old and abandoned. Better not try to go into.\n");
			break;
		case 'w':
			printf("The big boats seems old and abandoned. Better not try to go into.\n");
			break;
		case 'e':
			return road;
		default:
			printf("You have entered an invalid command\n");
			break;

		}
	} while (1);
}

int Center(){
	system("cls");
	char direction;
	printf("Gothic buildings are all around of a narrow square.\nYou can see the main road at south, and a couple of sinister alleys\nthat go deeper into the city.\n");


	do{
		fflush(stdin);
		scanf("%c", &direction);

		switch (direction)
		{
		case 's':
			return road;
		case 'n':
			printf("The buildings looks intimidating, and the alleys, terrifying. You prefer not go \ndepper.\n");
			break;
		case 'w':
			printf("The buildings looks intimidating, and the alleys, terrifying. You prefer not go \ndepper.\n");
			break;
		case 'e':
			printf("The buildings looks intimidating, and the alleys, terrifying. You prefer not go \ndepper.\n");
			break;
		default:
			printf("You have entered an invalid command\n");
			break;
		}
	} while (1);

}
