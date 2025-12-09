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
void decoding_animation(void);
void save_results(int base, float multiplier, float resistance, float tolerance, float min_val, float max_val);




// resistor decoder menu items
void menu_resistor_decoder(void);
void menu_show_color_table(void);
void menu_view_saved_results(void);
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
      menu_view_saved_results();
      break;
    case 4:
      menu_help();
      break;
    case 5:
      printf("Exiting program... \n");
      exit(0);
    default:
      printf("\nInvalid selection. Please choose an option from the menu.\n");
      main_menu();
      break;
  }
}
   

void print_main_menu(void) {
  printf("\n Hi, I'm your lab assistant bot. Please choose an option from the menu items below:\n");
  printf("1.) Automatic resistor decoder\n");
  printf("2.) Show color table\n");
  printf("3.) View saved results\n");
  printf("4.) Help\n");
  printf("5.) Exit \n");
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

void decoding_animation(void) {
    printf("\nDecoding...\n\n");
}

// menu item functions
void menu_resistor_decoder(void) {
    int digit1 = get_digit_band(1);
    int digit2 = get_digit_band(2);
    float multiplier = get_multiplier_band();
    float tolerance;
    get_tolerance_band(&tolerance);
    decoding_animation();


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

  char save_choice;
  printf("\nWould you like to save these results? (Y/N): ");
  scanf(" %c", &save_choice);
  
  if (save_choice == 'y' || save_choice == 'Y') {
      save_results(base, multiplier, resistance, tolerance, min_val, max_val);
  }


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
    printf("\n============================ Help ============================\n");

    printf("\nOverview:\n");
    printf("This program is designed to assist electrical engineers in the lab.\n");
    printf("Instead of using an Ohmmeter or manually decoding every resistor you need,\n");
    printf("this program will do it for you!\n");
    printf("Simply follow the prompts and enter the colors of each band of the resistor.\n");

    printf("\nHow is a resistor read?\n");
    printf("The colors of the bands of a resistor tell us its value.\n");
    printf("Band 1 = first digit (cannot usually be 0)\n");
    printf("Band 2 = second digit\n");
    printf("Band 3 = multiplier (power of ten)\n");
    printf("Band 4 = tolerance (accuracy range)\n");

    printf("\nHow do I use this program?\n");
    printf("If you have a resistor you would like to decode:\n");
    printf("1) Choose option 1 from the main menu.\n");
    printf("2) Select the color of the first band (digit band 1).\n");
    printf("3) Select the color of the second band (digit band 2).\n");
    printf("4) Select the color of the third band (multiplier band).\n");
    printf("5) Select the color of the fourth band (tolerance band).\n");
    printf("6) Read the final resistance and range in the result.\n");

    printf("\nASCII diagram of a 4 band resistor:\n");
    printf("   ________|====|====|====|====|________\n");
    printf("             B1   B2   B3   B4\n");
    printf("             |    |    |    |\n");
    printf("         Digit  Digit  Mult  Tol\n");

    printf("\n==============================================================\n");

    go_back_to_main();
}

void menu_view_saved_results(void) {
    FILE *file = fopen("saved_results.txt", "r");

    printf("\n================ Saved Results ================\n");

    if (file == NULL) {
        printf("No saved results found.\n");
        printf("================================================\n");
        go_back_to_main();
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);

    printf("================================================\n");

    go_back_to_main();
}


// resistor decoder functions
int get_digit_band(int band_number) {
    int choice;
    int min_allowed = 0;
  
    printf("\nSelect color of band %d (digit band): \n", band_number);
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
    

    if (band_number == 1) {
        printf("Note: Band 1 cannot be black (0).\n");
        min_allowed = 1;   // band 1 must be 1–9
    } else {
        min_allowed = 0;   // band 2 can be 0–9
    }

    do {
        printf("Enter choice (%d-9): ", min_allowed);
        scanf("%d", &choice);

        if (choice < min_allowed || choice > 9) {
            printf("Invalid choice. Please enter a number between %d and 9.\n", min_allowed);
        }

    } while (choice < min_allowed || choice > 9);

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
  printf("Enter choice (0–11): ");
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
  printf("Enter choice (1–8): ");
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

void save_results(int base, float multiplier, float resistance, float tolerance, float min_val, float max_val) {
  FILE *file = fopen("saved_results.txt", "a"); 
  if (file == NULL) {
      printf("Error opening file. Results not saved.\n");
      return;
  }

    fprintf(file, "======================================\n");
    fprintf(file, "Base value: %d\n", base);
    fprintf(file, "Multiplier: %.2f\n", multiplier);
    fprintf(file, "Nominal resistance: %.2f Ω\n", resistance);
    fprintf(file, "Tolerance: ±%.2f%%\n", tolerance * 100);
    fprintf(file, "Range: %.2f Ω to %.2f Ω\n", min_val, max_val);
    fprintf(file, "======================================\n\n");

    fclose(file);

    printf("Results successfully saved to saved_results.txt!\n");
}





