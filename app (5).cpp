#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>

using namespace std;


struct Employee {
    string firstName;
    string lastName;
    string username;
    string email;
    string phoneNumber;
    string privilege;
    string pin;
}staff, dStaff;

struct Hotel {
    int numberOfSingleBedRooms;
    int numberOfdoubleBedRooms;
    int numberOfLuxuryBedRooms;
    double priceOfSingleBedRooms;
    double priceOfdoubleBedRooms;
    double priceOfLuxuryBedRooms;
}hotel;

struct Rooms {
    string label;
    string numberfBed;
    string price;
    string catagory;
    string isBooked;
    string bookedId;
}room, eroom;


struct User {
    string firstName;
    string lastName;
    string phone;
    string email;
    string ssn;
    string checkout;
    string bookedRoom;
    string days;
}user;

// utility
void lineBreak(int amount);
void error(string msg);
void createFile(string path, string filename);
void createDb();
//string getUserName(string type);
bool userAuth(string username);
bool pinAuth(string pin);
int getId(string username);






// main app
void app();
void entryRouter();
void screenRouter(string priviledge);


// screens
/*first time screen*/
void fts();
void fts_2();
/*login*/
void loginScreen();
bool ftsLogin();
void chFtsLogin();
/*root*/
void rootDashboard();
// add staff 
void addStaff();
void singleAddStaff();
void multipleAddStaff();
void getStaffInfo();

// staff info
void singleStaffInfo();
void allStaffInfo();

// edit info
void editStaff();
/*admin*/
void adminDashboard();

// add room info
void addRoomInfo();
void writeSingleBedInfo();
void writeDoubleBedInfo();
void writeLuxuryBedInfo();

// get room info
void getRoomInfo();
void roomsPrice();
void singleRoomsPrice();
void doubleRoomsPrice();
void luxuryRoomsPrice();

// edit room info
void editRoomInfo();
void editRoomsPrice();
void editSingleRoomsPrice();
void editDoubleRoomsPrice();
void editLuxuryRoomsPrice();
/*staff*/
void staffDashboard();
void booking();
void singleBedBooking();
void doubleBedBooking();
void luxuryBedBooking();
void getUserInfo();
void writeUserInfo();
void checkAvailbility();
bool typeRoomAvailbility(string type);
bool isAvailable(string label);

bool fileExist(string fileName)
{
    bool found;
    ifstream file(fileName);
    found = file.good();
    file.close();
    return found;
}
 void leftPadd(string &str, const char labeling = 'S' )
{
        str.insert(str.begin(), labeling);
}

int main()
{
    //app();
    //adminDashboard();
    //cout << getId("sabcor");
    //staffDashboard();
    //getUserInfo();
    editSingleRoomsPrice();

   
    
}























void app() {
    // Entry router
    entryRouter();
}


void entryRouter() {
    string path = "C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\cache.csv";
    fstream file;
    if (fileExist(path)) {
        loginScreen();
    }
    else {
        file.open(path, ios::out);
        file << "fLogin,true\n";
        file << "registered,true";
        file.close();
        fts();
    }
}

void screenRouter(string priviledge) {
    system("cls");
    
  
    if (priviledge.compare("root") == 0) {
        rootDashboard();
    }
    
    if (priviledge.compare("admin") == 0) {
        adminDashboard();
    }
    
    if (priviledge.compare("staff") == 0) {
        staffDashboard();
    }
    
}




// utility
void lineBreak(int  amount) {
    string lBreak = "";
    for (int i = 0; i < amount; i++)
    {
        lBreak.append("\n");
    }
    cout << lBreak;
}
void error(string msg) {
    system("cls");
    cout << "ERR: " << msg << endl;
    system("cls");
}

void createFile(string path, string filename) {
    string filePath = path.append(filename);
    fstream file;
    file.open(filePath, ios::app);
    file.close();
}

void createDb() {
    const string path = "C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\";
    // staff db
    createFile(path, "staffDB.csv");
    // user db
    createFile(path, "userDB.csv");
    // room db
    createFile(path, "roomDB.csv");
    // transaction db
    createFile(path, "transactionDB.csv");
}

int getId(string username) {
    fstream file;
    int line = 0;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\staffDB.csv", ios::in);
    if (file.is_open()) {
        while (file.good())
        {
            ++line;
            getline(file, dStaff.firstName, ',');
            getline(file, dStaff.lastName, ',');
            getline(file, dStaff.username, ',');
            getline(file, dStaff.email, ',');
            getline(file, dStaff.privilege, ',');
            getline(file, dStaff.phoneNumber, ',');
            getline(file, dStaff.pin, '\n');
            if (dStaff.username.compare(username) == 0) {
                break;
            }

        }
        file.close();
    }
    return line;
}




bool userAuth(string username){
    fstream file;
    bool found = false;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\staffDB.csv", ios::in);
    if (file.is_open()) {
        while (file.good())
        {
            getline(file, staff.firstName, ',');
            getline(file, staff.lastName, ',');
            getline(file, staff.username, ',');
            getline(file, staff.email, ',');
            getline(file, staff.privilege, ',');
            getline(file, staff.phoneNumber, ',');
            getline(file, staff.pin, '\n');
            if (staff.username.compare(username) == 0) {
                found = true;
                break;
            }

        }
        file.close();
    }
    return found;
}
bool pinAuth(string pin) {
    fstream file;
    bool found = false;
    if (staff.pin.compare(pin) == 0) {
        found = true;
    }
    return found;
}



// screens
/*first time screen*/
void fts() {
    int option;
    cout << "Introducting better hotel reservation app" << endl;
    lineBreak(2);
    // todo
    cout << "fill description" << endl;
    lineBreak(2);
    //todo
    do
    {
        cout << "next | skip: " << endl;
        lineBreak(1);
        cout << "1. next" << endl;
        cout << "2. skip" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            fts_2();
            break;
        case 2:
            system("cls");
            loginScreen();
            break;
        default:
            system("cls");
            fts();
            break;
        }
        if (option == 1 || option == 2) {
            break;
        }
    } while (true);
}


/*first time screen 2*/
void fts_2() {
    int option;
    cout << "title" << endl;
    lineBreak(2);
    // todo
    cout << "fill description" << endl;
    lineBreak(2);
    //todo
    do
    {
        cout << "next | skip: " << endl;
        lineBreak(1);
        cout << "1. next" << endl;
        cout << "2. skip" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
        case 2:
            system("cls");
            createDb();
            loginScreen();
            break;
        default:
            system("cls");
            fts_2();
            break;
        }
        if (option == 1 || option == 2) {
            break;
        }
    } while (true);
}


/*login*/
void loginScreen() {
   
    
    if (ftsLogin()) {
        // createdb
        createDb();
        //flogin = false
        chFtsLogin();
        // root data to staff database
        fstream file;
        string path = "C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\staffDB.csv";
        file.open(path, ios::app);
        file << "root,root,root,root@gmail.com,root,0900000000,root" << endl;
        file.close();

    }
    
    int option;
    string username;
    string pin;
    cout << "login screen" << endl;
    lineBreak(2);
    cout << "Username: ";
    cin >> username;
    if (userAuth(username)) {
        system("cls");
        cout << "login screen" << endl;
        lineBreak(2);
        cout << "Pin: ";
        cin >> pin;
        if (pinAuth(pin)) {
            screenRouter(staff.privilege);
        }
    }// todo
    


}

bool ftsLogin() {
    fstream file;
    string path = "C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\cache.csv";
    string fLogin;
    string fLoginHeader;


    file.open(path, ios::in);

    if (file.is_open()) {

        getline(file, fLoginHeader, ',');
        getline(file, fLogin, '\n');
        file.close();
        if (fLogin.compare("true") == 0) {
            return true;
        }
        else {
            return false;
        }
    }
}
void chFtsLogin() {
    fstream file;
    string path = "C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\cache.csv";
    string fLogin;
    string fLoginHeader;


    file.open(path, ios::out);

    if (file.is_open()) {
        file << "fLogin,false\n";
        file << "registered,true";
        file.close();
    }
}


/*root*/
void rootDashboard() {
    int option;
    cout << "Root Dashboard" << endl;
    lineBreak(2);
    // todo
    do
    {
        cout << "1. Add staff:" << endl;
        cout << "2. get staff info:" << endl;
        cout << "3. edit staff info:" << endl;
        cout << "4. log out" << endl;
        cout << "5. exit" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            addStaff();
            break;
        case 2:
            system("cls");
            getStaffInfo();
            break;
        case 3:
            system("cls");
            editStaff();
            break;
        case 4:
            system("cls");
            loginScreen();
            break;
        case 5:
            exit(0);
            break;
        default:
            system("cls");
            rootDashboard();
            break;
        }
    } while (true);
}


// add staff info
void addStaff() {
    int option;
    cout << "Add Staff" << endl;
    lineBreak(2);
    // todo
    do
    {
        cout << "1. Single staff:" << endl;
        cout << "2. Multiple staff:" << endl;
        cout << "3. back" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            singleAddStaff();
            break;
        case 2:
            system("cls");
            multipleAddStaff();
            break;
        case 3:
            system("cls");
            rootDashboard();
            break;
        case 5:
            exit(0);
            cout << "Add Staff";
            break;
        default:
            system("cls");
            addStaff();
            break;
        }
    } while (true);

}

void singleAddStaff() {
    fstream file;
    string path = "C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\staffDB.csv";
    file.open(path, ios::app);
    

    string firstName;
    string lastName;
    string username;
    string email;
    string phoneNumber;
    string privilege;
    string pin;

    cout << "First Name: ";
    cin >> firstName;
    system("cls");
    cout << "last Name: ";
    cin >> lastName;
    system("cls");
    cout << "User Name: ";
    cin >> username;
    system("cls");
    cout << "Email: ";
    cin >> email;
    system("cls");
    cout << "Phone Number: ";
    cin >> phoneNumber;
    system("cls");
    cout << "privilege: ";
    cin >> privilege;
    system("cls");
    cout << "Pin: ";
    cin >> pin;
    system("cls");

    
    file << firstName;
    file << ",";
    file << lastName;
    file << ",";
    file << username;
    file << ",";
    file << email;
    file << ",";
    file << privilege;
    file << ",";
    file << phoneNumber;
    file << ",";
    file << pin;
    file << endl;

    file.close();
}

void multipleAddStaff() {
    int total;
    fstream file;
    string path = "C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\staffDB.csv";
    file.open(path, ios::app);


    string firstName;
    string lastName;
    string username;
    string email;
    string phoneNumber;
    string privilege;
    string pin;

    cout << "multiple Staff";
    lineBreak(1);
    cout << "How many staff do want: ";
    cin >> total;
    for (int i = 0; i < total; i++)
    {
        system("cls");
        cout << "record " << i + 1<< endl;
        cout << "First Name: ";
        cin >> firstName;
        system("cls");
        cout << "last Name: ";
        cin >> lastName;
        system("cls");
        cout << "User Name: ";
        cin >> username;
        system("cls");
        cout << "Email: ";
        cin >> email;
        system("cls");
        cout << "Phone Number: ";
        cin >> phoneNumber;
        system("cls");
        cout << "privilege: ";
        cin >> privilege;
        system("cls");
        cout << "Pin: ";
        cin >> pin;
        system("cls");


        file << firstName;
        file << ",";
        file << lastName;
        file << ",";
        file << username;
        file << ",";
        file << email;
        file << ",";
        file << privilege;
        file << ",";
        file << phoneNumber;
        file << ",";
        file << pin;
        file << endl;
        total--;
    }
    file.close();
}


// get staff Info
void getStaffInfo() {
    int option;
    cout << "Get Staff info" << endl;
    lineBreak(2);
    // todo
    do
    {
        cout << "1. Single staff info:" << endl;
        cout << "2. all staff info:" << endl;
        cout << "3. back" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            singleStaffInfo();
            break;
        case 2:
            system("cls");
            allStaffInfo();
            break;
        case 3:
            system("cls");
            rootDashboard();
            break;
        case 5:
            exit(0);
            cout << "Add Staff";
            break;
        default:
            system("cls");
            getStaffInfo();
            break;
        }
    } while (true);
};

void singleStaffInfo() {
    fstream file;
    string username;
    cout << "Search by Username: ";
    cin >> username;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\staffDB.csv", ios::in);
    if (file.is_open()) {
        while (file.good())
        {
            getline(file, dStaff.firstName, ',');
            getline(file, dStaff.lastName, ',');
            getline(file, dStaff.username, ',');
            getline(file, dStaff.email, ',');
            getline(file, dStaff.privilege, ',');
            getline(file, dStaff.phoneNumber, ',');
            getline(file, dStaff.pin, '\n');
            if (dStaff.username.compare(username) == 0) {
                system("cls");
                cout << dStaff.firstName << " "
                    << dStaff.lastName << " "
                    << dStaff.username << " "
                    << dStaff.email << " "
                    << dStaff.privilege << " "
                    << dStaff.phoneNumber << " "
                    << dStaff.pin
                    << endl;
                break;
            }

        }
        file.close();
    }
}

void allStaffInfo(){
    fstream file;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\staffDB.csv", ios::in);
    if (file.is_open()) {
        while (file.good())
        {
            getline(file, dStaff.firstName, ',');
            getline(file, dStaff.lastName, ',');
            getline(file, dStaff.username, ',');
            getline(file, dStaff.email, ',');
            getline(file, dStaff.privilege, ',');
            getline(file, dStaff.phoneNumber, ',');
            getline(file, dStaff.pin, '\n');
            system("cls");
            cout<< dStaff.firstName << " "
                << dStaff.lastName << " "
                << dStaff.username << " "
                << dStaff.email << " "
                << dStaff.privilege << " "
                << dStaff.phoneNumber << " "
                << dStaff.pin
                << endl;
        }
        file.close();
    }
}

//  edit staff
void editStaff(){
    fstream file;
    //string username;
    int line;
    string firstName;
    string lastName;
    string username;
    string email;
    string phoneNumber;
    string privilege;
    string pin;
    cout << "User name: ";
    cin >> username;
    line = getId(username);
    system("cls");
    int option;
    cout << "Admin Dashboard" << endl;
    lineBreak(2);
    // todo
    do
    {
        cout << "1. first Name:" << endl;
        cout << "2. last  Name:" << endl;
        cout << "3. User  Name:" << endl;
        cout << "4. Email:" << endl;
        cout << "5. Phone" << endl;
        cout << "6. privilege" << endl;
        cout << "7. pin:" << endl;
        cout << "5. back" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            cout << "Add Staff";
            break;
        case 2:
            system("cls");
            cout << "get Staff";
            break;
        case 3:
            system("cls");
            cout << "remove Staff";
            break;
        case 4:
            system("cls");
            loginScreen();
            break;
        case 5:
            exit(0);
            cout << "Add Staff";
            break;
        default:
            system("cls");
            adminDashboard();
            break;
        }
    } while (true);

    
     

}

/*admin*/
void adminDashboard() {
    int option;
    cout << "Admin Dashboard" << endl;
    lineBreak(2);
    // todo
    do
    {
        cout << "1. add rooms: " << endl;
        cout << "2. get rooms info: " << endl;
        cout << "3. edit room info: " << endl;
        cout << "4. log out" << endl;
        cout << "5. exit" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            addRoomInfo();
            break;
        case 2:
            system("cls");
            getRoomInfo();
            break;
        case 3:
            system("cls");
            editRoomInfo();
            break;
        case 4:
            system("cls");
            loginScreen();
            break;
        case 5:
            exit(0);
            cout << "Add Staff";
            break;
        default:
            system("cls");
            adminDashboard();
            break;
        }
        if (option == 1 || option == 2) {
            break;
        }
    } while (true);
};


// add room info
void addRoomInfo(){
    cout << "Adding room info";
    lineBreak(2);
    cout << "Number of single bed rooms: ";
    cin >> hotel.numberOfSingleBedRooms;
    cout << "Number of double bed rooms: ";
    cin >> hotel.numberOfdoubleBedRooms;
    cout << "Number of luxury bed rooms: ";
    cin >> hotel. numberOfLuxuryBedRooms;
    system("cls");
    cout << "Adding room info";
    lineBreak(2);
    cout << "Price of single bed rooms: ";
    cin >> hotel.priceOfSingleBedRooms;
    cout << "Price of double bed rooms: ";
    cin >> hotel.priceOfdoubleBedRooms;
    cout << "Price of luxury bed rooms: ";
    cin >> hotel.priceOfLuxuryBedRooms;
    writeSingleBedInfo();
    writeDoubleBedInfo();
    writeLuxuryBedInfo();
    adminDashboard();
}
void writeSingleBedInfo() {
    fstream file;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::app);
    const char  prefix = 's';
    string label;
    for (int i = 0; i < (int) hotel.numberOfSingleBedRooms; i++)
    {
        label = to_string(i);
        leftPadd(label, prefix);
        file << label;
        file << ",";
        file << "1";
        file << ",";
        file << hotel.priceOfSingleBedRooms;
        file << ",";
        file << "single";
        file << ",";
        file << "false";
        file << ",";
        file << "000" << endl;
    }
    file.close();
}
void writeDoubleBedInfo() {
    fstream file;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::app);
    const char  prefix = 'D';
    string label;
    for (int i = 0; i < (int) hotel.numberOfdoubleBedRooms; i++)
    {
        label = to_string(i);
        leftPadd(label, prefix);
        file << label;
        file << ",";
        file << "2";
        file << ",";
        file << hotel.priceOfdoubleBedRooms;
        file << ",";
        file << "double";
        file << ",";
        file << "false";
        file << ",";
        file << "000" << endl;
    }
    file.close();
}
void writeLuxuryBedInfo() {
    fstream file;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::app);
    const char  prefix = 'L';
    string label;
    for (int i = 0; i < (int) hotel.numberOfLuxuryBedRooms; i++)
    {
        label = to_string(i);
        leftPadd(label, prefix);
        file << label;
        file << ",";
        file << "3";
        file << ",";
        file << hotel.priceOfLuxuryBedRooms;
        file << ",";
        file << "luxury";
        file << ",";
        file << "false";
        file << ",";
        file << "000" << endl;
    }
    file.close();
}

// get room info
void getRoomInfo() {
    int option;
    cout << "Get Staff info" << endl;
    lineBreak(2);
    // todo
    do
    {
        cout << "1. Room Price: " << endl;
        cout << "2. back" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            roomsPrice();
            break;
        case 2:
            system("cls");
            adminDashboard();
            break;
        default:
            system("cls");
            getRoomInfo();
            break;
        }
    } while (true);
}
void roomsPrice() {
    int option;
    cout << "Room Price info" << endl;
    lineBreak(2);
    // todo
    do
    {
        cout << "1. Single rooms: " << endl;
        cout << "2. Double Rooms: " << endl;
        cout << "3. Luxury Rooms: " << endl;
        cout << "4. back" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            singleRoomsPrice();
            break;
        case 2:
            system("cls");
            doubleRoomsPrice();
            break;
        case 3:
            system("cls");
            luxuryRoomsPrice();
            break;
        case 4:
            system("cls");
            getRoomInfo();
            break;
        default:
            system("cls");
            roomsPrice();
            break;
        }
    } while (true);

}
void singleRoomsPrice(){
    
    fstream file;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::in);
    if (file.is_open()) {
        while (file.good())
        {
            getline(file, room.label, ',');
            getline(file, room.numberfBed, ',');
            getline(file, room.price, ',');
            getline(file, room.catagory, ',');
            getline(file, room.isBooked, ',');
            getline(file, room.bookedId, '\n');
            if (room.catagory.compare("single") == 0) {
                system("cls");
                cout << room.price;
                break;
            }

        }
        file.close();
    }


}
void doubleRoomsPrice(){
    fstream file;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::in);
    if (file.is_open()) {
        while (file.good())
        {
            getline(file, room.label, ',');
            getline(file, room.numberfBed, ',');
            getline(file, room.price, ',');
            getline(file, room.catagory, ',');
            getline(file, room.isBooked, ',');
            getline(file, room.bookedId, '\n');
            if (room.catagory.compare("double") == 0) {
                system("cls");
                cout << room.price;
                break;
            }

        }
        file.close();
    }
}
void luxuryRoomsPrice(){
    fstream file;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::in);
    if (file.is_open()) {
        while (file.good())
        {
            getline(file, room.label, ',');
            getline(file, room.numberfBed, ',');
            getline(file, room.price, ',');
            getline(file, room.catagory, ',');
            getline(file, room.isBooked, ',');
            getline(file, room.bookedId, '\n');
            if (room.catagory.compare("luxury") == 0) {
                system("cls");
                cout << room.price;
                break;
            }

        }
        file.close();
    }
}

//edit room info
void editRoomInfo(){
    int option;
    cout << "Edit Room info" << endl;
    lineBreak(2);
    // todo
    do
    {
        cout << "1. Room Price: " << endl;
        cout << "2. back" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            editRoomsPrice();
            break;
        case 2:
            system("cls");
            adminDashboard();
            break;
        default:
            system("cls");
            editRoomInfo();
            break;
        }
    } while (true);

}
void editRoomsPrice() {
    int option;
    cout << "Room Price info" << endl;
    lineBreak(2);
    // todo
    do
    {
        cout << "1. Single rooms Price: " << endl;
        cout << "2. Double Rooms Price: " << endl;
        cout << "3. Luxury Rooms Price: " << endl;
        cout << "4. back" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            editSingleRoomsPrice();
            break;
        case 2:
            system("cls");
            editDoubleRoomsPrice();
            break;
        case 3:
            system("cls");
            editLuxuryRoomsPrice();
            break;
        case 4:
            system("cls");
            editRoomInfo();
            break;
        default:
            system("cls");
            roomsPrice();
            break;
        }
    } while (true);

}
void editSingleRoomsPrice(){
    ifstream filein;
    ofstream fileout;
    string newLine;
    string newPrice;
    fileout.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDBTemp.csv", ios::out);
    filein.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::in);
    cout << "Editing Single Room Price" << endl;
    lineBreak(2);
    cout << "New Price: " << endl;
    cin >> newPrice;
    if (filein.is_open()) {
        while (filein.good())
        {
            string label;
            string numberfBed;
            string price;
            string catagory;
            string isBooked;
            string bookedId;
            getline(filein, newLine);
            stringstream row(newLine);
            if (!newLine.empty()) {
                getline(row, label, ',');
                getline(row, numberfBed, ',');
                getline(row, price, ',');
                getline(row, catagory, ',');
                getline(row, isBooked, ',');
                getline(row, bookedId, '\n');
                if (catagory.compare("single") == 0) {
                    
                    price = newPrice;
                }
                fileout << label;
                fileout << ",";
                fileout << numberfBed;
                fileout << ",";
                fileout << price;
                fileout << ",";
                fileout << catagory;
                fileout << ",";
                fileout << isBooked;
                fileout << ",";
                fileout << bookedId;
                fileout << endl;
            }


        }
        filein.close();
        fileout.close();
    }
    filein.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDBTemp.csv", ios::in);
    fileout.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::out);
    if (filein.is_open()) {
        while (filein.good())
        {
            string label;
            string numberfBed;
            string price;
            string catagory;
            string isBooked;
            string bookedId;
            getline(filein, newLine);
            stringstream row(newLine);
            if (!newLine.empty()) {
                getline(row, label, ',');
                getline(row, numberfBed, ',');
                getline(row, price, ',');
                getline(row, catagory, ',');
                getline(row, isBooked, ',');
                getline(row, bookedId, '\n');
                fileout << label;
                fileout << ",";
                fileout << numberfBed;
                fileout << ",";
                fileout << price;
                fileout << ",";
                fileout << catagory;
                fileout << ",";
                fileout << isBooked;
                fileout << ",";
                fileout << bookedId;
                fileout << endl;
            }


        }
        filein.close();
        fileout.close();
    }
    
    
}
void editDoubleRoomsPrice(){
    ifstream filein;
    ofstream fileout;
    string newLine;
    string newPrice;
    fileout.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDBTemp.csv", ios::out);
    filein.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::in);
    cout << "Editing Single Room Price" << endl;
    lineBreak(2);
    cout << "New Price: " << endl;
    cin >> newPrice;
    if (filein.is_open()) {
        while (filein.good())
        {
            string label;
            string numberfBed;
            string price;
            string catagory;
            string isBooked;
            string bookedId;
            getline(filein, newLine);
            stringstream row(newLine);
            if (!newLine.empty()) {
                getline(row, label, ',');
                getline(row, numberfBed, ',');
                getline(row, price, ',');
                getline(row, catagory, ',');
                getline(row, isBooked, ',');
                getline(row, bookedId, '\n');
                if (catagory.compare("double") == 0) {

                    price = newPrice;
                }
                fileout << label;
                fileout << ",";
                fileout << numberfBed;
                fileout << ",";
                fileout << price;
                fileout << ",";
                fileout << catagory;
                fileout << ",";
                fileout << isBooked;
                fileout << ",";
                fileout << bookedId;
                fileout << endl;
            }


        }
        filein.close();
        fileout.close();
    }
    filein.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDBTemp.csv", ios::in);
    fileout.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::out);
    if (filein.is_open()) {
        while (filein.good())
        {
            string label;
            string numberfBed;
            string price;
            string catagory;
            string isBooked;
            string bookedId;
            getline(filein, newLine);
            stringstream row(newLine);
            if (!newLine.empty()) {
                getline(row, label, ',');
                getline(row, numberfBed, ',');
                getline(row, price, ',');
                getline(row, catagory, ',');
                getline(row, isBooked, ',');
                getline(row, bookedId, '\n');
                fileout << label;
                fileout << ",";
                fileout << numberfBed;
                fileout << ",";
                fileout << price;
                fileout << ",";
                fileout << catagory;
                fileout << ",";
                fileout << isBooked;
                fileout << ",";
                fileout << bookedId;
                fileout << endl;
            }


        }
        filein.close();
        fileout.close();
    }

}
void editLuxuryRoomsPrice(){
    ifstream filein;
    ofstream fileout;
    string newLine;
    string newPrice;
    fileout.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDBTemp.csv", ios::out);
    filein.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::in);
    cout << "Editing Single Room Price" << endl;
    lineBreak(2);
    cout << "New Price: " << endl;
    cin >> newPrice;
    if (filein.is_open()) {
        while (filein.good())
        {
            string label;
            string numberfBed;
            string price;
            string catagory;
            string isBooked;
            string bookedId;
            getline(filein, newLine);
            stringstream row(newLine);
            if (!newLine.empty()) {
                getline(row, label, ',');
                getline(row, numberfBed, ',');
                getline(row, price, ',');
                getline(row, catagory, ',');
                getline(row, isBooked, ',');
                getline(row, bookedId, '\n');
                if (catagory.compare("luxury") == 0) {

                    price = newPrice;
                }
                fileout << label;
                fileout << ",";
                fileout << numberfBed;
                fileout << ",";
                fileout << price;
                fileout << ",";
                fileout << catagory;
                fileout << ",";
                fileout << isBooked;
                fileout << ",";
                fileout << bookedId;
                fileout << endl;
            }


        }
        filein.close();
        fileout.close();
    }
    filein.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDBTemp.csv", ios::in);
    fileout.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::out);
    if (filein.is_open()) {
        while (filein.good())
        {
            string label;
            string numberfBed;
            string price;
            string catagory;
            string isBooked;
            string bookedId;
            getline(filein, newLine);
            stringstream row(newLine);
            if (!newLine.empty()) {
                getline(row, label, ',');
                getline(row, numberfBed, ',');
                getline(row, price, ',');
                getline(row, catagory, ',');
                getline(row, isBooked, ',');
                getline(row, bookedId, '\n');
                fileout << label;
                fileout << ",";
                fileout << numberfBed;
                fileout << ",";
                fileout << price;
                fileout << ",";
                fileout << catagory;
                fileout << ",";
                fileout << isBooked;
                fileout << ",";
                fileout << bookedId;
                fileout << endl;
            }


        }
        filein.close();
        fileout.close();
    }

}
/*staff*/
void staffDashboard() {
    int option;
    cout << "Staff Dashboard" << endl;
    lineBreak(2);
    // todo
    do
    {
        cout << "1. Booking:" << endl;
        cout << "2. Room availability:" << endl;
        cout << "3. log out" << endl;
        cout << "4. exit" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            booking();
            break;
        case 2:
            system("cls");
            checkAvailbility();
            break;
        case 3:
            system("cls");
            loginScreen();
            break;
        case 4:
            exit(0);
            // todo
            break;
        default:
            system("cls");
            staffDashboard();
            break;
        }
        if (option == 1 || option == 2) {
            break;
        }
    } while (true);
};


void booking() {
    cout << "Booking" << endl;
    lineBreak(2);
    int type;
    cout << "Room Type: " << endl;
    lineBreak(1);
    cout << "1. single Bed room:" << endl;
    cout << "2. double Bed room:" << endl;
    cout << "3. luxury Bed room:" << endl;
    cin >> type;
    switch (type)
    {
    case 1:
        system("cls");
        singleBedBooking();
        break;
    case 2:
        system("cls");
        doubleBedBooking();
        break;
    case 3:
        system("cls");
        luxuryBedBooking();
        break;
    default:
        system("cls");
        booking();
        break;
    }
    // get user info
    // book it

}


void singleBedBooking(){
    ifstream filein;
    ofstream fileout;
    string newLine;
    bool booked = false;
    fileout.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDBTemp.csv", ios::out);
    filein.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::in);
    cout << "Single Bed Room" << endl;

    lineBreak(2);
    if (typeRoomAvailbility("single")) {
        getUserInfo();
        if (filein.is_open()) {
            while (filein.good())
            {
                string label;
                string numberfBed;
                string price;
                string catagory;
                string isBooked;
                string bookedId;
                getline(filein, newLine);
                stringstream row(newLine);
                if (!newLine.empty()) {
                    getline(row, label, ',');
                    getline(row, numberfBed, ',');
                    getline(row, price, ',');
                    getline(row, catagory, ',');
                    getline(row, isBooked, ',');
                    getline(row, bookedId, '\n');
                    if (catagory.compare("single") == 0 && isBooked.compare("false") == 0) {
                        if(!booked){
                            bookedId = user.ssn;
                            int checkout = stoi(user.days) * stoi(price);
                            user.checkout = to_string(checkout);
                            user.bookedRoom = label;
                            isBooked = "true";
                            booked = true;
                        }
                    }
                    fileout << label;
                    fileout << ",";
                    fileout << numberfBed;
                    fileout << ",";
                    fileout << price;
                    fileout << ",";
                    fileout << catagory;
                    fileout << ",";
                    fileout << isBooked;
                    fileout << ",";
                    fileout << bookedId;
                    fileout << endl;
                }
                
            
            }
            filein.close();
            fileout.close();
        }
        filein.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDBTemp.csv", ios::in);
        fileout.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::out);
        if (filein.is_open()) {
            while (filein.good())
            {
                string label;
                string numberfBed;
                string price;
                string catagory;
                string isBooked;
                string bookedId;
                getline(filein, newLine);
                stringstream row(newLine);
                if (!newLine.empty()) {
                    getline(row, label, ',');
                    getline(row, numberfBed, ',');
                    getline(row, price, ',');
                    getline(row, catagory, ',');
                    getline(row, isBooked, ',');
                    getline(row, bookedId, '\n');
                    fileout << label;
                    fileout << ",";
                    fileout << numberfBed;
                    fileout << ",";
                    fileout << price;
                    fileout << ",";
                    fileout << catagory;
                    fileout << ",";
                    fileout << isBooked;
                    fileout << ",";
                    fileout << bookedId;
                    fileout << endl;
                }


            }
            filein.close();
            fileout.close();
        }
        
    }else{
        cout << "No availbile room";
        system("cls");
        booking();
    }
    writeUserInfo();
    
   

}
void doubleBedBooking(){
    ifstream filein;
    ofstream fileout;
    string newLine;
    bool booked = false;
    fileout.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDBTemp.csv", ios::out);
    filein.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::in);
    cout << "Single Bed Room" << endl;

    lineBreak(2);
    if (typeRoomAvailbility("double")) {
        getUserInfo();
        if (filein.is_open()) {
            while (filein.good())
            {
                string label;
                string numberfBed;
                string price;
                string catagory;
                string isBooked;
                string bookedId;
                getline(filein, newLine);
                stringstream row(newLine);
                if (!newLine.empty()) {
                    getline(row, label, ',');
                    getline(row, numberfBed, ',');
                    getline(row, price, ',');
                    getline(row, catagory, ',');
                    getline(row, isBooked, ',');
                    getline(row, bookedId, '\n');
                    if (catagory.compare("double") == 0 && isBooked.compare("false") == 0) {
                        if (!booked) {
                            bookedId = user.ssn;
                            int checkout = stoi(user.days) * stoi(price);
                            user.checkout = to_string(checkout);
                            user.bookedRoom = label;
                            isBooked = "true";
                            booked = true;
                        }
                    }
                    fileout << label;
                    fileout << ",";
                    fileout << numberfBed;
                    fileout << ",";
                    fileout << price;
                    fileout << ",";
                    fileout << catagory;
                    fileout << ",";
                    fileout << isBooked;
                    fileout << ",";
                    fileout << bookedId;
                    fileout << endl;
                }


            }
            filein.close();
            fileout.close();
        }
        filein.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDBTemp.csv", ios::in);
        fileout.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::out);
        if (filein.is_open()) {
            while (filein.good())
            {
                string label;
                string numberfBed;
                string price;
                string catagory;
                string isBooked;
                string bookedId;
                getline(filein, newLine);
                stringstream row(newLine);
                if (!newLine.empty()) {
                    getline(row, label, ',');
                    getline(row, numberfBed, ',');
                    getline(row, price, ',');
                    getline(row, catagory, ',');
                    getline(row, isBooked, ',');
                    getline(row, bookedId, '\n');
                    fileout << label;
                    fileout << ",";
                    fileout << numberfBed;
                    fileout << ",";
                    fileout << price;
                    fileout << ",";
                    fileout << catagory;
                    fileout << ",";
                    fileout << isBooked;
                    fileout << ",";
                    fileout << bookedId;
                    fileout << endl;
                }


            }
            filein.close();
            fileout.close();
        }

    }
    else {
        cout << "No availbile room";
        system("cls");
        booking();
    }
    writeUserInfo();
}
void luxuryBedBooking(){
    ifstream filein;
    ofstream fileout;
    string newLine;
    bool booked = false;
    fileout.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDBTemp.csv", ios::out);
    filein.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::in);
    cout << "Single Bed Room" << endl;

    lineBreak(2);
    if (typeRoomAvailbility("luxury")) {
        getUserInfo();
        if (filein.is_open()) {
            while (filein.good())
            {
                string label;
                string numberfBed;
                string price;
                string catagory;
                string isBooked;
                string bookedId;
                getline(filein, newLine);
                stringstream row(newLine);
                if (!newLine.empty()) {
                    getline(row, label, ',');
                    getline(row, numberfBed, ',');
                    getline(row, price, ',');
                    getline(row, catagory, ',');
                    getline(row, isBooked, ',');
                    getline(row, bookedId, '\n');
                    if (catagory.compare("luxury") == 0 && isBooked.compare("false") == 0) {
                        if (!booked) {
                            bookedId = user.ssn;
                            int checkout = stoi(user.days) * stoi(price);
                            user.checkout = to_string(checkout);
                            user.bookedRoom = label;
                            isBooked = "true";
                            booked = true;
                        }
                    }
                    fileout << label;
                    fileout << ",";
                    fileout << numberfBed;
                    fileout << ",";
                    fileout << price;
                    fileout << ",";
                    fileout << catagory;
                    fileout << ",";
                    fileout << isBooked;
                    fileout << ",";
                    fileout << bookedId;
                    fileout << endl;
                }


            }
            filein.close();
            fileout.close();
        }
        filein.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDBTemp.csv", ios::in);
        fileout.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::out);
        if (filein.is_open()) {
            while (filein.good())
            {
                string label;
                string numberfBed;
                string price;
                string catagory;
                string isBooked;
                string bookedId;
                getline(filein, newLine);
                stringstream row(newLine);
                if (!newLine.empty()) {
                    getline(row, label, ',');
                    getline(row, numberfBed, ',');
                    getline(row, price, ',');
                    getline(row, catagory, ',');
                    getline(row, isBooked, ',');
                    getline(row, bookedId, '\n');
                    fileout << label;
                    fileout << ",";
                    fileout << numberfBed;
                    fileout << ",";
                    fileout << price;
                    fileout << ",";
                    fileout << catagory;
                    fileout << ",";
                    fileout << isBooked;
                    fileout << ",";
                    fileout << bookedId;
                    fileout << endl;
                }


            }
            filein.close();
            fileout.close();
        }

    }
    else {
        cout << "No availbile room";
        system("cls");
        booking();
    }
    writeUserInfo();

}



void getUserInfo() {
    system("cls");
    cout << "First name: ";
    cin >> user.firstName;
    cout << "Last name: ";
    cin >> user.lastName;
    cout << "Phone Number: ";
    cin >> user.phone;
    cout << "Email: ";
    cin >> user.email;
    cout << "Ssn: ";
    cin >> user.ssn;
    cout << "Days you spending: ";
    cin >> user.days;

}
void writeUserInfo() {
    fstream file;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\userDB.csv", ios::app);
    string firstName;
    string lastName;
    string phone;
    string email;
    string ssn;
    string checkout;
    string bookedRoom;
    string days;
    if (file.is_open()) {
        file << user.firstName;
        file << ",";
        file << user.lastName;
        file << ",";
        file << user.phone;
        file << ",";
        file << user.phone;
        file << ",";
        file << user.email;
        file << ",";
        file << user.ssn;
        file << ",";
        file << user.checkout;
        file << ",";
        file << user.bookedRoom;
        file << ",";
        file << user.days;
        file << endl;
        file.close();
    }
}

bool typeRoomAvailbility(string type) {
    fstream file;
    bool found = false;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::in);
    if (file.is_open()) {
        while (file.good())
        {
            getline(file, room.label, ',');
            getline(file, room.numberfBed, ',');
            getline(file, room.price, ',');
            getline(file, room.catagory, ',');
            getline(file, room.isBooked, ',');
            getline(file, room.bookedId, '\n');
            
            if (type.compare(room.catagory) == 0) {
                if (room.isBooked.compare("false") == 0) {
                    found = true;
                    return found;
                }
                
            }

            
        }
        file.close();
    }

    return found;
}

void checkAvailbility() {
    cout << "Check Availbility";
    lineBreak(2);
    string roomNumber;
    cout << "Room #";
    cin >> roomNumber;
    system("cls");
    if (isAvailable(roomNumber)) {
        cout << "This Room is booked" << endl;
    }
    else {
        cout << "This Room is not booked" << endl;
    }
}



bool isAvailable(string label) {
    fstream file;
    bool found = false;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::in);
    if (file.is_open()) {
        while (file.good())
        {
            getline(file, room.label, ',');
            getline(file, room.numberfBed, ',');
            getline(file, room.price, ',');
            getline(file, room.catagory, ',');
            getline(file, room.isBooked, ',');
            getline(file, room.bookedId, '\n');
            if (label.compare(room.label) == 0) {
                if (room.isBooked.compare("true") == 0) {
                    found = "true";
                    return found;
                }
                else {
                    return found;
                }
            }
        }
        file.close();
    }
    
}

/*
int i = 0;
        while (filein.good())
        {
            ++i;

            string label;
            string numberfBed;
            string price;
            string catagory;
            string isBooked;
            string bookedId;
            getline(filein, label, ',');
            getline(filein, numberfBed, ',');
            getline(filein, price, ',');
            getline(filein, catagory, ',');
            getline(filein, isBooked, ',');
            getline(filein, bookedId, '\n');
            cout << label << endl;

            if (i == count) {
                fileout << label;
                fileout << ",";
                fileout << numberfBed;
                fileout << ",";
                fileout << price;
                fileout << ",";
                fileout << catagory;
                fileout << ",";
                fileout << isBooked;
                fileout << ",";
                fileout << bookedId;
            }
            else {
                
            }

        }
        fileout.close();
        filein.close();
*/






/*
            * filein.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDBTemp.csv", ios::in);
            fileto.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\roomDB.csv", ios::out);
            if (fileto.is_open()) {
                while (fileto.good())
                {
                    getline(filein, eroom.label, ',');
                    getline(filein, eroom.numberfBed, ',');
                    getline(filein, eroom.price, ',');
                    getline(filein, eroom.catagory, ',');
                    getline(filein, eroom.isBooked, ',');
                    getline(filein, eroom.bookedId, '\n');


                    fileto << eroom.label;
                    fileto << ",";
                    fileto << eroom.numberfBed;
                    fileto << ",";
                    fileto << eroom.price;
                    fileto << ",";
                    fileto << eroom.catagory;
                    fileto << ",";
                    fileto << eroom.isBooked;
                    fileto << ",";
                    fileto << eroom.bookedId << endl;
                }
            }
            filein.close();
            fileto.close();*/









/*
createDb();
    // loginScreen();
    //userAuth("ursdic");
    fstream file;
    int line = 0;
    bool found = false;
    file.open("C:\\Users\\K.Lyon\\Desktop\\hotel-reservation-project\\app\\app\\db\\staffDB.csv", ios::in);
    if (file.is_open()) {

        while (file.good())
        {
            getline(file, staff.firstName, ',');
            getline(file, staff.lastName, ',');
            getline(file, staff.username, ',');
            getline(file, staff.email, ',');
            getline(file, staff.phoneNumber, ',');
            getline(file, staff.privilege, ',');
            getline(file, staff.pin, '\n');

            if (line != 0) {
                //found = true;
                cout << staff.username << endl;

            }
            line++;
        }
        file.close();
    }
*/



/*
string strReplace = "HELLO";
    string strNew = "GOODBYE";
    ofstream file;
    file.open("filein.txt");
    file << "ONE" << endl;
    file << "TWO" << endl;
    file << "THREE" << endl;
    file << "HELLO" << endl;
    file << "SEVEN" << endl;
    ifstream filein("filein.txt"); //File to read from
    ofstream fileout("fileout.txt"); //Temporary file
    if (!filein || !fileout)
    {
        cout << "Error opening files!" << endl;
        return 1;
    }

    string strTemp;
    //bool found = false;
    while (filein >> strTemp)
    {
        if (strTemp == strReplace) {
            strTemp = strNew;
            //found = true;
        }
        strTemp += "\n";
        fileout << strTemp;
        //if(found) break;
    }

    filein.close();
    fileout.close();

    int status = remove("filein.txt");
    if (status == 0)
        cout << "\nFile Deleted Successfully!";
    else
        cout << "\nError Occurred!";

*/



/*
 ofstream file;
    file.open("filein.csv", ios::out);
    if (file.is_open()) {
        while (file.good())
        {
            string firstName;
            string lastName;
            string username;
            string email;
            string phoneNumber;
            string privilege;
            string pin;
            getline(file, firstName, ',');
            getline(file, lastName, ',');
            getline(file, username, ',');
            getline(file, email, ',');
            getline(file, phoneNumber, ',');
        }
    }



    /*
    string strReplace = "HELLO";
    string strNew = "GOODBYE";

    file << "ONE" << endl;
    file << "TWO" << endl;
    file << "THREE" << endl;
    file << "HELLO" << endl;
    file << "SEVEN" << endl;
    ifstream filein("filein.txt"); //File to read from
    ofstream fileout("fileout.txt"); //Temporary file
    if (!filein || !fileout)
    {
        cout << "Error opening files!" << endl;
        return 1;
    }

    string strTemp;
    //bool found = false;
    while (filein >> strTemp)
    {
        if (strTemp == strReplace) {
            strTemp = strNew;
            //found = true;
        }
        strTemp += "\n";
        fileout << strTemp;
        //if(found) break;
    }

    */
