#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

int main() {
	FILE *fh1, *fh2;

	int i,j,m,read;

	double matches,percentage,complete,lentxt1,lentxt2,len2txt1,k;

	char txt1[1000000],txt2[1000000],ASCII[222],matchtxt2[1000000],repeat = 'y',enter,npc=(' ' - 1);

	while (repeat == 'y') {


		m = 0;
		read = 0;
		matches = 0;
		percentage = 0;
		complete = 0;
		lentxt1 = -1;
		lentxt2 = 0;
		len2txt1 = 0;
		enter = 0;

		for (i = 0; i < 1000000; i++) {
			txt1[i] = 0;
			txt2[i] = 0;
			matchtxt2[i] = 0;
		}

		for (i = 0; i < 222; i++) {
			ASCII[i] = 0;
		}

		system("clear");

		printf(
				"Insert/update first and second text in the text files and press return. \n");

		while (enter != '\r' && enter != '\n') {
			enter = getchar();
		}

		system("clear");

		fh2 = fopen("text2.txt", "r");

		if (fh2 != NULL) {
			while (!feof(fh2)) {
				txt2[read] = fgetc(fh2);
				read++;
			}

			fclose(fh2);
		} else {
			system("clear");
			printf("Error opening file. \n");
			return 0;
		}

		for (i = 0; i < 222; i++) {
			ASCII[i] = (' ' + i);
		}

		lentxt2 = strlen(txt2);

		for (j = 0; j < strlen(txt2); j++) {
			for (i = 0; i < 222; i++) {

				if (ASCII[i] == txt2[j]) {
					matchtxt2[m] = ASCII[i];
					ASCII[i] = npc;
					m++;
				}
			}

			if (strlen(txt2) >= 10000) {
				while (complete <= j + 1) {
					if (fmod((complete + 1), (lentxt2 / 100)) <= 0.01) {
						system("clear");
						printf(
								"Searching for unique characters in text 2: %lu%% \n",
								j * 100 / strlen(txt2));
					}
					complete += 0.01;
				}
			}
		}

		system("clear");

		printf("Done searching for unique characters in text 2. \n");

		for (k = 0; k < 1000000; k += 0.001) {

		}

		m = 0;
		read = 0;
		complete = 0;
		lentxt1 = -1;
		k = 0;

		fh1 = fopen("text1.txt", "r");

		if (fh1 != NULL) {
			while (!feof(fh1)) {
				txt1[read] = fgetc(fh1);
				read++;
			}

			fclose(fh1);
		} else {
			system("clear");
			printf("Error opening file. \n");
			return 0;
		}

		for (i = 0; i < 222; i++) {
			ASCII[i] = (' ' + i);
		}

		for (j = 0; j < strlen(txt1); j++) {
			for (i = 0; i < strlen(matchtxt2); i++) {

				if (matchtxt2[i] == txt1[j]) {
					matches++;
					if (ASCII[i] == txt1[j] && i < 222) {
						ASCII[i] = npc;
					}
				}

				else if (matchtxt2[i] != txt1[j]) {

					if (ASCII[i] == txt1[j] && i < 222) {
						ASCII[i] = npc;
					}
				}
			}

			len2txt1 = strlen(txt1);
			if (strlen(txt1) >= 10000)
					{
				while (complete <= j + 1) {
					if (fmod((complete + 1), (len2txt1 / 100)) <= 0.01) {
						system("clear");
						printf("Checking for matches: %lu%% \n",
								j * 100 / strlen(txt1));
					}
					complete += 0.01;
				}

				if (txt1[j] != '\n') {
					lentxt1++;
				}
			}

			else if (strlen(txt1) < 10000) {
				if (txt1[j] != '\n') {
					lentxt1++;
				}
			}
		}

		system("clear");

		enter = 0;

		printf("Done checking for matches. Press return. \n");
		while (enter != '\r' && enter != '\n') {
			enter = getchar();
		}

		system("clear");

		printf("Matches: %d \n", (int) matches);
		printf(
				"Number of characters found in text 1 (printable w/ extended): %d \n",
				(int) lentxt1);
		percentage = ((matches * 100) / lentxt1);
		printf(
				"The percentage of text 1 that can be created using only characters from text 2 is: %f%% \n",
				percentage);
		printf("\n");
		printf("Do you wish to process another set of texts? (y/n) \n");
		printf("*if so, please enter 'y' for yes. \n");
		printf(
				"*otherwise, please insert 'n' for no, in order to terminate the program. \n");
		printf("\n");
		printf("Insert response: ");
		scanf(" %[^\n]%*c", &repeat);

	}

	system("clear");

	return 0;
}
