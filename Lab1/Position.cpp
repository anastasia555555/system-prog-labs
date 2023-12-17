#include <iostream>
#include <string>
#include "Position.h"

namespace Records {
    class Position {
    public:
        Position::Position()
            : mPositionId(0), mPositionName(""), mSalary(kDefaultSalary),
            mBonus(0), mPenalty(0), mResponsibility(""), mRequirements("") {}

        Position::Position(int id, const std::string& name, double salary, const std::string& responsibilities, const std::string& requirements)
            : mPositionId(id), mPositionName(name), mSalary(salary),
            mResponsibility(responsibilities), mRequirements(requirements), mBonus(0), mPenalty(0) {}


        // Getters and setters
        int Position::getPositionId() const {
            return mPositionId;
        }

        void Position::setPositionId(int id) {
            mPositionId = id;
        }

        std::string Position::getPositionName() const {
            return mPositionName;
        }

        void Position::setPositionName(const std::string& name) {
            mPositionName = name;
        }

        double Position::getSalary() const {
            return mSalary;
        }

        void Position::setSalary(double salary) {
            mSalary = salary;
        }

        double Position::getBonus() const {
            return mBonus;
        }

        void Position::setBonus(int bonus) {
            mBonus = bonus;
        }

        double Position::getPenalty() const {
            return mPenalty;
        }

        void Position::setPenalty(int penalty) {
            mPenalty = penalty;
        }

        std::string Position::getResponsibility() const {
            return mResponsibility;
        }

        void Position::setResponsibility(const std::string& responsibilities) {
            mResponsibility = responsibilities;
        }

        std::string Position::getRequirements() const {
            return mRequirements;
        }

        void Position::setRequirements(const std::string& requirements) {
            mRequirements = requirements;
        }

        // Methods
        void Position::displayPositionDetails() const {
            std::cout << "----------------------------" << std::endl;
            std::cout << "Position ID: " << mPositionId << std::endl;
            std::cout << "Position Name: " << mPositionName << std::endl;
            std::cout << "Salary: $" << mSalary << std::endl;
            std::cout << "Bonus: $" << mBonus << std::endl;
            std::cout << "Penalty: $" << mPenalty << std::endl;
            std::cout << "Responsibility: " << mResponsibility << std::endl;
            std::cout << "Requirements: " << mRequirements << std::endl;
        }

        void Position::giveBonus(int bonus) {
            mBonus += bonus;
        }

        void Position::givePenalty(int penalty) {
            mPenalty += penalty;
        }

        double Position::countTotalSalary() const {
            return mSalary + mBonus - mPenalty;
        }

    private:
            int mPositionId;
            std::string mPositionName;
            double mSalary;
            double mBonus;
            double mPenalty;
            std::string mResponsibility;
            std::string mRequirements;
    };
}

