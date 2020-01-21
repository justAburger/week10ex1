#include"Customer.h"
#include<map>

#define EXIT 4
#define SECOND_EXIT 3
#define SIZE_OF_ITEMS 10

#define OPTION_ADD_COSTUMER 1
#define OPTION_UPDATE_COSTUMER 2
#define OPTION_PRINT_MAX 3

#define SECONDARY_OPTION_ADD 1
#define SECONDARY_OPTION_REMOVE 2


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::map;


int chooseFromMenu();
int chooseFromItems(Item* itemList);
int chooseFromSecondMenu();

int main()
{

	map<string, Customer> abcCustomers;
	Item itemList[SIZE_OF_ITEMS] = {
		Item("Milk","00001",5.3),
		Item("Cookies","00002",12.6),
		Item("bread","00003",8.9),
		Item("chocolate","00004",7.0),
		Item("cheese","00005",15.3),
		Item("rice","00006",6.2),
		Item("fish", "00008", 31.65),
		Item("chicken","00007",25.99),
		Item("cucumber","00009",1.21),
		Item("tomato","00010",2.32) };

	int choicesTaken[SIZE_OF_ITEMS] = { 0 };
	int choice = 1;
	int choice2 = 1;
	string currCustomerName;
	
	while (choice != EXIT)
	{
		//get choice
		choice = chooseFromMenu();

		switch (choice)
		{
		//4 opitons are availabe
		case OPTION_ADD_COSTUMER:
		{
			cout << "Enter the name of the Customer:" << endl;
			cin >> currCustomerName;
			system("cls");
			//if costumer is already in list
			while (abcCustomers.find(currCustomerName) != abcCustomers.end())
			{
				cout << "customer already exsist, please try again:" << endl;
				cin >> currCustomerName;
				system("cls");
			}

			Customer currentCustomer(currCustomerName);

			while (choice2 != 0)
			{
				choice2 = chooseFromItems(itemList);
				if (choice2 != 0)
				{
					currentCustomer.addItem(itemList[choice2 - 1]);
				}
			}
			abcCustomers.insert({currCustomerName,currentCustomer});
			choice2 = 0;
			break;
		}
		case OPTION_UPDATE_COSTUMER: 
		{
			//first knowing which costumer needs to change
			cout << "Enter name of the Customer:" << endl;
			cin >> currCustomerName;
			system("cls");
			//looking for the costumer
			std::map<std::string,Customer>::iterator it = abcCustomers.begin();
			it = abcCustomers.find(currCustomerName);
			while (it == abcCustomers.end())
			{
				cout << "customer does not exsist, please try again:" << endl;
				cin >> currCustomerName;
				system("cls");
				it = abcCustomers.find(currCustomerName);
			}

			//printing his items
			cout << "items of " << currCustomerName << " are:" << endl;
			Customer* currentCustomer;
			currentCustomer = &abcCustomers[currCustomerName];
			currentCustomer->printItems();
			cout << "press any key to continue..." << endl;
			getchar();
			getchar();
			choice2 = chooseFromSecondMenu();
			while (choice2 != SECOND_EXIT)
			{
				switch (choice2)
				{
				case SECONDARY_OPTION_ADD:
				{
					while (choice2 != 0)
					{
						cout << "Choose a displayed item: (0 to exit)" << endl;
						choice2 = chooseFromItems(itemList);
						if(choice2 > 0)
							currentCustomer->addItem(itemList[choice2 - 1]);
					}
					break; 
				}
				case SECONDARY_OPTION_REMOVE:
				{
					choice2 = 1;
					while(choice2 != 0)
					{
						cout << "The items you can remove are: (0 to exit)" << endl;
						choice2 = chooseFromItems(itemList);
						if (choice2 > 0)
							currentCustomer->removeItem(itemList[choice2 - 1]);
					} 
					break;
				}
				}
				choice2 = chooseFromSecondMenu();
			}
			break;
		}
		case OPTION_PRINT_MAX:
		{
			system("cls");
			double sum = 0;
			const Customer* curr{};
			for (auto it = abcCustomers.cbegin(); it != abcCustomers.cend(); it++) 
			{
				if (it->second.totalSum() > sum)
				{
					curr = &it->second;
					sum = curr->totalSum();
				}
			}
			cout << "The customer who pays the most is " << curr->getName() << endl;
			curr->printItems();
			system("PAUSE");
			break;
		}


		}
	}
	return 0;
}

/*
Function prints the options to the user as well as returning the choice
input: none/ output:the choice (int)
it also checks if input is in the right range
*/
int chooseFromMenu() 
{
	int ret;
	system("cls");
	cout << "Welcome to MagshiMart!" << endl;
	cout << "1. sign as customer and buy items" << endl;
	cout << "2. uptade existing customer's items" << endl;
	cout << "3. print the customer who pays the most" << endl;
	cout << "4. exit" << endl;
	cin >> ret;
	while (!cin || (ret < 1 || ret > EXIT)) //if the input is not correct
	{
		cout << "Bad value! Try again:";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> ret;
	}
	system("cls");
	return ret;
}

/*
Function prints the selling items in the shop
as well as getting the choice of the user (int) while checking the input
input:Item pointer/Output: int (choice)
*/
int chooseFromItems(Item* itemList)
{
	int ret;
	system("cls");
	cout << "Choose a displayed item: (0 to exit)" << endl;
	for (int i = 0; i < SIZE_OF_ITEMS; i++)
	{
		cout << i+1 << ". " << itemList[i].getName()<<" "<< itemList[i].getPrice() <<endl;		
	}
	cin >> ret;
	while ((!cin) || (ret < 0 || ret > SIZE_OF_ITEMS)) //if the input is not correct
	{
		cout << "Bad value! Try again:";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> ret;
	}
	system("cls");
	return ret;
}

/*
Function prints Three options for the user
as well as getting the choice of the user (int) while checking the input
input:none /Output: int (choice)
*/
int chooseFromSecondMenu()
{
	int ret;
	system("cls");
	cout << "1. Add items" << endl;
	cout << "2. Remove items" << endl;
	cout << "3. Back to menu" << endl;
	cin >> ret;
	while ((!cin) || (ret < 1 || ret > SECOND_EXIT)) //if the input is not correct
	{
		cout << "Bad value! Try again:";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> ret;
	}
	system("cls");
	return ret;
}