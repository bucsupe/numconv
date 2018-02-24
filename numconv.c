#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int toarabic(char* roman, char* arabic);

int main(int argc, char *argv[]){

	char converted[100];

	printf("numconv - Numeric conversion functions\n");
	switch (argc){
		case 1:
		
			printf("Usage:\n\tnumconv -a <arabic number> \n\tnumconv -r <roman number>\n");
			break;
		
		case 3:
			
			if (strcmp(argv[1],"-r")==0){
				
				printf("%s -> %i\n",argv[2],toarabic(argv[2],converted));				
			}
			break;
	}


	return 0;
};


int toarabic(char* roman,char* arabic){
	int i;
	int a=0;

	for(i=0;i<strlen(roman);i++){
		if (toupper(roman[i])=='M'){
			a+=1000;
		}
		if (toupper(roman[i])=='D'){
			a+=500;
		}
		if (toupper(roman[i])=='C'){
			if (toupper(roman[i+1])=='M'){
				a-=100;
			} else if (toupper(roman[i+1])=='D') {
				a-=100;
			} else {
				a+=100;
			}			
		}
		if (toupper(roman[i])=='L'){
			a+=50;
		}
		if (toupper(roman[i])=='X'){
			if (toupper(roman[i+1])=='C'){
				a-=10;
			} else if (toupper(roman[i+1])=='L'){
				a-=10;
			} else {
				a+=10;
			}
		}
	}

	//itoa(a,arabic,10);
	return a;

}
