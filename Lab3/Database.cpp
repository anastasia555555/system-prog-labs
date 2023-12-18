#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include "Database.h"
#include "Position.h"

namespace Records {
    class Database {
    public:
        void Database::addPosition(const Position& position) {
            positions.push_back(position);
        }

        Position Database::getPosition(int positionId) const {
            auto it = std::find_if(positions.begin(), positions.end(),
                [positionId](const Position& pos) { return pos.getPositionId() == positionId; });

            if (it != positions.end()) {
                return *it;
            }
            else {
                return Position();
            }
        }

        void Database::removePosition(int positionId) {
            positions.remove_if([positionId](const Position& pos) { return pos.getPositionId() == positionId; });
        }

        void Database::displayAllPositions() const {
            for (const auto& position : positions) {
                position.displayPositionDetails();
                std::cout << "---------------------\n";
            }
        }
        
    protected:
        std::list<Position> positions;
    };
}
