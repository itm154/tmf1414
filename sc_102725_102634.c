#include <stdio.h>
#include <string.h>

/* ******************************** */
/* *        Constant values       * */
/* ******************************** */
const float price2D = 12.00;
const float price3D = 15.00;
const float priceIMAX = 18.00;

const float discChild = 0.5;
const float discSenior = 0.2;
const float discTuesday = 0.15;

const float surchargeWeekdayEvening = 0.1;
const float surchargeWeekend = 0.15;

//
/* ******************************* */
/* *      Type Definitions       * */
/* ******************************* */
typedef struct {
  float basePrice;
  float showtimeSurcharge;
  float discountAge;
  float finalPrice;
  float totalPrice;
} price;

typedef struct {
  int hour;
  int minutes;
} showtime;

//
/* ********************************** */
/* *      Function Prototypes       * */
/* ********************************** */
float getBasePrice(int movieType);
float getSurcharge(float basePrice, int showtimeHour, char day[]);
float getDiscountAge(float basePrice, int age);

void displayTicketDetails(int movieType, showtime showtime, int age[],
                          char day[], price prices);

//
/* **************************** */
/* *      Main Function       * */
/* **************************** */
int main() {
  int movieType, numTickets;
  char day[20];
  showtime Showtime;
  price Prices;

  printf("******************************\n");
  printf("**     Welcome to CineMax   **\n");
  printf("******************************\n");

  printf("Please select a movie type:\n");
  printf("1. 2D\n");
  printf("2. 3D\n");
  printf("3. IMAX\n");
  printf("Enter your choice (1-3): ");
  scanf("%d", &movieType);

  Prices.basePrice = getBasePrice(movieType);
  if (Prices.basePrice == 0.0) {
    printf("Invalid movie type, please select one of 3 available ones.\n");
    return -1;
  }

  printf("Enter showtime (24-hour format, e.g, 20:00): ");
  scanf("%d:%d", &Showtime.hour, &Showtime.minutes);
  if (Showtime.hour > 24 || Showtime.minutes >= 60) {
    printf("Invalid time, please enter a valid 24-hour format\n");
    return -1;
  }

  printf("Enter the day of the week (e.g, Monday, Tuesday): ");
  scanf("%s", day);

  printf("\nEnter number of ticket to purchase: ");
  scanf("%d", &numTickets);

  Prices.showtimeSurcharge = getSurcharge(Prices.basePrice, Showtime.hour, day);

  int age[numTickets];
  for (int i = 0; i < numTickets; i++) {
    printf("\nTicket #%d", i + 1);
    printf("\nEnter your age: ");
    scanf("%d", &age[i]);

    Prices.discountAge =
        getDiscountAge(Prices.basePrice + Prices.showtimeSurcharge, age[i]);
  }

  Prices.basePrice *= numTickets;
  Prices.finalPrice =
      Prices.basePrice + Prices.showtimeSurcharge - Prices.discountAge;

  printf("\nBase price: RM%.2f\n", Prices.basePrice);
  printf("Showtime surcharge: RM%.2f\n", Prices.showtimeSurcharge);
  printf("Age discount: -RM%.2f\n", Prices.discountAge);
  printf("Final price: RM%.2f\n", Prices.finalPrice);

  return 0;
}

//
/* *********************************** */
/* *      Function Definitions       * */
/* *********************************** */
float getBasePrice(int movieType) {
  if (movieType == 1) {
    return price2D;
  } else if (movieType == 2) {
    return price3D;
  } else if (movieType == 3) {
    return priceIMAX;
  } else {
    return 0.0;
  }
}

float getSurcharge(float basePrice, int showtimeHour, char day[]) {
  if (strcmp(day, "Saturday") == 0 || strcmp(day, "Sunday") == 0) {
    return basePrice * surchargeWeekend;
  } else if (showtimeHour >= 18) {
    return basePrice * surchargeWeekdayEvening;
  } else {
    return 0.0;
  }
}

float getDiscountAge(float basePrice, int age) {
  float discount = 0.0;

  if (age < 12) {
    return discount += basePrice * discChild;
  } else if (age >= 60) {
    return discount += basePrice * discSenior;
  } else {
    return 0.0;
  }
}
