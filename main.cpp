//Project
//Hendrix Travers Aloi 
//*****************************************************************************************************************************
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <conio.h>
#include <string>

using namespace std;

void text_animation(char a[100])//text animation for added aesthetic
{
    int i; double k;
    for (i=0; a[i]!='\0'; ++i)
    {
        for(k=0; k<3000000; ++k);
        cout << a[i];
    }
}

void text_animation2(char a[100])//slower text animation
{
    int i; double k;
    for (i=0; a[i]!='\0'; ++i)
    {
        for(k=0; k<30000000; ++k);//more zeros means longer time taken to animate
        cout << a[i];
    }
}

void text_animation3(char a[100])//even slower text animation
{
    int i; double k;
    for (i=0; a[i]!='\0'; ++i)
    {
        for(k=0; k<300000000; ++k);//more zeros means longer time taken to animate
        cout << a[i];
    }
}

struct order //elements contained in one node of ID 
{
    int quantity = 0; // quantity of item(s)
    string name = "", sizes = "", flavours = "", type = ""; 
    double prices = 0.00, total = 0.00;
};

order MENU( string *);

struct Node //node for ID 
{
int ID = 0;
order data; //include data under struct order.
Node *next;
};



class Queue
{
    private:
    struct Node *head, *tail;
    public:
    Queue()
    {
        head = tail = NULL;
    }
    void enQueue(int *id, order *info);
    void deQueue();
    void displayQueue(int *checkID);
    void reQueue();
    void menu();
    void showID();
    void displayAll();
    int id;
    double amount = 0;
    order csmd;
    double prc, ttl;
    int choice;
~Queue()
{
    Node *temp;
    temp = head;
    while(temp != NULL)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}
};

void Queue::enQueue(int *id, order *info) //add item into the queue
{
    Node *temp = new Node;
    temp->ID = *id;
	temp->data = *info;
    temp->next = NULL;

    if(tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void Queue::deQueue() //remove item from the queue
{
    Node *temp = new Node;
    if(head == NULL)
    {
        cout << "Cart is empty!!! Please add Item(s) to Cart" << endl;
        text_animation2 ("Going back to Cart Menu"); text_animation3("...."); cout << endl;
        cout << "" << endl;
        system("cls");
    }
    else
    {
        temp = head;
        head = head->next;
        cout << temp->data.flavours <<" "<< temp->data.type<< " has been deleted from the queue..!!\n";
        delete temp;

    }
}

void Queue::reQueue() //rearrage the queue
{
    Node *temp, *current, *next;
    current = head;
    temp = NULL;
    next = NULL;

     while(current != NULL)//reverse the list
          {
              next = current->next;
              current->next = temp;
              temp = current;
              current = next;
          }
          head = temp;
}

void Queue::displayQueue(int *checkID) //show all data in the queue
{
    Node *temp;
    int i = 0, check = *checkID, count = 0;
    double sum = 0;
    if(head == NULL)
        cout<< "Cart Empty!!! Nothing to show\n";
    else
    {
        reQueue();
        temp = head;

        while(temp!=NULL)
        {
            if(temp->ID==check)
            {
                i = count + 1;

                if(count < 1)
                {
                    cout << "\n**************************************************************************************" << endl;
                    cout << "Order ID : " << temp->ID << endl;
                    cout << "Customer Name : " << temp->data.name << endl;
                    cout << "**************************************************************************************" << endl;
                    cout << "Items | Grocery Type |  Size  |   Flavour   | Quantity | Price/item | Total Price (RM) " << endl;
                    cout << "**************************************************************************************" << endl;
                    std::cout <<std::setw(6)<< i <<"|"<<std::setw(14)<< temp->data.type <<"|"<<std::setw(8)<< temp->data.sizes <<"|"<<std::setw(13)<< temp->data.flavours;
                    std::cout <<"|"<<std::setw(10)<< temp->data.quantity <<"|"<<std::setw(12)<< temp->data.prices <<"|"<<std::setw(16)<< temp->data.total << endl;
                    sum = sum + temp->data.total;
                }
                else
                {
                    std::cout <<std::setw(6)<< i <<"|"<<std::setw(14)<< temp->data.type <<"|"<<std::setw(8)<< temp->data.sizes <<"|"<<std::setw(13)<< temp->data.flavours;
                    std::cout <<"|"<<std::setw(10)<< temp->data.quantity <<"|"<<std::setw(12)<< temp->data.prices <<"|"<<std::setw(16)<< temp->data.total << endl;
                    sum = sum + temp->data.total;
                }
                count++;
            }
            temp = temp->next;
        }
        cout << "**************************************************************************************" << endl;
        std::cout.width(69);std::cout << std::left << "Total Amount (RM) :" << std::right << setw(16)<< sum << endl;
        cout << "**************************************************************************************" << endl;
        cout<<"\n";
    }
    reQueue();
}


void Queue::menu() //Menu interface and options for one customer
{
    Node *temp;
    choice = 0;
    int id;
    string NAME;
    order data;
    srand(time(0));
    system("cls");

    //Upon registering a name, a unique ID will be given.
    cout << "Please enter name: (no space required)" << endl;
    cin  >> NAME;
    system("cls");
    cout << "Registering customer"; text_animation2 ("....");
    system("cls");

    // code to generate unique random ID which will be assigned to the user.
     id = 1000 + (rand() % 10000);
            temp = head;
            while(temp != NULL)
            {   
                if(temp->ID == id)
                {
                    id = 1000 + (rand() % 10000);
                }

                temp = temp->next;
            }

    while(choice <= 3)
    {
        odr:
        text_animation ("Hello there, "); cout <<"" << NAME; text_animation ("! welcome to MyGrocery Shop");
        cout << endl;
        cout << "this is your given ID:" << endl; 
        cout << "" << id << endl;
        text_animation ("What would you like to do?");
        cout << endl;
        cout << "=========================================================="<<"\n";
        cout << "\t Shoppping Cart "<<"\n";
        cout << "=========================================================="<<"\n";
        cout << " 1. Add Item"<<"\n";
        cout << " 2. Remove Recently Added Item"<<"\n";
        cout << " 3. Check Item"<<"\n";
        cout << " 4. Exit to Main Menu"<<"\n";
        cout << "=========================================================="<<"\n";
        cout << endl;
        cout << "=========================================================="<<"\n";
        cout << endl;
        cout << endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            system("cls");
            data = MENU(&NAME);
            enQueue(&id, &data); //add item to queue
            break;

            case 2:
            system("cls");
            deQueue(); // remove first item in queue
            break;

            case 3:
            system("cls");
            displayQueue(&id); // show all items in queue
            break;

            case 4:
            exit;
            break;

            default:
            cout << "Please enter correct choice(1-4)!!\n";
            goto odr;
            break;
        }
    }
}

void mainMenu() //User Interface for the Main Menu
{
        cout << "==========================================================" << endl;
        cout << "Welcome to MyGrocery Shop...!!" << endl;
        cout << "==========================================================" << endl;
        cout << "[1]    New Customer" << endl;
        cout << "[2]    View an Order" << endl;
        cout << "[3]    Summary Report" << endl;
        cout << "[4]    Exit Program" << endl;
        cout << "==========================================================" << endl;
        cout << "Please enter your choice: " << endl;
}

void Queue::showID()//Display all registered IDs
{
    int ID=0, j=1 , k=-1;
    cout << "How many Customers?" << endl;
    cin >> k;
    if(ID == NULL)
    {
        cout << "Hello there" << endl;
        cout << "No ID to be shown" << endl;
    }
    else
    {
        cout << "List of IDs are:" << endl;
        for(j=0; j<k; j++)
        {
        cout << "__________________________________" << endl;
        cout << "" << j << ".";
        cout << "" << ID << endl; 
        }
        
    }
    
}

void Queue::displayAll() //remove ID 
{
    system("cls");
    cout << "Deleting ID" << endl;
    cout << "Removing..." << endl;
    cout << endl;
    cout << endl;
    deQueue();
}


int main() //main function of the program
{
    Queue newCustomer, Customer;
    Node *head = NULL;
    Node *last = NULL;
    int select;
	select = 0;

	while(select <= 3)
    {
        mainMenu();//display the main menu interface
        cin >> select;
        
        switch(select)
        {
        case 1://adding order
            newCustomer.menu();
            break;

        case 2://search order from customer ID
            system("cls");
            Customer.showID();
            break;           

        case 3://display summary report of order
            system("cls");
            Customer.displayAll();
            break;

        case 4://exit
            system("cls");
            text_animation2 ("Exiting program.... Have a nice day! :) .."); //tells the user that the user is exiting the program
            break;

        default: //default key- other than the ones listed udner options will prompt user to key in a valid input.
            system("cls");
            cout << "Please enter correct choice(1-4)"; text_animation2("!!!!");
            cout << endl;
            mainMenu();//then calls back the function main menu
            break;
        }
    }

 return 0;
}

order MENU(string *nme) //Inventory items for purchase and all the preset data
{
    Queue guest;
    order details;
    int type, flavour, size;
    double amount = 0;
    details.name = *nme;
    
    system("cls");
    menu:
    cout << "\n" << "Which item to be added into cart?\n";
	cout << "==========================================================" << endl;
    cout << "[1]    Milk" << endl;
    cout << "[2]    Drink" << endl;
    cout << "[3]    Noodle" << endl;
    cout << "[4]    Cancel" << endl;
    cout << "==========================================================" << endl;
    cout << "Please enter your choice...!!" << endl;
    cin >> type;

    switch(type)
    {
    case 1:
        details.type = "Milk";
        type1:
        cout <<"\n"<< "==========================================================" << endl;
        cout << "[1]    " << "Original" << endl;
        cout << "[2]    " << "Chocolate" << endl;
        cout << "[3]    " << "Strawberry" << endl;
        cout << "==========================================================" << endl;
        cout << "Which flavour do you want?" << endl;
        cout << "Please enter your choice: " << endl;
        cin >> flavour;
        switch(flavour)
        {
        case 1:
            amount = amount + 2.50;
            details.flavours = "Original";
            break;

        case 2:
            amount = amount + 3.00;
            details.flavours = "Chocolate";
            break;

        case 3:
            amount = amount + 3.00;
            details.flavours = "Strawberry";
            break;

        default:
            cout<<"Please enter correct choice(1-3)!!\n";
            goto type1;
            break;
        }
        break;

    case 2:
        details.type = "Drink";
        type2:
        cout <<"\n"<< "==========================================================" << endl;
        cout << "[1]    " << "Mango" << endl;
        cout << "[2]    " << "Lychee" << endl;
        cout << "[3]    " << "Soya Bean" << endl;
        cout << "==========================================================" << endl;
        cout << "Which flavour do you want?" << endl;
        cout << "Please enter your choice: " << endl;
        cin >> flavour;
        switch(flavour)
        {
        case 1:
            amount = amount + 2.50;
            details.flavours = "Mango";
            break;

        case 2:
            amount = amount + 3.00;
            details.flavours = "Lychee";
            break;

        case 3:
            amount = amount + 2.50;
            details.flavours = "Soya Bean";
            break;

        default:
            cout<<"Please enter correct choice(1-3)!!\n";
            goto type2;
            break;
        }
        break;

    case 3:
        details.type = "Noodle";
        type3:
        cout <<"\n"<< "==========================================================" << endl;
        cout << "[1]    " << "Curry" << endl;
        cout << "[2]    " << "Tomyam" << endl;
        cout << "[3]    " << "Laksa" << endl;
        cout << "==========================================================" << endl;
        cout << "Which flavour do you want?" <<endl;
        cout << "Please enter your choices: " << endl;
        cin >> flavour;
        switch(flavour)
        {
        case 1:
            amount = amount + 5.00;
            details.flavours = "Curry";
            break;

        case 2:
            amount = amount + 6.00;
            details.flavours = "Tomyam";
            break;

        case 3:
            amount = amount + 7.00;
            details.flavours = "Laksa";
            break;

        default:
            cout<<"Please enter correct choice(1-3)!!\n";
            goto type3;
            break;
        }
        break;

    case 4:
            system("cls");
            cout << "order cancelled..." << endl;
            text_animation2 ("Returning to the Menu");
            cout << endl;
            main();

    default:
        cout<<"Please enter correct choice(1-4)!!\n";
        goto menu;
        break;
    }

    Size:
    cout << "==========================================================" << endl;
    cout << "Which size do you want..??" << endl;
    cout << "[1] Small" <<"\t"<< "[2] Medium" <<"\t"<< "[3] Large" << endl;
    cout << "==========================================================" << endl;
    cout << "\n";
    cin >>size;
        switch(size)
        {
            case 1:

                amount = amount - 0.50;
                details.sizes = "Small";

                break;

            case 2:
                amount = amount;
                details.sizes = "Medium";
                break;

            case 3:
                amount = amount + 0.50;
                details.sizes = "Large";

                break;

            default:
                cout<<"Please enter correct choice(1-3)!!\n";
                goto Size;
                break;
        }

    cout << "==============================================================" << endl;
    cout << "\nPlease enter the quantity of item to be added into cart..!!" << endl;
    cout << "\n";
    cout << "==============================================================" << endl;
    cout << "\n";
    cin >> details.quantity;

    if(details.quantity <= 0)
    {
        cout << "Invalid. The value cannot be less than 1!!!!\n";
        cout << "Please enter a different value :\n";
        cin >> details.quantity;
    }
    details.prices = amount;
    details.total = amount * details.quantity;
    system("cls");
    return details;
}

