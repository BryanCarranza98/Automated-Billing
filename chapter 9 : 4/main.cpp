
//Bryan Carranza 
//This program helps a restaurant automate its breakfast billing system. The customer inputs the numbers corresponding to the menu items, and then enters 0 to complete their order. The program then outputs the selected items, calculates the sales tax, and provides the total amount owed.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct menuItemType //This struct defines the components of menuItemType.
{
    string menuItem;
    double itemPrice;
};

void getData(menuItemType menuList[]); //This function loads data into the array menuList.
void showMenu(menuItemType menuList[], int x); //This function shows the different items offered by the restaurant.
void printCheck(menuItemType menuList[], int menuOrder[], int x); //This function calulates and prints the check.

int main()
{
    const int menuItems = 8;
    menuItemType menuList[menuItems];
    int menuOrder[menuItems] = {0};
    int orderSelection = 0;
    bool ordering = true;
    
    getData(menuList);
    showMenu(menuList, menuItems);
    
    while(ordering)
    {
        cout << endl << "Please enter the corresponding number for the item you would like to order, or enter 0 to finish and see the total."
        << endl;
        cin >> orderSelection;
        
        if (orderSelection > 0 && orderSelection <= menuItems)
        {
            menuOrder[orderSelection - 1] += 1;
        }
        else
            ordering = false;
    }
    
    printCheck(menuList, menuOrder, menuItems);
    
    return 0;
}

void getData(menuItemType menuList[])
{
    menuItemType plainEgg;
    menuItemType baconEgg;
    menuItemType muffin;
    menuItemType frenchToast;
    menuItemType fruitBasket;
    menuItemType cereal;
    menuItemType coffee;
    menuItemType tea;
    
    plainEgg.menuItem = "Plain Egg         ";
    plainEgg.itemPrice = 1.45;
    baconEgg.menuItem = "Bacon and Egg     ";
    baconEgg.itemPrice = 2.45;
    muffin.menuItem = "Muffin            ";
    muffin.itemPrice = 0.99;
    frenchToast.menuItem = "French Toast      ";
    frenchToast.itemPrice = 1.99;
    fruitBasket.menuItem = "Fruit Basket      ";
    fruitBasket.itemPrice = 2.49;
    cereal.menuItem = "Cereal            ";
    cereal.itemPrice = 0.69;
    coffee.menuItem = "Coffee            ";
    coffee.itemPrice = 0.50;
    tea.menuItem = "Tea               ";
    tea.itemPrice = 0.75;
    
    menuList[0] = plainEgg;
    menuList[1] = baconEgg;
    menuList[2] = muffin;
    menuList[3] = frenchToast;
    menuList[4] = fruitBasket;
    menuList[5] = cereal;
    menuList[6] = coffee;
    menuList[7] = tea;
}

void showMenu(menuItemType menuList[], int x)
{
   int count;
    
    cout << "Welcome to Johnny's Restaurant" << endl;
    cout << "What would you like to order?" << endl << endl;
    
    
   for(count = 0; count < x; count++)
    {
        cout << setprecision (2) << fixed << setw (2) << left << "[" << count + 1 << "]"
        << menuList[count].menuItem << '$'
        << menuList[count].itemPrice << endl;
    }
}

void printCheck(menuItemType menuList[], int menuOrder[], int menuItems)
{
    double orderTax = 0;
    double totalPrice = 0;
    const double TAX = .05;
    
    cout << endl << "Thank you for your order!" << endl << endl << "Here are the items you selected: " << endl;
    
    for(int i = 0; i < menuItems; i++)
    {
        if(menuOrder[i] > 0)
        {
            cout << setprecision (2) << setw (10) << left << menuList[i].menuItem
            << '$' << (menuList[i].itemPrice * menuOrder[i]) << endl;
            totalPrice += (menuList[i].itemPrice * menuOrder[i]);
        }
    }
    
    orderTax = totalPrice * TAX;
    totalPrice += orderTax;
    
    cout << setprecision (2) << fixed << setw (18) << left << endl << "Tax    " << "$" << orderTax << endl
    << setw (18) << left << "Total    " << "$" << totalPrice << endl;
    
}

