// Database.h

#include <iostream>
#include "Position.h"
namespace Records {
    class Database {
        const int kMaxPositions = 30;
        public:
             Database();
             ~Database();
             Position& addPosition(std::string inPositionTitle, int inOklad, std::string inObovyazky, std::string inVymogy);
             Position& getPosition(std::string inObovyazky);
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
