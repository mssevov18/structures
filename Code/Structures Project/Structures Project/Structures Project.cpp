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

struct TAKE_OFF_TIME {
    int month;
    int day;
};

struct FLIGHT {
    char flightNum[6];
    string origin, destination;
    float distanceToDestination;
    struct PLANES plane;
    TAKE_OFF_TIME timeOfTakeOff;
};

// Functions
void mainMenu(bool& inMainLoop, FLIGHT flight[], int& flightCounter, CLIENT client[], int& clientCounter); //mainMenu

void registerFlight(FLIGHT flight[], int& flightCounter); //registration Flight

void informationFlight(FLIGHT flight[], int& flightCounter); //information Flight

void editFlight(FLIGHT flight[], int& flightCounter); //Edit Flight 

void registrationClient(CLIENT client[], int& clientCounter); //registration Client

void informationClient(CLIENT client[], int& clientCounter); //information Client

void removeClient(CLIENT client[], int& clientCounter); //Remove Client

void editClient(CLIENT client[], int& clientCounter); //Edit Client 

void checkMonth(FLIGHT flight[], int i); //Checks if the month is possible

void checkDay(FLIGHT flight[], int i); //Checks if the day is possible

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

    cout << "\nEsc. Quit application...\n";

    cout << "\n-----/ Flight \\-----\n";
    cout << "1. Register a new Flight...\n";
    cout << "2. See Flight information...\n";
    cout << "3. Remove a Flight...\n";

    cout << "\n-----/ Client \\-----\n";
    cout << "4. Register a new Client...\n";
    cout << "5. See Client information...\n";
    cout << "6. Remove a Client...\n";

    cout << "\n-----/ Edit \\-----\n";

    cout << "7. Edit client info...\n";
    cout << "8. Edit Flight info...\n";


    switch (_getch())
    {
    case 27: //0 -> quit app
        inMainLoop = false;
        break;
    case 49: //1 -> register a new flight
        registerFlight(flight, flightCounter); //function
        break;
    case 50: //2 -> see flight information
        informationFlight(flight, flightCounter);//function
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
    case 55: //7 -> edit client
        editClient(client, clientCounter);//function
        break;
    case 56: //8 -> edit Flight
        editFlight(flight, flightCounter);//function
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
    cout << "Flight Num(6 symbols): ";
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
    _getch();
}

void removeClient(CLIENT client[], int& clientCounter) //Remove Client Function
{
    informationClient(client, clientCounter);
    removeStart:
    system("CLS");
    int index;
    cout << "Choose id: ";
    cin >> index;
    if (index > clientCounter or index < 0) //checking index in range of client counter 
    {
        cout << "Error...\n";
        goto removeStart;
    }
    else
    {
        cout << "id:" << index;
        cout << "\nName: " << client[index].name.first << " " << client[index].name.middle << " " << client[index].name.last;
        cout << "\nAge: " << client[index].age;
        cout << "\nEGN: " << client[index].egn;
        cout << "\nBoard pass\n";
        cout << "Flight Num: " << client[index].bp.flightNum;
        cout << "\nTaken Seats: " << client[index].bp.takenSeats << "\n";
        cout << "\n";


        for (int i = index; i < clientCounter - 1; i++) //delete index registration client
        {
            client[i] = client[i + 1];
        }
        clientCounter--;

    }
    _getch();
}

void editClient(CLIENT client[], int& clientCounter)
{
editClientStart:
    informationClient(client, clientCounter);
    system("CLS");
    int index;
    struct CLIENT temp;
    cout << "===========| Edit Menu Client |===========\n";

    cout << "\n0 Back to the Main Menu...\n";

    cout << "\n1.Edit Name...\n";
    cout << "2.Edit age...\n";
    cout << "3.Edit EGN...\n";
    cout << "4.Edit flight num...\n";
    cout << "5.Edit taken seats...\n";

    _getch();
    cout << "\nchoose ID: ";
    cin >> index;
    if (index > clientCounter or index < 0)
    {
        cout << "\nError...\n";
        _getch();
        goto editClientStart;
    }
    switch (_getch()) //second menu
    {
    case 48: //0 -> back to the Main Menu
        break;
    case 49: //1 -> edit name

        cout << "Old name: " << client[index].name.first << " " << client[index].name.middle << " " << client[index].name.last << "\n";
        cout << "New name: ";
        cin >> temp.name.first;
        cin >> temp.name.middle;
        cin >> temp.name.last;
        cout << "\n1.Save new name\n";
        cout << "2.Cancel the new name\n";
        switch (_getch()) // save or cancel the new name
        {
        case 49: //1 -> save new name
            client[index].name.first = temp.name.first; //change old name with new name
            client[index].name.middle = temp.name.middle;
            client[index].name.last = temp.name.last;
            cout << "\nNew name is saved.\n";
            _getch();
            break;
        case 50: //2 -> Cancel the new name
            cout << "\nNothing has changed.\n";
            _getch();
            break;
        }

        break;
    case 50: //2 -> edit age

        cout << "Old age: " << client[index].age << "\n";
        cout << "New age: ";
        cin >> temp.age;
        cout << "\n1.Save new age\n";
        cout << "2.Cancel the new age\n";
        switch (_getch()) // save or cancel the new age
        {
        case 49: //1 -> save new age
            client[index].age = temp.age; //change old age with new age
            cout << "\nNew age is saved.\n";
            _getch();
            break;
        case 50: //2 -> Cancel the new age
            cout << "\nNothing has changed.\n";
            _getch();
            break;
        }

        break;
    case 51: //3 -> edit EGN

        cout << "Old EGN: " << client[index].egn << "\n";
        cout << "New EGN: ";
        cin >> temp.egn;
        cout << "\n1.Save new EGN\n";
        cout << "2.Cancel the new EGN\n";
        switch (_getch()) // save or cancel the new EGN
        {
        case 49: //1 -> save new EGN
            swap(client[index].egn, temp.egn); //change old EGN with new EGN
            cout << "\nNew EGN is saved.\n";
            _getch();
            break;
        case 50: //2 -> Cancel the new EGN
            cout << "\nNothing has changed.\n";
            break;
        }

        break;
    case 52: //4 -> edit flight num

        cout << "Old flight number: " << client[index].bp.flightNum << "\n";
        cout << "New flight number: ";
        cin >> temp.bp.flightNum;
        cout << "\n1.Save new flight number\n";
        cout << "2.Cancel the new flight number\n";
        switch (_getch()) // save or cancel the new flight num
        {
        case 49: //1 -> save new flight num
            cout << "\nNew flight number is saved.\n";
            swap(client[index].bp.flightNum, temp.bp.flightNum); //change old flight num with new flight num
            break;
        case 50: //2 -> Cancel the new flight num
            cout << "\nNothing has changed.\n";
            break;
        }

        break;
    case 53: //5 -> edit taken seats

        cout << "Old taken seats: " << client[index].bp.takenSeats << "\n";
        cout << "New taken seats: ";
        cin >> temp.bp.takenSeats;
        cout << "\n1.Save new taken seats\n";
        cout << "2.Cancel the new taken seats\n";
        switch (_getch()) // save or cancel the new taken seats
        {
        case 49: //1 -> save new taken seats
            client[index].bp.takenSeats = temp.bp.takenSeats; //change old taken seats with new taken seats
            _getch();
            break;
        case 50: //2 -> Cancel the new taken seats
            cout << "\nNew taken seats is cancel.\n";
            _getch();
            break;
        }

        break;
    }

    cout << "\nNew Client Info:";
    cout << "\nid:" << index; //couting all information of client
    cout << "\nName: " << client[index].name.first << " " << client[index].name.middle << " " << client[index].name.last;
    cout << "\nAge: " << client[index].age;
    cout << "\nEGN: " << client[index].egn;
    cout << "\nBoard pass\n";
    cout << "Flight Num: " << client[index].bp.flightNum;
    cout << "\nTaken Seats: " << client[index].bp.takenSeats << "\n";
    cout << "\n";
    _getch();
}

void registerFlight(FLIGHT flight[], int& flightCounter)
{
    system("CLS");

    cout << "Flight Number(6 symbols): "; cin >> flight[flightCounter].flightNum;
    cout << "Country/City of origin: "; cin >> flight[flightCounter].origin;
    cout << "Destination: "; cin >> flight[flightCounter].destination;
    cout << "Travel Distance(km): "; cin >> flight[flightCounter].distanceToDestination;
    int month;
    cout << "Take off date(26.8): "; cin >> flight[flightCounter].timeOfTakeOff.day >> flight[flightCounter].timeOfTakeOff.month;
    checkMonth(flight, flightCounter);
    checkDay(flight, flightCounter);
    cout << "Plane: ";
    cout << "\n-  -Manufacturer: "; cin >> flight[flightCounter].plane.manufacturer;
    cout << "-  -Model name: "; cin >> flight[flightCounter].plane.modelName;
    cout << "-  -Max seats: "; cin >> flight[flightCounter].plane.maxSeats;
    flightCounter++;
}

void checkMonth(FLIGHT flight[], int i) //Checks if the month is possible
{
    if (flight[i].timeOfTakeOff.month < 0 or flight[i].timeOfTakeOff.month > 12)
    {
        cout << "\tMonth not possible... Enter a new Month: "; cin >> flight[i].timeOfTakeOff.month;
        checkMonth(flight, i);
    }

}

void checkDay(FLIGHT flight[], int i) //Checks if the day is possible
{
    int maxDays;
    switch (flight[i].timeOfTakeOff.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        maxDays = 31;
        break;
    case 2:
        maxDays = 28;
    default:
        maxDays = 30;
        break;
    }

    if (flight[i].timeOfTakeOff.day < 0 or flight[i].timeOfTakeOff.day > maxDays)
    {
        cout << "\tDay not possible... Enter a new day: "; cin >> flight[i].timeOfTakeOff.day;
        checkDay(flight, i);
    }

}

void informationFlight(FLIGHT flight[], int& flightCounter)
{
    system("CLS");
    for (int i = 0; i < flightCounter; i++)
    {
        cout << "Flight Number(6 symbols): " << flight[i].flightNum;
        cout << "\nCountry/City of origin: " << flight[i].origin;
        cout << "\nDestination: " << flight[i].destination;
        cout << "\nTravel Distance(km): " << flight[i].distanceToDestination;
        cout << "\nTake off date(day.month): " << flight[i].timeOfTakeOff.day << "."; if (flight[i].timeOfTakeOff.month < 10) cout << "0"; cout << flight[i].timeOfTakeOff.month;
        cout << "\nPlane: ";
        cout << "\n-  -Manufacturer: " << flight[i].plane.manufacturer;
        cout << "\n-  -Model name: " << flight[i].plane.modelName;
        cout << "\n-  -Max seats: " << flight[i].plane.maxSeats;

    }
    _getch();
}

void editFlight(FLIGHT flight[], int& flightCounter) 
{
    int index;
    struct CLIENT temp;
    system("CLS");
    cout << "===========| Edit Menu Flight |===========\n";

    cout << "\n0 Back to the Main Menu...\n";

    switch (_getch()) //second menu
    {
    case 48: //0 -> back to the Main Menu
        break;
    }
}