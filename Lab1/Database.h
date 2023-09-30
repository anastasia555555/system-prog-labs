// Database.h

#include <iostream>
#include "Position.h"
namespace Records {
    const int kMaxPositions = 30;
    const int kFirstPositionNumber = 100;
    class Database {
        public:
             Database();
             ~Database();
             Position& addPosition(std::string inPositionTitle, int inOklad, std::string inObovyazky, std::string inVymogy);
             Position& getPosition(int inPositionNumber);
             Position& getPosition(std::string inPositionTitle);
             void displayAll();
             void displayCurrent();
             void displayFormer();
        protected:
             Position mPositions[kMaxPositions];
             int mNextSlot;
             int mNextPositionNumber;
    };
}
