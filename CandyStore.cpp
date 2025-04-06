#include <iostream>
#include <fstream>
using namespace std;

const int NUM_CANDIES = 7;
const double DISCOUNT_THRESHOLD = 10.0;
const double DISCOUNT_PERCENTAGE = 0.10;
const double TAX_RATE = 0.07;
double candyPrices[NUM_CANDIES] = {1.50, 0.75, 1.00, 0.50, 1.50, 0.60, 1.30};

string candyNames[NUM_CANDIES] = 
{
    "Rainbow Delight",
    "Choco Crunch",
    "Fizzy Fruit",
    "Jawbreaker",
    "Minty Marvel",
    "Berry Burst",
    "Toffee Treasure"
};



void displayMenu1()
{
    cout << "===== Candy Shop Menu =====" << endl;
    for (int i = 0; i < NUM_CANDIES; ++i)
    {
        cout << i + 1 << ". " << candyNames[i] << " - $" << candyPrices[i] << endl;
    }
    cout << NUM_CANDIES + 1 << ". Exit" << endl;
    cout << "===========================" << endl;
}

double calculateTotal1(int candyChoice, int quantity)
{
    if (candyChoice >= 1 && candyChoice <= NUM_CANDIES)
    {
        return candyPrices[candyChoice - 1] * quantity;
    }
    return 0.0; // Invalid candy choice
}

void displayOrderSummary1(double total)
{
    cout << "===== Order Summary =====" << endl;
    cout << "Total Cost: $" << total << endl;
    cout << "==========================" << endl;
}

void saveOrderToFile1(int choice, int quantity, double total)
{
    ofstream outFile("order_history.txt", ios::app);
    outFile << "Item: " << candyNames[choice - 1] << endl
            << "Quantity: " << quantity << endl
            << "Total: $" << total << endl;
    outFile.close();
}


void addRecord1() {
    string newName;
    double newPrice;

    cout << "Enter candy name: ";
    cin.ignore();  // Ignore any newline character in the input buffer
    getline(cin, newName);

    cout << "Enter candy price: ";
    cin >> newPrice;

    ofstream outFile("candy_records.txt", ios::app);
    outFile << "Name: " << newName << endl << "Price: $" << newPrice << endl;
    outFile.close();

    cout << "Record added successfully!" << endl;
}

void editRecord1() {
    string targetName;
    double newPrice;

    cout << "Enter candy name to edit: ";
    cin.ignore();  // Ignore any newline character in the input buffer
    getline(cin, targetName);

    cout << "Enter new price for " << targetName << ": ";
    cin >> newPrice;

    // Implement code to edit record in candy_records.txt here

    cout << "Record updated successfully!" << endl;
}

void admin1(){
    int pass;
    cout << "Enter your password: ";
    cin >> pass;

    if (pass == 230966) {
        int choice;
        cout << "1. Add Record\n2. Edit Record\n3. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord1();
                break;
            case 2:
                editRecord1();
                break;
            case 3:
                // Exit
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 to 3." << endl;
        }
    }
}

void user1() 
{
	    ofstream outFile("order_history.txt");  // Create the file
    outFile.close();

    const double DISCOUNT_THRESHOLD=10.0;
    const double DISCOUNT_PERCENTAGE=0.10;
    const double TAX_RATE=0.07;

    int choice;
    double total=0.0;
    int quantity;

    do 
	{
        displayMenu1();
        cout<<"Enter your choice (1-8): ";
        cin>>choice;

        if(choice>=1 && choice<=7) 
		{
            cout<<"Enter quantity: ";
            cin>>quantity;
            double itemTotal=calculateTotal1(choice,quantity);
            total+=itemTotal;
			saveOrderToFile1(choice, quantity, itemTotal);
        } 
		else if(choice!=8)
		 {
            cout<<"Invalid choice! Please enter a number between 1 to 8."<<endl;
         }
    		

    } 
	
	while(choice!=8);

    displayOrderSummary1(total);

    if(total>DISCOUNT_THRESHOLD)
	 {
        double discountAmount=total*DISCOUNT_PERCENTAGE;
        cout<<"Congratulations! You qualify for a $ "<<discountAmount<<" discount!"<<endl;
        total-=discountAmount;
    }

    double taxAmount=total*TAX_RATE;
    total+=taxAmount;

    cout<<"Total cost of your order after discount and tax: $"<<total<<endl;
    cout<<"Order details saved in 'order_history.txt'. Exiting the Candy Shop. Thank you for your order!"<<endl;

}

void main1() {
	
    int choice;
    double total=0.0;
    int quantity;
    do {
        cout << "Are you\n1. Admin\n2. User\n3. Exit\n";
        cin >> choice;

        if (choice == 1) {
            admin1();
        } else if (choice == 2) {
            user1();
        } else if (choice == 3) {
            cout << "\nExiting ";
        } else {
            cout << "Invalid command";
        }
    } while (choice != 3);
    do
    {
        displayMenu1();
        cout << "Enter your choice (1-" << NUM_CANDIES + 1 << "): ";
        cin >> choice;

        if (choice >= 1 && choice <= NUM_CANDIES)
        {
            cout << "Enter quantity: ";
            cin >> quantity;
            double itemTotal = calculateTotal1(choice, quantity);
            total += itemTotal;
            saveOrderToFile1(choice, quantity, itemTotal);
        }
        else if (choice != NUM_CANDIES + 1)
        {
            cout << "Invalid choice! Please enter a number between 1 to " << NUM_CANDIES + 1 << "." << endl;
        }

    } while (choice != NUM_CANDIES + 1);

   ;
}

void displayMenu2() 
{
    cout << "===== Candy Shop Menu =====" << endl;
    cout << "1. Rainbow Delight - $1.50" << endl;
    cout << "2. Choco Crunch - $0.75" << endl;
    cout << "3. Fizzy Fruit - $1.00" << endl;
    cout << "4. Jawbreaker - $0.50" << endl;
    cout << "5. Minty Marvel - $1.50" << endl;
    cout << "6. Berry Burst - $0.60" << endl;
    cout << "7. Toffee Treasure - $1.30" << endl;
    cout << "8. Exit" << endl;
    cout << "===========================" << endl;
}

double calculateTotal2(int candyChoice, int quantity) 
{
    switch (candyChoice) 
    {
        case 1:
            return 1.50 * quantity;
        case 2:
            return 0.75 * quantity;
        case 3:
            return 1.00 * quantity;
        case 4:
            return 0.50 * quantity;
        case 5:
            return 1.50 * quantity;
        case 6:
            return 0.60 * quantity;
        case 7:
            return 1.30 * quantity;
        default:
            return 0.0;
    }
}

void displayOrderSummary2(double total) 
{
    cout << "===== Order Summary =====" << endl;
    cout << "Total Cost: $" << total << endl;
    cout << "==========================" << endl;
}

void saveOrderToFile2(int choice, int quantity, double total) 
{
    ofstream outFile("order_history.txt", ios::app);
    outFile << "Item: " << choice << endl << "Quantity: " << quantity << endl << "Total: $" << total << endl;
    outFile.close();
}

void addRecord2() 
{
    string* newName = new string;
    double* newPrice = new double;

    cout << "Enter candy name: ";
    cin.ignore();  
    getline(cin, *newName);

    cout << "Enter candy price: ";
    cin >> *newPrice;

    ofstream outFile("candy_records.txt", ios::app);
    outFile << "Name: " << *newName << endl << "Price: $" << *newPrice << endl;
    outFile.close();

    cout << "Record added successfully!" << endl;

    cout << "===== Candy Shop Menu =====" << endl;
    cout << "1. Rainbow Delight - $1.50" << endl;
    cout << "2. Choco Crunch - $0.75" << endl;
    cout << "3. Fizzy Fruit - $1.00" << endl;
    cout << "4. Jawbreaker - $0.50" << endl;
    cout << "5. Minty Marvel - $1.50" << endl;
    cout << "6. Berry Burst - $0.60" << endl;
    cout << "7. Toffee Treasure - $1.30" << endl;
    cout << "8. " << *newName << " - " << *newPrice << endl;
    cout << "===========================" << endl;

    // Deallocate memory
    delete newName;
    delete newPrice;
}

void editRecord2() 
{
    string* targetName = new string;
    double* newPrice = new double;

    cout << "Enter candy name to edit: ";
    cin.ignore(); 
    getline(cin, *targetName);

    cout << "Enter new price for " << *targetName << ": ";
    cin >> *newPrice;
    cout << "Record updated successfully!" << endl;

    // Deallocate memory
    delete targetName;
    delete newPrice;
}

void admin2() 
{
    int pass;
    cout << "Enter your password: ";
    cin >> pass;

    if (pass == 230966) 
    {
        int choice;
        cout << "1. Add Record\n2. Edit Record\n3. Exit\n";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                addRecord2();
                break;
            case 2:
                editRecord2();
                break;
            case 3:
                // Exit
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 to 3." << endl;
        }
    }
}

void user2() 
{
    ofstream outFile("order_history.txt");  
    outFile.close();

    const double DISCOUNT_THRESHOLD = 10.0;
    const double DISCOUNT_PERCENTAGE = 0.10;
    const double TAX_RATE = 0.07;

    int choice;
    double total = 0.0;
    int quantity;

    do 
    {
        displayMenu2();
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        if (choice >= 1 && choice <= 7) 
        {
            cout << "Enter quantity: ";
            cin >> quantity;
            double itemTotal = calculateTotal2(choice, quantity);
            total += itemTotal;
            saveOrderToFile2(choice, quantity, itemTotal);
        } 
        else if (choice != 8) 
        {
            cout << "Invalid choice! Please enter a number between 1 to 8." << endl;
        }
    } while (choice != 8);

    displayOrderSummary2(total);

    if (total > DISCOUNT_THRESHOLD) 
    {
        double discountAmount = total * DISCOUNT_PERCENTAGE;
        cout << "Congratulations! You qualify for a $ " << discountAmount << " discount!" << endl;
        total -= discountAmount;
    }

    double taxAmount = total * TAX_RATE;
    total += taxAmount;

    cout << "Total cost of your order after discount and tax: $" << total << endl;
    cout << "Order details saved in 'order_history.txt'. Exiting the Candy Shop. Thank you for your order!" << endl;
}
void main2() 
{
    int choice;
    do 
    {
        cout << "Are you\n1. Admin\n2. User\n3. Exit\n";
        cin >> choice;

        if (choice == 1) 
        {
            admin2();
        } 
        else if (choice == 2) 
        {
            user2();
        } 
        else if (choice == 3) 
        {
            cout << "\nExiting ";
        } 
        else 
        {
            cout << "Invalid command";
        }
    } while (choice != 3);

}

void displayMenu3() 
{
    cout<<"===== Candy Shop Menu ====="<<endl;
    cout<<"1. Rainbow Delight - $1.50"<<endl;
    cout<<"2. Choco Crunch - $0.75"<<endl;
    cout<<"3. Fizzy Fruit - $1.00"<<endl;
    cout<<"4. Jawbreaker - $0.50"<<endl;
    cout<<"5. Minty Marvel - $1.50"<<endl;
    cout<<"6. Berry Burst - $0.60"<<endl;
    cout<<"7. Toffee Treasure - $1.30"<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"==========================="<<endl;
}

double calculateTotal3(int candyChoice, int quantity)
 {
    switch(candyChoice)
	{
        case 1:
            return 1.50*quantity;
        case 2:
            return 0.75*quantity;
        case 3:
            return 1.00*quantity;
        case 4:
            return 0.50*quantity;
        case 5:
            return 1.50*quantity;
        case 6:
            return 0.60*quantity;
        case 7:
            return 1.30*quantity;
        default:
            return 0.0;
    }
}

void displayOrderSummary3(double total)
 {
    cout<<"===== Order Summary ====="<<endl;
    cout<<"Total Cost: $"<<total<<endl;
    cout<<"=========================="<<endl;
}

void saveOrderToFile3(int choice, int quantity, double total) 
{
    	ofstream outFile("order_history.txt",ios::app);
        outFile<<"Item: "<<choice<<endl<<"Quantity: "<<quantity<<endl<<"Total: $"<<total<<endl;
        outFile.close();
    
}


void addRecord3() 
{
    string newName;
    double newPrice;

    cout << "Enter candy name: ";
    cin.ignore();  // Ignore any newline character in the input buffer
    getline(cin, newName);

    cout << "Enter candy price: ";
    cin >> newPrice;

    ofstream outFile("candy_records.txt", ios::app);
    outFile << "Name: " << newName << endl << "Price: $" << newPrice << endl;
    outFile.close();

    cout << "Record added successfully!" << endl;
    
    cout<<"===== Candy Shop Menu ====="<<endl;
    cout<<"1. Rainbow Delight - $1.50"<<endl;
    cout<<"2. Choco Crunch - $0.75"<<endl;
    cout<<"3. Fizzy Fruit - $1.00"<<endl;
    cout<<"4. Jawbreaker - $0.50"<<endl;
    cout<<"5. Minty Marvel - $1.50"<<endl;
    cout<<"6. Berry Burst - $0.60"<<endl;
    cout<<"7. Toffee Treasure - $1.30"<<endl;
    cout<<"8. "<<newName<<" - "<<newPrice<<endl;
	cout<<"==========================="<<endl;
}

void editRecord3() 
{
    string targetName;
    double newPrice;

    cout << "Enter candy name to edit: ";
    cin.ignore(); 
    getline(cin, targetName);

    cout << "Enter new price for " << targetName << ": ";
    cin >> newPrice;
    cout << "Record updated successfully!" << endl;
}

void admin3() 
{
    int pass;
    cout << "Enter your password: ";
    cin >> pass;

    if (pass == 230966)
	 {
        int choice;
        cout << "1. Add Record\n2. Edit Record\n3. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord3();
                break;
            case 2:
                editRecord3();
                break;
            case 3:
                // Exit
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 to 3." << endl;
        }
    }
}

void user3() 
{
	ofstream outFile("order_history.txt");  // Create the file
    outFile.close();

    const double DISCOUNT_THRESHOLD=10.0;
    const double DISCOUNT_PERCENTAGE=0.10;
    const double TAX_RATE=0.07;

    int choice;
    double total=0.0;
    int quantity;

    do 
	{
        displayMenu3();
        cout<<"Enter your choice (1-8): ";
        cin>>choice;

        if(choice>=1 && choice<=7) 
		{
            cout<<"Enter quantity: ";
            cin>>quantity;
            double itemTotal=calculateTotal3(choice,quantity);
            total+=itemTotal;
			saveOrderToFile3(choice, quantity, itemTotal);
        } 
		else if(choice!=8)
		 {
            cout<<"Invalid choice! Please enter a number between 1 to 8."<<endl;
         }
    		

    } 
	
	while(choice!=8);

    displayOrderSummary3(total);

    if(total>DISCOUNT_THRESHOLD)
	 {
        double discountAmount=total*DISCOUNT_PERCENTAGE;
        cout<<"Congratulations! You qualify for a $ "<<discountAmount<<" discount!"<<endl;
        total-=discountAmount;
    }

    double taxAmount=total*TAX_RATE;
    total+=taxAmount;

    cout<<"Total cost of your order after discount and tax: $"<<total<<endl;
    cout<<"Order details saved in 'order_history.txt'. Exiting the Candy Shop. Thank you for your order!"<<endl;

}

void main3()
 {
    int choice;
    do {
        cout << "Are you\n1. Admin\n2. User\n3. Exit\n";
        cin >> choice;

        if (choice == 1) 
		{
            admin3();
        } else if (choice == 2) 
		{
            user3();
        } else if (choice == 3) 
		{
            cout << "\nExiting ";
        } else {
            cout << "Invalid command";
        }
    } while (choice != 3);

    
}
int main() 
{
	int userChoice;
    do
    {
    
    	cout << "\nThe program you want to run \n1.Simple Variable\n2.Arrays\n3.Pointers\n4.Exit\n ";
	    cout << "Enter your choice:";
	    cin >> userChoice;
	
		switch (userChoice) 
		{
	        case 1:
	            {
				    main2();
				}
			    break;
	        case 2:
	            {
					main1();
		    	}
	            break;
	        case 3:
	            {
	            	main3();
				}
	            break;
	        case 4:
			    {
					cout<<"Exiting";
			    }  
                break;    	        
			default:		
	            cout << "Invalid choice.\n";
	            break;
		}
	}while(userChoice!=4);
    return 0;
}
