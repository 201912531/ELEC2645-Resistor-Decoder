#include <stdio.h>
#include <stdlib.h>

// function prototypes
void main_menu(void);
int get_user_input(void);
void select_menu_item(int input);
void print_main_menu(void);
void go_back_to_main(void);


// resistor decoder menu items
void menu_resistor_decoder(void);
void menu_show_color_table(void);
void menu_help(void);

// main function
int main(void) {
  main_menu();
  return 0;
}

// menu functions
void main_menu(void) {
  print_main_menu();
  int input = get_user_input();
  select_menu_item(input);
}

int get_user_input(void) {
  int input;
  printf("\nSelect item: ");
  scanf("%d", &input);
  return input;
}

void select_menu_item(int input) {
  switch (input) {
    case 1:
      menu_resistor_decoder(); 
      break;
    case 2: 
      menu_show_color_table(); 
      break;
    case 3: 
      menu_help(); 
      break;
    case 4: 
      printf("Exiting program ... \n");
      exit(0);
    default:
      printf("Invalid selection. Exiting... \n");
      exit(1);
  }
}

void print_main_menu(void) {
  printf("\n Hi, I'm your resistor decoder buddy. Please choose an option from the menu items below:\n");
  printf("1.) Automatic resistor decoder\n");
  printf("2.) Show color table\n");
  printf("3.) Help\n");
  printf("4.) Exit \n");
  printf("--------------------------\n");
}

void go_back_to_main(void) {
  char input;
  do {
    printf("\n Enter X to return to the main menu: ");
    scanf(" %c", &input);
  } while (input != 'x' && input != 'X');
  main_menu();
}

// menu item functions
void menu_resistor_decoder(void) {
  printf("\n not done");
  go_back_to_main();
}

void menu_show_color_table(void) {
  printf("\n not done");
  go_back_to_main();
}

void menu_help(void) {
  printf("\n not done");
  go_back_to_main();
}

