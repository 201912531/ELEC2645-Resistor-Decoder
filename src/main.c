#include <stdio.h>
#include <stdlib.h>

// function prototypes
void main_menu(void);
int get_user_input(void);
void select_menu_item(int input);
void print_main_menu(void);
void go_back_to_main(void);

int get_digit_band(int band_number);
float get_multiplier_band(void);
void get_tolerance_band(float *tolerance_percent);
void print_resistance(float r);


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

void print_resistance(float r) {
    if (r >= 1000000)
        printf("%.2f MΩ\n", r / 1000000);
    else if (r >= 1000)
        printf("%.2f kΩ\n", r / 1000);
    else
        printf("%.2f Ω\n", r);
}

// menu item functions
void menu_resistor_decoder(void) {
    int digit1 = get_digit_band(1);
    int digit2 = get_digit_band(2);
    float multiplier = get_multiplier_band();
    float tolerance;
    get_tolerance_band(&tolerance);

    int base = (digit1 * 10) + digit2;
    float resistance = base * multiplier;
    float min_val = resistance * (1 - tolerance);
    float max_val = resistance * (1 + tolerance);

  printf("\n====================== The results are in! ======================\n");
  printf("Base value: %d\n", base);
  printf("Multiplier: %.2f\n", multiplier);
  printf("Nominal resistance: %.2f Ω\n", resistance);
  printf("The final resistor value is: ");
  print_resistance(resistance);
  printf("Tolerance: ±%.2f%%\n", tolerance * 100);
  printf("Range: %.2f Ω  to  %.2f Ω\n", min_val, max_val);
  printf("=============================================================\n");


    go_back_to_main();
}


void menu_show_color_table(void) {
    printf("\n===================== Color Code Table =====================\n");
    printf("Digit (Bands 1 & 2)  Multiplier (Band 3)   Tolerance (Band 4)\n");
    printf("--------------------------------------------------------------\n");
    printf("Black   = 0          x1                      N/A\n");
    printf("Brown   = 1          x10                     ±1%%\n");
    printf("Red     = 2          x100                    ±2%%\n");
    printf("Orange  = 3          x1,000                  N/A\n");
    printf("Yellow  = 4          x10,000                 N/A\n");
    printf("Green   = 5          x100,000                ±0.5%%\n");
    printf("Blue    = 6          x1,000,000              ±0.25%%\n");
    printf("Violet  = 7          x10,000,000             ±0.1%%\n");
    printf("Grey    = 8          x100,000,000            ±0.05%%\n");
    printf("White   = 9          x1,000,000,000          N/A\n");
    printf("Gold    = N/A        x0.1                    ±5%%\n");
    printf("Silver  = N/A        x0.01                   ±10%%\n");
    printf("==============================================================\n");

    go_back_to_main();
}


void menu_help(void) {
  printf("\n not done");
  go_back_to_main();
}

// resistor decoder functions
int get_digit_band(int band_number) {
    int choice;

    printf("\nSelect color of digit band %d:\n", band_number);
    printf("0: Black\n");
    printf("1: Brown\n");
    printf("2: Red\n");
    printf("3: Orange\n");
    printf("4: Yellow\n");
    printf("5: Green\n");
    printf("6: Blue\n");
    printf("7: Violet\n");
    printf("8: Grey\n");
    printf("9: White\n");
    printf("Enter choice (0-9): ");
    scanf("%d", &choice);

  if (choice < 0 || choice > 9) {
    printf("invalid choice, defaulting to black (0) \n");
    choice = 0;
  }

  return choice;
}

float get_multiplier_band(void) {
  int choice;
  printf("\nSelect colour of 3rd band (multipler band):\n");
  printf("0: Black\n");
  printf("1: Brown\n");
  printf("2: Red\n");
  printf("3: Orange\n");
  printf("4: Yellow\n");
  printf("5: Green\n");
  printf("6: Blue\n");
  printf("7: Violet\n");
  printf("8: Grey\n");
  printf("9: White\n");
  printf("10: Gold\n");
  printf("11: Silver\n");
  scanf("%d", &choice);
  
  switch (choice) {
      case 0:  return 1.0f;
      case 1:  return 10.0f;
      case 2:  return 100.0f;
      case 3:  return 1000.0f;
      case 4:  return 10000.0f;
      case 5:  return 100000.0f;
      case 6:  return 1000000.0f;
      case 7:  return 10000000.0f;
      case 8:  return 100000000.0f;
      case 9:  return 1000000000.0f;
      case 10: return 0.1f;
      case 11: return 0.01f;
      default:
            printf("Invalid choice, defaulting to Black (x1).\n");
            return 1.0f;
    }
}

void get_tolerance_band(float *tolerance_percent) {
  int choice;
  printf("\nSelect color of 4th band (tolerance band):\n");
  printf("1: Brown\n");
  printf("2: Red\n");
  printf("3: Green\n");
  printf("4: Blue\n");
  printf("5: Violet\n");
  printf("6: Grey\n");
  printf("7: Gold\n");
  printf("8: Silver\n");
  scanf("%d", &choice);

  switch(choice) {
      case 1: *tolerance_percent = 0.01f; break;
      case 2: *tolerance_percent = 0.02f; break;
      case 3: *tolerance_percent = 0.005f; break;
      case 4: *tolerance_percent = 0.0025f; break;
      case 5: *tolerance_percent = 0.001f; break;
      case 6: *tolerance_percent = 0.0005f; break;
      case 7: *tolerance_percent = 0.05f; break;
      case 8: *tolerance_percent = 0.10f; break;
      default:
            printf("Invalid input, defaulting to Gold (±5%%)\n");
            *tolerance_percent = 0.05f;
    }


}



