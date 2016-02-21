#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main() {
	room = forest;
	do{

		switch (room){
		case forest:
			room = Forest();
			break;
		case road:
			room = Road();
			break;
		case beach:
			room = Beach();
			break;
		case dock:
			room = Dock();
			break;
		case centre:
			room = Center();
			break;
		}


	} while (1);
	
	return 0;

}