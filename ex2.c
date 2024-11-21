/******************
Name:Maor Ophir
ID:315144063
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	setbuf(stdout, NULL);
	// Choice variable
	int choice;
	do {
		// Print menu
		printf("Choose an option:\n"
		"\t1. Happy Face\n"
		"\t2. Balanced Number\n"
		"\t3. Generous Number\n"
		"\t4. Circle Of Joy\n"
		"\t5. Happy Numbers\n"
		"\t6. Festival Of Laughter\n"
		"\t7. Exit\n");
		scanf("%d", &choice);
		// Action for each case
		switch (choice) {

			case 1: {
				// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
				/* Example:
				* n = 3:
				* 0   0
				*   o
				* \___/
				*/
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				char eyes, nose, mouth;
				int face_size;
				scanf(" %c %c %c", &eyes, &nose, &mouth);
				printf("Enter face size:\n");
				while (scanf("%d", &face_size) != 1 || face_size <= 0 || face_size % 2 == 0) {
					printf("The face's size must be an odd and positive number, please try again:\n");
				}
				// Prints first eye spaces and then thr second eye
				printf("%c", eyes);
				for (int i = 0; i < face_size; i++) printf(" ");
				printf("%c\n", eyes);
				// Prints spaces before the nose, then the nose
				for (int i = 0; i < face_size / 2 + 1; i++) printf(" ");
				printf("%c\n", nose);
				// Prints mouth
				printf("\\");
				for (int i = 0; i < face_size; i++) printf("%c", mouth);
				printf("/\n");
				break;
			}
			case 2: {
				// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
				// and the sum of all digits to the right of the middle digit(s) are equal
				/* Examples:
				Balanced: 1533, 450810, 99
				Not blanced: 1552, 34
				Please notice: the number has to be bigger than 0.
				*/
				int num, left_digits = 0, right_digits = 0, digit_counter = 0;
				printf("Enter a number:\n");
				while(scanf("%d", &num) != 1 || num <= 0)
					printf("Only positive number is allowed, please try again:\n");
				float temp = (float)num;
				for (;num > 10; num /= 10)
					digit_counter++;
				digit_counter++;
				num = (int)temp;
				if (digit_counter % 2 != 0) {
					for (int i = 0; i < digit_counter / 2 + 1; i++) {
						right_digits += (int)temp % 10;
						temp /= 10;
					}
					temp *= 10;
					for (int i = 0; i < digit_counter / 2 + 1; i++) {
						left_digits += (int)temp % 10;
						temp /= 10;
					}
				} else {
					for (int i = 0; i < digit_counter / 2; i++) {
						right_digits += (int)temp % 10;
						temp /= 10;
					}
					for (int i = 0; i < digit_counter / 2; i++) {
						left_digits += (int)temp % 10;
						temp /= 10;
					}
				}
				if (left_digits == right_digits)
					printf("This number is balanced and brings harmony!\n");
				else
					printf("This number isn't balanced and destroys harmony.\n");
				break;
			}
			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			/* Examples:
			Abudant: 12, 20, 24
			Not Abudant: 3, 7, 10
			Please notice: the number has to be bigger than 0.
			*/

			// Case 4: determine wether a number is a prime.
			/* Examples:
			This one brings joy: 3, 5, 11
			This one does not bring joy: 15, 8, 99
			Please notice: the number has to be bigger than 0.
			*/


			// Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.
			*/

			// Festival of Laughter: Prints all the numbers between 1 the given number:
			// and replace with "Smile!" every number that divided by the given smile number
			// and replace with "Cheer!" every number that divided by the given cheer number
			// and replace with "Festival!" every number that divided by both of them
			/* Example:
			6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
			*/
			case 7:
				printf("Thank you for your journey through Numeria!\n");
				return 0;
			default:
				printf("This option is not available, please try again.\n");
				continue;
		}
	}while (0 < choice < 7);
	printf("Thank you for your journey through Numeria!\n");
	return 0;
}
