#include <stdio.h>
#include <unistd.h> // Library required for sleep

// This method clears buffer
void clearBuffer (void) {
    char input;
    while ( (input = getchar()) != '\n' && input != EOF );
}

// Enum values representating every day of the week
enum Day {
  MONDAY = 1,
  Tuesday = 2,
  WEDNESDAY = 3,
  THURSDAY = 4,
  FRIDAY = 5,
  SATURDAY = 6,
  SUNDAY = 7
};

int main(int argc, char *argv[]) {
    int week;               // Variable to store the week integer
    int day;                // Variable to store the day integer

    scanf("%d", &week);     // Stores the user input into the variable 'week'
    clearBuffer();          // Clears buffer after storing the user input

    // If the user input for week is greater than 5 or less than 1, stops the program.
    if(week > 5 || week < 1) {
        printf("invalid week\n");
        return 0;
    }

    // Stores the user input into the 'day' variable
    scanf("%d", &day);

    // If the user input for day is greater than 7 or less than 1, stops the program.
    if(day > 7 || day < 1) {
        printf("invalid day\n");
        return 0;
    }

    // The enum representation of day is stored in the current_day
    enum Day current_day = day;

    // This while loop is responsible for printing the days and the weeks with respect to the order, until week 5.
    while(week <= 5) {

        /* This switch case is responsible for switching the current day variable which we get from enums, and switching them
        with appropriate print statements. The current_day is incremented in each case, so that all the days of a week
        is printed out. When the current_day is 7, we set the value of current_day back to 1 and increment the value of week,
        so that valid days are printed for the next week (incremented week) respecting their orders. The loop is exited once
        the week crosses 5. The program closes after week 5.*/
        switch (current_day) {
            case 1:
                printf("Week %d, Monday\n", week);      // Print statement to print the week along with day
                current_day++;                          // Increments the currentday
                break;
            case 2:
                printf("Week %d, Tuesday\n", week);
                current_day++;
                break;
            case 3:
                printf("Week %d, Wednesday\n", week);
                current_day++;
                break;
            case 4:
                printf("Week %d, Thursday\n", week);
                current_day++;
                break;
            case 5:
                printf("Week %d, Friday\n", week);
                current_day++;
                break;
            case 6:
                printf("Week %d, Saturday\n", week);
                current_day++;
                break;
            case 7:
                printf("Week %d, Sunday\n", week);
                current_day = 1;    // The current_day is set to 1, because current_day = 8 does not represent any valid day
                week++;             // Week is incremented on the 7th day
                break;
        }
        // Program increments the weeks and days after each second
        sleep(1);
    }

}