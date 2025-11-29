#include <stdio.h>

int main() {

  int running = 1;

  while (running) {
    int choice;
  
    printf("Resistor Decoder Buddy\n");
    printf("1: Decode a 4-band resistor\n");
    printf("2: Exit\n");
    printf("Enter your choice:  \n");
    scanf("%d", &choice);
  
    if (choice == 1) {
      printf(" ");
    } else if (choice == 2) {
      printf("byyyeeee\n");
      running = 0;
    } else 
      printf("Invalid choice. Read the menu.\n");
  }  
return 0;
}
