#include <iostream>
#include <string>
#include "Position.h"

using namespace std;
namespace Records {
	
    const int kMaxPositions = 30;
	const int kFirstPositionNumber = 1;
    
	class Database {
        public:
             Database();
             ~Database();
             Position& addPosition(string inPositionTitle, int inOklad, string inObovyazky, string inVymogy);
             Position& getPosition(string inPositionTitle);
             void displayAll();
        protected:
             Position mPositions[kMaxPositions];
             int mNextSlot;
             int mNextPositionNumber;
    };
}
