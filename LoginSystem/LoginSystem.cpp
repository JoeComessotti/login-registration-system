#include <iostream>
#include <fstream>
#include <string>


// This function takes a file name, and a line number as parameters
// It will return whatever text is on the given string, in the given file
std::string line(std::string fileName, int lineNumber) {
    
    std::ifstream file(fileName);
    
    std::string line;
    
    for (int i = 0; i < lineNumber; i++)
    {
        std::getline(file, line);
    }
    return line;
}

// Function that takes a username (string) is a parameter, and returns true of its a valid user
bool isUserValid(std::string user) {
    
    std::string fileName = user + ".txt";
    
    std::ifstream file(fileName);

    std::string text;
    
    if (std::getline(file, text)) {
        return true;
    }
    else {
        return false;
    }
}

// Function that takes a user name, and a password as input 
// It checks if the inputed password matches the one stored in the users file
bool isCorrectPassword(std::string user, std::string passwordCandidate) {

    std::string fileName = user + ".txt";

    std::string password = line(fileName, 2);

    if (passwordCandidate == password) {
        return true;
    }
    else {
        return false;
    }
}

// Creates a new user file, if the user name hasnt already been taken
bool createUser(std::string username, std::string password) {
    if (isUserValid(username)) {
        return false;
    }
    else {
        std::ofstream newUser(username + ".txt");
        newUser << username + "\n";
        newUser << password;
        return true;
    }
}

void login(std::string error);
void signup(std::string error);

// Start menu
void start(std::string error) {
    // If there is an error, displays it otherwise dislpays the title of the page
    if (error != "") {
        std::cout << error + "\n";
    }
    else {
        std::cout << "Welcome! \n";
    }
    
    // Gives the user their menu options
    std::cout << "1: Login \n2: Register\n";

    // Collects the user input
    std::string welcomeChoice;
    std::cout << "Your choice: ";
    std::getline(std::cin, welcomeChoice);
    
    // Calls a function based on the user input
    if (welcomeChoice == "1") {
        system("cls");
        login("");
    }
    else if (welcomeChoice == "2") {
        system("cls");
        signup("");
    }
    else {
        system("cls");
        start("Invalid choice. Please use either 1 or 2.");
    }
}

// Login menu
void login(std::string error) {
    // If there is an error, displays it otherwise dislpays the title of the page
    if (error != "") {
        std::cout << error + "\n";
    }
    else {
        std::cout << "Login\n";
    }
    
    // Collects input for username
    std::string username;
    std::cout << "Username: ";
    std::getline(std::cin, username);

    // Collects input for password
    std::string password;
    std::cout << "Password: ";
    std::getline(std::cin, password);

    // Checks if the username is valid
    if (!isUserValid(username)) {
        system("cls");
        login("Username is invalid");
    }

    // Checks if the password is correct 
    else if (!isCorrectPassword(username, password)) {
        system("cls");
        login("Password is invalid");
    }
    else {
        std::cout << "Welcome, " + username + "!";
    } 

} 

// Signup menu
void signup(std::string error) {
    // If there is an error, displays it 
    // Otherwise shows the title of the page
    if (error != "") {
        std::cout << error + "\n";
    }
    else {
        std::cout << "Registration\n";
    }
    
    // Collects input for username
    std::string username;
    std::cout << "Username: ";
    std::getline(std::cin, username);

    // Collects input for password 
    std::string password;
    std::cout << "Password: ";
    std::getline(std::cin, password);

    // Collects input for password repeat
    std::string passwordrpt;
    std::cout << "Repeat password: ";
    std::getline(std::cin, passwordrpt);

    // Checks if the user already exists
    if (isUserValid(username)) {
        system("cls");
        signup("Username is already taken. Please try again");
    }
    
    // Checks if the passwords match
    else if (password != passwordrpt) {
        system("cls");
        signup("Passwords do not match.");

    }

    // Creates a user
    else if (createUser(username, password)) {
        system("cls");
        login("Registration success! Login");
    }
    else {
        system("cls");
        signup("Error: could not create user. Please try again.");
    }

}

int main()
{
    start("");
    
    return 0;
}
