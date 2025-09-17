#include <stdio.h>

int main(void) {
    int running = 1;

    while (running) {
        int choice;

        printf("\n--- Theme Park Ticketing System ---\n");
        printf("1. Book Tickets\n");
        printf("2. View Ticket Prices\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) return 1;

        if (choice == 1) {
            // --- Book Tickets ---
            char rideType, ticketType, mealChoice;
            const char *rideName = "Invalid";
            const char *ticketName = "Invalid";
            double pricePerTicket = 0.0;
            int quantity;

            // Validate ride type
            do {
                printf("Ride Type (T=Thrill, W=Water, F=Family) [UPPERCASE]: ");
                if (scanf(" %c", &rideType) != 1) return 1;
            } while (rideType != 'T' && rideType != 'W' && rideType != 'F');

            // Validate ticket type
            do {
                printf("Ticket Type (S=Standard, F=Fast Pass) [UPPERCASE]: ");
                if (scanf(" %c", &ticketType) != 1) return 1;
            } while (ticketType != 'S' && ticketType != 'F');

            // Validate quantity
            do {
                printf("Number of Tickets (>0): ");
                if (scanf("%d", &quantity) != 1) return 1;
                if (quantity <= 0) printf("Quantity must be greater than 0.\n");
            } while (quantity <= 0);

            // Meal choice
            do {
                printf("Meal Package? (y/n): ");
                if (scanf(" %c", &mealChoice) != 1) return 1;
            } while (mealChoice!='y' && mealChoice!='Y' && mealChoice!='n' && mealChoice!='N');

            // Price via switch/case
            switch (rideType) {
                case 'T':
                    rideName = "Thrill";
                    switch (ticketType) {
                        case 'S': ticketName = "Standard";  pricePerTicket = 20.0; break;
                        case 'F': ticketName = "Fast Pass"; pricePerTicket = 30.0; break;
                    }
                    break;
                case 'W':
                    rideName = "Water";
                    switch (ticketType) {
                        case 'S': ticketName = "Standard";  pricePerTicket = 18.0; break;
                        case 'F': ticketName = "Fast Pass"; pricePerTicket = 28.0; break;
                    }
                    break;
                case 'F':
                    rideName = "Family";
                    switch (ticketType) {
                        case 'S': ticketName = "Standard";  pricePerTicket = 15.0; break;
                        case 'F': ticketName = "Fast Pass"; pricePerTicket = 25.0; break;
                    }
                    break;
            }

            // Costs
            const double MEAL_PRICE = 6.50;
            double subtotal   = pricePerTicket * quantity;
            double discount   = (quantity > 5) ? (subtotal * 0.15) : 0.0;
            double mealCost   = (mealChoice=='y' || mealChoice=='Y') ? (MEAL_PRICE * quantity) : 0.0;
            double finalTotal = subtotal - discount + mealCost;

            // Summary
            printf("\nRide Type: %s\n", rideName);
            printf("Ticket Type: %s\n", ticketName);
            printf("Number of Tickets: %d\n", quantity);
            printf("Meal Package: %s\n", (mealChoice=='y'||mealChoice=='Y') ? "Yes" : "No");
            printf("Total Cost Before Discount: £%.2f\n", subtotal);
            printf("Bulk Discount: £%.2f\n", discount);
            printf("Meal Package Cost: £%.2f\n", mealCost);
            printf("Final Total Cost: £%.2f\n", finalTotal);

            // Ask to return to menu or exit
            char again;
            printf("Would you like to see the menu again (y/n)? ");
            if (scanf(" %c", &again) != 1) return 1;
            if (again=='n' || again=='N') {
                printf("Thank you for your purchase, enjoy the rides!\n");
                running = 0;
            }

        } else if (choice == 2) {
            // --- View Ticket Prices ---
            printf("\nTicket Prices:\n");
            printf("Thrill  - Standard: £20.00 | Fast Pass: £30.00\n");
            printf("Water   - Standard: £18.00 | Fast Pass: £28.00\n");
            printf("Family  - Standard: £15.00 | Fast Pass: £25.00\n");

            // Ask to return to menu or exit
            char again;
            printf("Would you like to see the menu again (y/n)? ");
            if (scanf(" %c", &again) != 1) return 1;
            if (again=='n' || again=='N') {
                printf("Thank you for your purchase, enjoy the rides!\n");
                running = 0;
            }

        } else if (choice == 3) {
            printf("Thank you for your purchase, enjoy the rides!\n");
            running = 0;
        } else {
            printf("Invalid choice. Please select 1, 2, or 3.\n");
        }
    }
    return 0;
}
