#include <iostream>
#include <string>
#include <list>
#include "Position.h"

namespace Records {
    class Database {
    public:
        void addPosition(const Position& position); // Add a position to the database
        Position getPosition(int positionId) const; // Get a position by ID
        void removePosition(int positionId);        // Remove a position by ID
        void displayAllPositions() const;           // Display all positions in the database

    protected:
        std::list<Position> positions;
    };
}
