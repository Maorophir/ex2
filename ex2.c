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
			case 3: {
				// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
				/* Examples:
				Abudant: 12, 20, 24
				Not Abudant: 3, 7, 10
				Please notice: the number has to be bigger than 0.
				*/
				int num, sum = 0;
				printf("Enter a number:\n");
				while(scanf("%d", &num) != 1 || num <= 0)
					printf("Only positive number is allowed, please try again:\n");
				for (int i = 2; i < num; i++ ) {
					if (num % i == 0)
						sum += i;
				}
				if (sum > num)
					printf("This number is generous!\n");
				else
					printf("This number does not share.\n");
				break;
			}

			case 4: {
				// Case 4: determine wether a number is a prime.
				/* Examples:
				This one brings joy: 3, 5, 11
				This one does not bring joy: 15, 8, 99
				Please notice: the number has to be bigger than 0.
				*/
				int num, temp, rev_num = 0, digit_counter = 1;
				char p_check = 1;
				printf("Enter a number:\n");
				while(scanf("%d", &num) != 1 || num <= 0)
					printf("Only positive number is allowed, please try again:\n");
				for (int i = 2; i < num; i++ ) {
					if (num % i == 0) {
						p_check = 0;
						break;
					}
				}
				if (!p_check) {
					printf("The circle remains incomplete.\n");
					break;
				}
				for (temp = num; temp > 10; temp /= 10)
					digit_counter++;
				temp = num;
				for (int i = 0, digit; i < digit_counter; i++) {
					digit = temp % 10;
					rev_num = rev_num * 10 + digit;
					temp = temp / 10;
				}
				for (int i = 2; i < rev_num; i++) {
					if (rev_num % i == 0) {
						p_check = 0;
						break;
					}
				}
				if (!p_check)
					printf("The circle remains incomplete.\n");
				else
					printf("This number completes the circle of joy!\n");
				break;
			}
			case 5: {
				// Happy numbers: Print all the happy numbers between 1 to the given number.
				// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
				/* Examples:
				Happy :) : 7, 10
				Not Happy :( : 5, 9
				Please notice: the number has to be bigger than 0.
				*/
				// If the cycle reaches 4 it's not a happy number (End Of Cycle)
				#define EOC 4
				// Initialization of variables
				int num, check_happy = 0, start = 1;
				// Gets a number from the user, only positives are accepted
				printf("Enter a number:\n");
				while(scanf("%d", &num) != 1 || num <= 0)
					printf("Only positive number is allowed, please try again:\n");
				// Prints the plate for the numbers to be added to
				printf("Between 1 and %d only these numbers bring happiness:", num);
				// Temporary variable to manipulate
				int temp = start;
				/* Algorithm for checking whether a number is a "Happy Number"
				 * Going over each number from 1 to num. */
				while (start <= num) {
					// Count the number's digits
					int digit_counter = 1;
					for (int i = temp; i >= 10; i /= 10)
						digit_counter++;
					// Calculate the sum of the number's squares
					for (int i = 0, j = temp; i < digit_counter; i++, j /= 10)
						check_happy += (j % 10) * (j % 10);
					// If a number's sum equals 4 that number isn't "happy"
					if (check_happy == EOC) {
						start++;
						temp = start;
						check_happy = 0;
					}
					// If the number's sum is equals to 1 ("happy") print it
					else if (check_happy == 1) {
						printf(" %d", start);
						start++;
						temp = start;
						check_happy = 0;
					// If the sum isn't 4 or 1 loop again to check the number's squares.
					}else {
						temp = check_happy;
						check_happy = 0;
					}
				}
				// Prints enter and break the case
				printf("\n");
				break;
			}
			case 6: {
				// Festival of Laughter: Prints all the numbers between 1 the given number:
				// and replace with "Smile!" every number that divided by the given smile number
				// and replace with "Cheer!" every number that divided by the given cheer number
				// and replace with "Festival!" every number that divided by both of them
				/* Example:
				6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
				*/
				printf("Enter a smile and cheer number:\n");
				int smile, cheer;
				while (scanf())
			}
			case 7:
				printf("Thank you for your journey through Numeria!\n");
				return 0;
			default:
				printf("This option is not available, please try again.\n");
		}
	}while (choice != 7);
}
