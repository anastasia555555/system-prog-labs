#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"

using namespace std;
namespace Records {
    Database::Database() {
        mNextSlot = 0;
        mNextPositionNumber = kFirstPositionNumber;
    }
    Database::~Database() { }
    
    Position& Database::addPosition(string inPositionTitle, int inOklad, string inObovyazky, string inVymogy) {
        if (mNextSlot >= kMaxPositions) {
            cerr << "Only 30 positions are allowed." << endl;
            throw exception();
        }
    
		Position& addedPosition = mPositions[mNextSlot++];
		addedPosition.setPositionTitle(inPositionTitle);
		addedPosition.setOklad(inOklad);
		addedPosition.setPositionNumber(mNextPositionNumber++);
		
		return addedPosition;
    }
    
    Position& Database::getPosition(string inPositionTitle) {
        for (int i = 0; i < mNextSlot; i++) {
            if (mPositions[i].getPositionTitle() == inPositionTitle) {
                return mPositions[i];
            }
         }
         cerr << "No match with title: " << inPositionTitle << endl;
         throw exception();
    }

    void Database::displayAll() {
        for (int i = 0; i < mNextSlot; i++) {
            mPositions[i].display();
        }
    }
}
