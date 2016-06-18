#include <stdio.h>
#define MAX 100

//this will standardize my data structure through the entire code
typedef struct{
    char manufacturer [MAX], model [MAX], color [MAX];
    int year;
    float price;
} REG;

//these are the prototypes for the functions (they wouldn't be necessary if I had declared them before main)
REG register_car (void);
void menu (void);
void print_single_info (REG *, int );
void printf_all_info (REG *, int );
void change_chevrolet_to_GM (REG *, int );

int main (){
    int total_cars, car_number, i, option, c;
    printf ("***REGISTRATION***\n\nTotal cars: "); scanf ("%d", &total_cars);
    system ("cls");
    REG cars [total_cars];
    for (i = 0; i < total_cars; i++){
        //each car will be registered and identified by the counter + 1. The information will be received by this vector
        printf ("***REGISTRATION***\n\nCar %d\n", i + 1);
        cars [i] = register_car();
        system ("cls");
    }
    do {
        //this repetitive structure will be executed until user types 0 (zero) on the keyboard
        menu ();
        fflush (stdin);
        scanf ("%d", &option);
        system ("cls");
        switch (option){
            case 1: print_single_info (cars, car_number);
                    break;
            case 2: printf ("Option 2\n\n");
                    print_all_info (cars, total_cars);
                    break;
            case 3: change_chevrolet_to_GM (cars, total_cars);
                    print_all_info (cars, total_cars);
                    break;
            default: printf ("\n\nInvalid option!");
        }
        printf ("\n\nContinue? (Yes - 1 // No - 0)");
        fflush (stdin);
        scanf ("%d", &c);
        system ("cls");
    } while (c != 0);
    return 0;
}

//this function is called each time I need to complete a position in the vector we declared in main. It returns a struct of the type REG
REG register_car (void){
    REG auxCar;
    fflush (stdin);
    printf ("Model: "); gets (auxCar.model);
    printf ("Manufacturer: "); gets (auxCar.manufacturer);
    printf ("Color: "); gets (auxCar.color);
    printf ("Year: "); scanf ("%d", &auxCar.year);
    printf ("Price: "); scanf ("%f", &auxCar.price);
    return auxCar;
}

//this function only prints my menu, nothing more
void menu (void){
    printf ("***MENU***\n(1)Show a single car's info\n(2)Show all the cars info\n(3)Update Chevrolet to GM manufacturer\n\nChosen option: ");
}

//this function receives my vector of structures and a car's identification. The user selects a car by it's ID and then the function prints the respective data.
void print_single_info (REG *car, int n){

    printf ("Option 1 - Select a car: "); scanf ("%d", &n);
    printf ("\n\nCar %d\nModel: %s\nManufacturer: %s\nColor: %s\nYear: %d\nPrice: %.2f", n, car[n-1].model, car[n-1].manufacturer, car[n-1].color, car[n-1].year, car[n-1].price);
}
//this function prints all the info about all cars. It receives my vector of structures and the total of cars registered
void print_all_info (REG *cars, int total_cars){
    int i;
    for (i = 0; i < total_cars; i++){
        printf ("Car %d\nModel: %s\nManufacturer: %s\nColor: %s\nYear: %d\nPrice: %.2f", i + 1, cars[i].model, cars[i].manufacturer, cars[i].color, cars[i].year, cars[i].price);
    }
}

//this function receives my vector and verifies if there are any models manufactured by Chevrolet. If so, it updates the 'Manufacturer' string to General Motors
void change_chevrolet_to_GM (REG *cars, int total_cars){
    int i;
    for (i = 0; i < total_cars; i++){
        if (strcmp (cars[i].manufacturer, "Chevrolet") == 0){
            strcpy (cars[i].manufacturer, "General Motors");
        }
    }
}
