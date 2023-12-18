#include <iostream>
#include <limits> 
#include "Database.h"

class Menu {
public:
    Menu() : database() {}

    void displayMenu() const {
        std::cout << "====== Menu ======\n";
        std::cout << "1. Add Position\n";
        std::cout << "2. Remove Position\n";
        std::cout << "3. View All Positions\n";
        std::cout << "4. Exit\n";
        std::cout << "==================\n";
    }

    void processChoice() {
        int choice;
        while (true) {
            displayMenu();
            choice = getUserInput("Enter your choice: ");

            switch (choice) {
                case 1:
                    addPosition();
                    break;
                case 2:
                    removePosition();
                    break;
                case 3:
                    viewAllPositions();
                    break;
                case 4:
                    std::cout << "Exiting the program.\n";
                    return;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        }
    }

private:
    Records::Database database;

    int getUserInput(const std::string& prompt) const {
        int choice;
        std::cout << prompt;
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard invalid input
        return choice;
    }

    void addPosition() {
        int id = getUserInput("Enter position ID: ");
        std::string name;
        std::cout << "Enter position name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        double salary = getUserInput("Enter salary: ");
        std::string responsibilities;
        std::cout << "Enter responsibilities: ";
        std::getline(std::cin, responsibilities);
        std::string requirements;
        std::cout << "Enter requirements: ";
        std::getline(std::cin, requirements);

        Records::Position newPosition(id, name, salary, responsibilities, requirements);
        database.addPosition(newPosition);
        std::cout << "Position added successfully.\n";
    }

    void removePosition() {
        int id = getUserInput("Enter the position ID to remove: ");
        database.removePosition(id);
        std::cout << "Position removed successfully.\n";
    }

    void viewAllPositions() const {
        database.displayAllPositions();
    }
};