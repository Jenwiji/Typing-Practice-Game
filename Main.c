#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0
#define MAXCHAR 5000

void gotoxy(int, int);
int openPassage(char*, double[]);
void viewUserData();
void typingPractice();
void streaksMode();
int chooseLevel();
void red();
void white();
void yellow();
void cyan();
void tpinstructions(void);
BOOL WINAPI Beep(_In_ DWORD dwFreq, _In_ DWORD dwDuration);

void main() {
	char userChoice;
	white();
	printf("\n\n\n\n\n\n\t\t\t\t\t WELCOME TO TYPING PRACTICE");
	printf("\n\t\t\t\t\t Please Select a Mode:\n");
	cyan();
	printf("\n\t\t\t\t\t 1. View your data [PRESS 1]\n");
	printf("\n\t\t\t\t\t 2. Begin Typing Practice [PRESS 2]\n");
	printf("\n\t\t\t\t\t 3. Game Mode (STREAKS) [PRESS 3]\n");
	printf("\n\t\t\t\t\t 4. Exit Program [PRESS 4]\n\n");

	do {
		userChoice = _getch();
		if (userChoice == '1') {
			viewUserData();
		}
		else if (userChoice == '2') {

			typingPractice();
		}
		else if (userChoice == '3') {
			streaksMode();
		}
		else if (userChoice == '4') {
			white();
			printf("\n\nExiting program...");
			Sleep(3000);
			exit(1);
		}
	} while (userChoice != '1' || userChoice != '2' || userChoice != '3');
}




/*THE FOLLOWING ARE FUNCTIONS USED IN THE PROGRAM*/

//text colors
void red() {
	printf("\033[1;31m");
}

void yellow() {
	printf("\033[1;33m");
}


void cyan() {
	printf("\033[0;36m");
}

void white() {
	printf("\033[97m");
}

void reset() {
	printf("\033[0m");
}

//typing instructions
void tpinstructions(void) {
	char proceed;
	system("cls");
	printf("\n\n\t\t\t\t\t\t !! INSTRUCTIONS !!");
	printf("\n\n\t\t%c The timer begins once you have selected the level.\n\n", 175);
	printf("\t\t%c To encourage you to finish the practice, you cannot exit the practice once you have started.\n\n", 175);
	printf("\t\t%c Characters you have typed will not be displayed on the screen unless it is correct.\n\n", 175);
	printf("\t\t%c After every typed line, you must press the spacebar to proceed to the next line.\n\n", 175);
	printf("\t\t%c For each incorrectly typed character, a bell alert will notify you \n\t\t\n\t\t and the number of mistakes will increase by 1.\n\n", 175);
	printf("\t\t%c Your data can be saved after completing the typing practice.\n\n", 175);
	printf("\n\n\t\t%c Once you have read and understood the instructions, press any key to proceed.\n\n", 175);
	proceed = _getch();
	return;
}

//view saved data
void viewUserData() {
	char username[50], userdata[MAXCHAR], userChoice, exit = FALSE;
	FILE* pfile;
	system("cls");
	printf("View user data\n");
	puts("Enter your username");
	scanf("%s", username);
	strcat(username, ".txt");
	pfile = fopen(username, "r");
	while (pfile == NULL) {
		puts("The file with this username does not exist...");
		puts("Enter correct username or press '0' and ENTER to return to main menu");
		scanf("%s", username);
		if (strcmp(username, "0") == 0) {
			exit = TRUE;
			break;
		}
		else {
			strcat(username, ".txt");
			pfile = fopen(username, "r");
		}
	}
	if (exit == TRUE) {
		system("cls");
		main();
	}

	else {
		white();
		while (fgets(userdata, 300, pfile) != NULL) {
			printf("%s", userdata);
		}
	}
	cyan();
	fclose(pfile);
	puts("\n\n\nPress 'x' to go back to main menu");
	userChoice = _getch();

	while (tolower(userChoice) != 'x') {
		userChoice = _getch();
		printf("\r%c", userChoice);
	}
	system("cls");
	main();
}

//allow users to choose level
int chooseLevel() {
	char levelChosen[50];
	int levelChosenInt;
	do {
		system("cls");
		puts("\n\t\t\t\tPlease Choose a Level: ");
		white();
		puts("\n\t\t\t\t\tBeginner:");
		puts("\t\t\t\tLevel 1 [PRESS 1 and ENTER]");
		puts("\t\t\t\tLevel 2 [PRESS 2 and ENTER]");
		puts("\t\t\t\tLevel 3 [PRESS 3 and ENTER]");
		puts("\t\t\t\tLevel 4 [PRESS 4 and ENTER]");
		puts("\t\t\t\tLevel 5 [PRESS 5 and ENTER]");

		yellow();
		puts("\n\t\t\t\t\tIntermediate:");
		puts("\t\t\t\tLevel 6 [PRESS 6 and ENTER]");
		puts("\t\t\t\tLevel 7 [PRESS 7 and ENTER]");
		puts("\t\t\t\tLevel 8 [PRESS 8 and ENTER]");
		puts("\t\t\t\tLevel 9 [PRESS 9 and ENTER]");
		puts("\t\t\t\tLevel 10 [PRESS 10 and ENTER]");

		red();
		puts("\n\t\t\t\t\tAdvanced:");
		puts("\t\t\t\tLevel 11 [PRESS 11 and ENTER]");
		puts("\t\t\t\tLevel 12 [PRESS 12 and ENTER]");
		puts("\t\t\t\tLevel 13 [PRESS 13 and ENTER]");
		puts("\t\t\t\tLevel 14 [PRESS 14 and ENTER]");
		puts("\t\t\t\tLevel 15 [PRESS 15 and ENTER]");

		cyan();
		puts("\n\t\tTo go back to main menu, press 'x' and ENTER");

		cyan();
		scanf("%s", levelChosen);
		if (tolower(levelChosen[0]) == 'x') {
			system("cls");
			main();
			break;
		}
		levelChosenInt = atoi(levelChosen);
		if ((levelChosenInt > 0) && (levelChosenInt < 16)) {
			break;
		}
	} while (TRUE);
	return levelChosenInt;
}

//typing practice (choice2)
void typingPractice() {
	int level;
	char userChoice, username[20], backmain;
	char* passages[] = { "%%p1%%.txt", "%%p2%%.txt", "%%p3%%.txt", "%%p4%%.txt", "%%p5%%.txt", "%%p6%%.txt",
		"%%p7%%.txt", "%%p8%%.txt", "%%p9%%.txt", "%%p10%%.txt", "%%p11%%.txt", "%%p12%%.txt", "%%p13%%.txt", "%%p14%%.txt", "%%p15%%.txt" };
	double data[5];

	tpinstructions();
	system("cls");
	level = chooseLevel();
	fflush(stdin);
	switch (level) {

	case 1:
		openPassage(passages[0], &data);
		break;

	case 2:
		openPassage(passages[1], &data);
		break;

	case 3:
		openPassage(passages[2], &data);
		break;

	case 4:
		openPassage(passages[3], &data);
		break;

	case 5:
		openPassage(passages[4], &data);
		break;

	case 6:
		openPassage(passages[5], &data);
		break;

	case 7:
		openPassage(passages[6], &data);
		break;

	case 8:
		openPassage(passages[7], &data);
		break;

	case 9:
		openPassage(passages[8], &data);
		break;

	case 10:
		openPassage(passages[9], &data);
		break;

	case 11:
		openPassage(passages[10], &data);
		break;

	case 12:
		openPassage(passages[11], &data);
		break;

	case 13:
		openPassage(passages[12], &data);
		break;

	case 14:
		openPassage(passages[13], &data);
		break;

	case 15:
		openPassage(passages[14], &data);
		break;
	}

	printf("Total time: %.0lf minutes %.0lf seconds \nMistakes: %.0lf \nWords per minute: %.0lf\n", data[0], data[1], data[2], data[3]);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	printf("Completed on: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("\nDo you want to save your progress? (Press Y/N)\n");
	userChoice = _getch();

	while (tolower(userChoice) != 'y' && tolower(userChoice) != 'n') {
		userChoice = _getch();
		printf("\r%c", userChoice);
	}

	if (tolower(userChoice) == 'n') {
		printf("\nGoing back to main menu...");
		Sleep(5000);
		system("cls");
		main();
	}

	else if (tolower(userChoice) == 'y')
	{
		puts("\nEnter your username");
		scanf("%s", username);
		strcat(username, ".txt");
		FILE* pfile;
		pfile = fopen(username, "r");

		if (pfile == NULL) {
			printf("New file created: %s\n", username);
		}

		pfile = fopen(username, "a+");
		puts("Data saved successfully...");
		fprintf(pfile, "\n");
		fprintf(pfile, "Date: %d-%02d-%02d %02d:%02d:%02d\tTotal Time: %.0lf minutes %.0lf seconds\t\tMistakes: %.0lf\tWords per minute: %.0lf", tm.tm_year + 1900,
			tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, data[0], data[1], data[2], data[3]);
		fclose(pfile);
		printf("\nPress 'x' to go back to main menu\n");
		backmain = _getch();

		if (tolower(backmain) == 'x') {
			system("cls");
			main();
		}
		else {
			puts("Exiting program");
			exit(1);
		}
	}
}

//streaks mode(choice3)
void streaksMode() {
	FILE* pfile;
	int usermistake = 0, streak = 0, replay;
	char userchoice;
	char display[20], usertyped;

	system("cls");
	printf("\n\n\t\t\t!! Welcome to STREAKS MODE !!\n\n");
	printf("\t\t%c This mode will test your accuracy and patience.\n", 175);
	printf("\t\t%c For each correctly typed word, your streak count will increase by 1.\n", 175);
	printf("\t\t%c The game ends when you type an incorrect character.\n\n", 175);
	red();
	printf("\t\t To begin [PRESS 1]\n", 175);
	white();
	printf("\t\t To go back to main menu [PRESS 0]\n", 175);
	cyan();
	do {
		userchoice = _getch();
		printf("\r%c", userchoice);
	} while (userchoice != '1' && userchoice != '0');


	if (userchoice == '0') {
		system("cls");
		main();
	}

	if (userchoice == '1') {

		pfile = fopen("%speed%mode.txt", "r");
		while (pfile != NULL) {

			system("cls");
			gotoxy(5, 1);
			printf("\rYour streaks: %d", streak);

			if (usermistake == 1) {
				break;
			}

			fgets(display, 20, pfile);
			gotoxy(5, 4);
			printf("%s", display);
			int count = 0;
			gotoxy(5, 5);
			while (1) {

				usertyped = _getch();

				if (usertyped == display[count]) {
					white();
					printf("%c", usertyped);
					count++;
					cyan();
				}
				else {
					usermistake = 1;
					break;
				}

				if (count + 1 == strlen(display)) {
					break;
				}
			}
			streak++;
		}

		if (usermistake == 1) {

			system("cls");
			red();
			puts("\n\n\t\t GAME OVER");
			cyan();
			printf("\n\n\t Your total streaks: %d\n\n", streak);
			white();
			printf("\tTo restart              [PRESS 1]\n");
			printf("\tTo retrurn to main menu [PRESS 0]\n\n");
			cyan();

			do {
				replay = _getch();
				printf("\r%c", replay);
			} while (replay != '1' && replay != '0');

			if (replay == '1') {
				system("cls");
				streaksMode();
			}
			else if (replay == '0') {
				system("cls");
				main();
			}
		}

		fclose(pfile);
	}
}

//move cursor
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//open a passage chosen by the user
int openPassage(char* passage, double data[]) {

	char typethis[MAXCHAR], typed;
	int mistakes = 0, rowcount = 3;
	int  wpm, count2 = 0;
	double totaltime, totalmins, remaintimesec;
	time_t start, end;

	system("cls");
	yellow();
	printf("\t\tMistakes: \t%d\r", mistakes);
	cyan();
	FILE* pfile;
	pfile = fopen(passage, "r");
	start = clock();
	while (fgets(typethis, MAXCHAR, pfile) != NULL) {

		int chartyped = 0, count = 0;

		printf("\n\n%s\n", typethis);
		gotoxy(0, rowcount);
		while (TRUE) {

			typed = _getch();
			if ((typed) != typethis[count]) {
				Beep(600, 100);
				mistakes++;
				gotoxy(30, 0);
				yellow();
				printf("\33[2K\r\t\tMistakes:\t%d", mistakes);
				cyan();

			}
			else {
				//counts number of correct inputs			
				chartyped++;
				count++;
				white();
				printf("%c", typed);
				cyan();

			}

			if (chartyped == strlen(typethis) - 1) {
				break;

			}

			gotoxy(chartyped, rowcount);
		}

		rowcount += 3;
		count2 += count;
	}

	system("cls");

	end = clock();
	totaltime = (difftime(end, start) / CLOCKS_PER_SEC);
	totalmins = totaltime / 60;
	remaintimesec = (int)totaltime % 60;
	wpm = (count2 / 5) / totalmins;

	data[0] = floor(totalmins);
	data[1] = remaintimesec;
	data[2] = mistakes;
	data[3] = wpm;

	fclose(pfile);
	return 0;
}