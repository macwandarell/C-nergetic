#include <stdio.h>
#include "f_string.h"
#include "rating.h"
#include <stdlib.h>// for atoi, atof
#include <string.h>

// Define the hotel structure
struct hotel {
    int index_in_city;
    char name[201];
    char city[51];
    int price_of_deluxe;
    int price_of_single;
    int price_of_villa;
    int price_of_luxury;
    float rating;
    char address[501];
    char description[1001];
};

void display_hotels_by_city(struct hotel *hotels, int num_hotels, int city_number) {
    char *city_name;

    switch (city_number) {
        case 1: city_name = "Mumbai"; break;
        case 2: city_name = "Delhi"; break;
        case 3: city_name = "Bangalore"; break;
        case 4: city_name = "Kolkata"; break;
        case 5: city_name = "Chennai"; break;
        case 6: city_name = "Udaipur"; break;
        case 7: city_name = "Ahmedabad"; break;
        case 8: city_name = "Goa"; break;
        case 9: city_name = "Manali"; break;
        case 10: city_name = "Hyderabad"; break;
        default: printf("Invalid city number.\n"); return;
    }

     printf("\nHotels in %s (City Number: %d):\n", city_name, city_number);
    for (int i = 0; i < num_hotels; i++) {
        if (strcmp(hotels[i].city, city_name) == 0) {
            printf("\nHotel #%d:\n", i + 1);
            printf("Index in city: %d\n", hotels[i].index_in_city);
            printf("Name: %s\n", hotels[i].name);
            printf("City: %s\n", hotels[i].city);
            printf("Price of deluxe room: %d\n", hotels[i].price_of_deluxe);
            printf("Price of single room: %d\n", hotels[i].price_of_single);
            printf("Price of villa: %d\n", hotels[i].price_of_villa);
            printf("Price of luxury room: %d\n", hotels[i].price_of_luxury);
            printf("Rating: ");rating_to_stars(hotels[i].rating);
            printf("Address: %s\n", hotels[i].address);
            printf("Description: %s\n", hotels[i].description);
        }
    }
}


 int main(){
    int city_number;
    char *city_name;
    struct hotel hotels[100];

    FILE *fp = fopen("hotel_list.csv", "r");

    if (!fp) {
        printf("File does not exist.\n");
    } else {
        int n = 1024;
        char buffer[n];
        int row = 0;
        int column = 0;

        // Array of structures to store hotels (maximum of 100 hotels for simplicity)
        

        while (fgets(buffer, n, fp)) {
            struct hotel temp_hotel;
            column = 0;
            row++;
            if (row == 1) continue; // Skip header row

            // Split the line into values
            char *value = strtok(buffer, ",");
            while (value) {
                switch (column) {
                    case 0:
                        temp_hotel.index_in_city = atoi(value); // Convert to integer
                        break;
                    case 1:
                        strncpy(temp_hotel.name, value, 200);
                        temp_hotel.name[200] = '\0';
                        break;
                    case 2:
                        strncpy(temp_hotel.city, value, 50);
                        temp_hotel.city[50] = '\0';
                        break;
                    case 3:
                        temp_hotel.price_of_deluxe = atoi(value);
                        break;
                    case 4:
                        temp_hotel.price_of_single = atoi(value);
                        break;
                    case 5:
                        temp_hotel.price_of_villa = atoi(value);
                        break;
                    case 6:
                        temp_hotel.price_of_luxury = atoi(value);
                        break;
                    case 7:
                        temp_hotel.rating = atof(value); // Convert to float
                        break;
                    case 8:
                        strncpy(temp_hotel.address, value, 500);
                        temp_hotel.address[500] = '\0';
                        break;
                    case 9:
                        strncpy(temp_hotel.description, value, 1000);
                        temp_hotel.description[1000] = '\0';
                        break;
                }
                value = strtok(NULL, ","); // Get the next value
                column++;
            }

            // Store the current hotel structure in the array
            if (row - 2 < 100) { // Ensure it doesn't exceed array size
                hotels[row - 2] = temp_hotel;
            } else {
                printf("Exceeded maximum number of hotels (100).\n");
                break;
            }
        }

        fclose(fp);


        // Display menu
        f_string_format(1, "\033[1m==============\033[0m");
        f_string_format(1, "\033[38;5;208m          TRIVAGO   \033[0m");
        f_string_format(1, "\033[1m  ==============\033[0m\n");
        f_string_format(0, "\033[33m City List\033[0m");
        f_string_format(0, "\033[33m 1. Mumbai\033[0m");
        f_string_format(0, "\033[33m 2. Delhi\033[0m");
        f_string_format(0, "\033[33m 3. Bangalore\033[0m");
        f_string_format(0, "\033[33m 4. Kolkata\033[0m");
        f_string_format(0, "\033[33m 5. Chennai\033[0m");
        f_string_format(0, "\033[33m 6. Udaipur\033[0m");
        f_string_format(0, "\033[33m 7. Ahmedabad\033[0m");
        f_string_format(0, "\033[33m 8. Goa\033[0m");
        f_string_format(0, "\033[33m 9. Manali\033[0m");
        f_string_format(0, "\033[33m 10. Hydrabad\033[0m");
        f_string_format(0, "\033[33m 11. Exit\033[0m");
        f_string_format(1, "\033[1m ==============================\033[0m\n");
        printf("Enter your choice of city by selecting the index number: ");
   
        scanf("%d", &city_number);
        getchar();
        printf("\n"); // Clear newline character from input buffer

        switch (city_number) {
        case 1: display_hotels_by_city(hotels, row-1, 1); break;
        case 2: display_hotels_by_city(hotels, row-1, 2); break;
        case 3: display_hotels_by_city(hotels, row-1, 3); break;
        case 4: display_hotels_by_city(hotels, row-1, 4); break;
        case 5: display_hotels_by_city(hotels, row-1, 5); break;
        case 6: display_hotels_by_city(hotels, row-1, 6); break;
        case 7: display_hotels_by_city(hotels, row-1, 7); break;
        case 8: display_hotels_by_city(hotels, row-1, 8); break;
        case 9: display_hotels_by_city(hotels, row-1, 9); break;
        case 10: display_hotels_by_city(hotels, row-1, 10); break;
        case 11: printf("Exiting Hotel Page.Goodbye!\n");
        default: printf("Enter right number");break;
        
    }
        }
}