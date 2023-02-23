#include <iostream>
#include <string>
#include <fstream>

void listUsers(std::fstream& file);
void addUser(std::fstream& file, const std::string& userName);
void removeUser(std::fstream& file, const std::string& userName);

void displayMenu();
int getSelection(const std::string& prompt, const int& high=10, const int& low=0);

enum MenuOption
{
    QUIT, LIST, ADD, REMOVE,
};

int main()
{
    bool running = true;

    std::string filename = "data.txt";
    std::fstream file (filename);

    if (!file)
    {
        std::cout << "Failed opening file '" << filename << "' . Quitting...";

        running = false;
    }

    while (running)
    {
        displayMenu();

        switch(getSelection("Make a selection", 3))
        {
            case LIST:
                listUsers(file);
                break;
            case ADD:
                addUser(file, "DUMMY");
                break;
            case REMOVE:
                removeUser(file, "DUMMY");
                break;
            case QUIT:
                running = false;
                break;
            default:
                std::cout << "Not a valid menu option. Try again." << '\n';
                break;
        }
    }

    file.close();

    return 0;
}

void displayMenu()
{
    std::cout << '\n'
              << "----- MENU -----" << '\n'
              << LIST   << ": List all users" << '\n'
              << ADD    << ": Add a user" << '\n'
              << REMOVE << ": Remove a user" << '\n'
              << QUIT   << ": Quit" << '\n' << '\n';
}

// listUsers()
void listUsers(std::fstream& file)
{
    int userNumber = 0;
    std::string user = "";
    while (!file.eof())
    {
        std::getline(file, user);

        if (user != "")
        {
            std::cout << ++userNumber << ": " << user << '\n';
        }
    }
}

// addUser()
void addUser(std::fstream& file, const std::string& userName)
{
    std::cout << "STUB: adding user '" << userName << "' to the list of users." << '\n';
}

// removeUser()
void removeUser(std::fstream& file, const std::string& userName)
{
    std::cout << "STUB: removing user '" << userName << "' to the list of users." << '\n';
    
}

// No side effects!
int getSelection(const std::string& prompt, const int& high, const int& low)
{
    int input {0};
    bool validSelection {false};

    do
    {
        std::cout << prompt << ": ";
        if (std::cin >> input)
        {
            if (input >= low && input <= high)
            {
                validSelection = true;
            }
            else
            {
                std::cout << "\nNumber not with range: [" << low << ", " << high << "]" << '\n';
            }
        }
        else
        {
            std::cin.clear();
            // std::cin.ignore(100, '\n');
            std::cout << "\nInput is not an integer." << '\n';
        }
    }
    while (!validSelection);

    std::cout << '\n';

    return input;
}
