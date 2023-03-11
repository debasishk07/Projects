#include<stdio.h>
#include<stdlib.h>

#define MAX_CUSTOMERS 108
#define MAX_PRODUCTS 50

struct Product {
    char name[20];
    float price;
    int quantity;
};

struct Customer {
    char name[30];
    char address[100];
    char phone[20];
    struct Product products[MAX_CUSTOMERS];
    int num_products;
};

struct Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void add_customer();
void add_product(struct Customer *customer);
void generate_bill(struct Customer customer);

int main() {
    int choice;
    do {
        printf("\n1.ADD CUSTOMER\n");
        printf("2.ADD PRODUCT\n");
        printf("3.GENERATE BILL\n");
        printf("4.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
            add_customer();
            break;
            case 2:
            add_product(&customers[num_customers-1]);
            break;
            case 3:
            generate_bill(customers[num_customers-1]);
            break;
            case 4:
            printf("Exiting program...\n");
            break;
            default:
            printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
    return 0;
}
void add_customer() {
    struct Customer new_customer;

    printf("Enter customer name: ");
    scanf("%s", new_customer.name);

    printf("Enter customer address: ");
    scanf("%s", new_customer.address);

    printf("Enter the customer phone number: ");
    scanf("%s", new_customer.phone);

    new_customer.num_products = 0;

    customers[num_customers] = new_customer;
    num_customers++;
}

void add_product(struct Customer *customer) {
    if (customer->num_products == MAX_PRODUCTS) {
        printf("Customer has reached the maxumum number of products.\n");
        return;
    }
    struct Product new_product;
    printf("Enter the product name: ");
    scanf("%s", new_product.name);

    printf("Ente the product price: ");
    scanf("%f", &new_product.price);

    printf("Enter the product quantity: ");
    scanf("%d", &new_product.quantity);

    customer->products[customer->num_products] = new_product;
    customer->num_products++;
}

void generate_bill(struct Customer customer){
    int i;
    float total = 0;

    printf("\n\nCustomer name: %s\n", customer.name);
    printf("Address: %s\n", customer.address);
    printf("Phone number: %s\n\n", customer.phone);

    printf("Product\t\tPrice\tQuantity\tTotal\n");

    for(i=0;i<customer.num_products; i++){
        printf("%s\t\t%.2f\t%d\t\t%.2f\n", customer.products[i].name, customer.products[i].price, customer.products[i].quantity, customer.products[i].price * customer.products[i].quantity);
        total += customer.products[i].price * customer.products[i].quantity;
    }

    printf("\nTotal Bill: %.2f\n", total);
}
