// Include, Using, Define
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// Structures, Enumerators
struct NAME {
    string first, middle, last;
};

struct BOARD_PASS {
    char flightNum[6];
    int takenSeats;
};

struct CLIENT {
    struct NAME name;
    int age;
    char egn[11];
    struct BOARD_PASS bp;
};

struct PLANES {
    string manufacturer;
    string modelName;
    int maxSeats;
};

enum MONTHS {
    January = 1,
    February = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
};

struct TAKE_OFF_TIME {
    enum MONTHS month;
    int day;
    int hour;
    int minutes;
};

struct FLIGHT {
    char flightNum[6];
    string origin, destination;
    float distanceToDestination;
    struct PLANES plane;
};

// Functions
void mainMenu(bool& inMainLoop, FLIGHT flight[], int& flightCounter, CLIENT client[], int& clientCounter); //mainMenu

void registerFlight(FLIGHT flight[], int& flightCounter);

void registrationClient(CLIENT client[], int& clientCounter); //registration Client

void informationClient(CLIENT client[], int& clientCounter); //information Client

void removeClient(CLIENT client[], int& clientCounter); //Remove Client

// Main
int main()
{
    int clientCounter = 0;
    struct CLIENT client[20];
    int flightCounter = 0;
    struct FLIGHT flight[20];
    bool inMainLoop = true;
    while (inMainLoop)
    {
        mainMenu(inMainLoop, flight, flightCounter, client, clientCounter);
    }
}

// Functions
void mainMenu(bool& inMainLoop, FLIGHT flight[], int& flightCounter, CLIENT client[], int& clientCounter)
{
    system("CLS");
    cout << "===========| Main Menu |===========\n";

    cout << "\n0. Quit application...\n";

    cout << "\n-----/ Flight \\-----\n";
    cout << "1. Register a new Flight...\n";
    cout << "2. See Flight information...\n";
    cout << "3. Remove a Flight...\n";

    cout << "\n-----/ Client \\-----\n";
    cout << "4. Register a new Client...\n";
    cout << "5. See Client information...\n";
    cout << "6. Remove a Client...\n";

    switch (_getch())
    {
    case 48: //0 -> quit app
        inMainLoop = false;
        break;
    case 49: //1 -> register a new flight
        registerFlight(flight, flightCounter); //function
        break;
    case 50: //2 -> see flight information
        //function
        break;
    case 51: //3 -> remove a flight
        //function
        break;
    case 52: //4 -> register a new client
        registrationClient(client, clientCounter);//function
        break;
    case 53: //5 -> see client information
        informationClient(client, clientCounter);//function
        break;
    case 54: //6 -> remove a client
        removeClient(client, clientCounter);//function
        break;
    default:
        cout << "Error...";
        break;
    }
}

void registrationClient(CLIENT client[], int& clientCounter) //registration client Function
{
    system("CLS");
    cout << "First name: ";
    cin >> client[clientCounter].name.first;
    cout << "Middle name: ";
    cin >> client[clientCounter].name.middle;
    cout << "Last name: ";
    cin >> client[clientCounter].name.last;
    cout << "Age: ";
    cin >> client[clientCounter].age;
    cout << "EGN: ";
    cin >> client[clientCounter].egn;
    cout << "Board pass\n";
    cout << "Flight Num: ";
    cin >> client[clientCounter].bp.flightNum;
    cout << "Taken Seats: ";
    cin >> client[clientCounter].bp.takenSeats;
    
    clientCounter++;
}

void informationClient(CLIENT client[], int& clientCounter) //information Client Function
{
    system("CLS");
    for (int i = 0; i < clientCounter; i++)
    {
        cout << "id:" << i;
        cout << "\nName: "<< client[i].name.first<<" "<< client[i].name.middle<<" "<< client[i].name.last;
        cout << "\nAge: " << client[i].age;
        cout << "\nEGN: " << client[i].egn;
        cout << "\nBoard pass\n";
        cout << "Flight Num: " << client[i].bp.flightNum;
        cout << "\nTaken Seats: " << client[i].bp.takenSeats << "\n";
        cout << "\n";

    }
    system("PAUSE");
}

void removeClient(CLIENT client[], int& clientCounter) //Remove Client Function
{
    
    system("CLS");
    int index;
    cout << "Choose id: ";
    cin >> index;
    if (index > clientCounter ) //checking index in range of client counter 
    {
        cout << "Error...\n";
    }
    else 
    {
        for (int i = index; i < clientCounter-1; i++) //delete index registration client
        {
            client[i] = client[i + 1];
        }
        clientCounter--;
        
        for (int i = 0; i < clientCounter; i++) //couting new list of clients
        {
            cout << "id:" << i;
            cout << "\nName: " << client[i].name.first << " " << client[i].name.middle << " " << client[i].name.last;
            cout << "\nAge: " << client[i].age;
            cout << "\nID: " << client[i].id; //bug!!! replace twice when element than 10
            cout << "\nEGN: " << client[i].egn;
            cout << "\nBoard pass\n";
            cout << "Flight Num: " << client[i].bp.flightNum;
            cout << "\nTaken Seats: " << client[i].bp.takenSeats << "\n";
            cout << "\n";

        }
    }
    system("PAUSE");
}

void registerFlight(FLIGHT flight[], int& flightCounter)
{
    system("CLS");

    cout << "Flight Number(6 symbols): "; cin >> flight[flightCounter].flightNum;
    cout << "Country/City of origin: "; cin >> flight[flightCounter].origin;
    cout << "Destination: "; cin >> flight[flightCounter].destination;
    cout << "Travel Distance(km): "; cin >> flight[flightCounter].distanceToDestination;
    cout << "Plane: ";
    cout << "\n----Manufacturer: "; cin >> flight[flightCounter].plane.manufacturer;
    cout << "----Model name: "; cin >> flight[flightCounter].plane.modelName;
    cout << "----Max seats: "; cin >> flight[flightCounter].plane.maxSeats;

    flightCounter++;
}
