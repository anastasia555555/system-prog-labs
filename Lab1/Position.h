#include <iostream>
namespace Records {
    const int kDefaulPochatkovyiOklad = 3000;
    class Position {
        public:
            Position();
            void giveBonus(int inBonusSize = 1000); //gives a bonus
            void givePenalty(int inPenaltySize = 500); //sets a penalty
            void display(); //outputs info to the console

            // Accessors and setters
            void setPositionTitle(std::string inPositionTitle);
            std::string getPositionTitle();
            void setOklad(int inOklad);
            int getOklad();
            void setObovyazky(std::string inObovyazky);
            std::string getObovyazky();
            void setVymogy(std::string Vymogy);
            std::string getVymogy();
        private:
            std::string mPositionTitle;
            int mOklad;
            std::string mObovyazky;
            std::string mVymogy;
    };
}
