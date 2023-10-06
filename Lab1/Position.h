#include <iostream>
#include <string>

using namespace std;
namespace Records {
    
	const int kDefaulPochatkovyiOklad = 3000;
    
	class Position {
        public:
            Position();
            void giveBonus(int inBonusSize = 1000); //gives a bonus
            void givePenalty(int inPenaltySize = 500); //sets a penalty
            void display(); //outputs info to the console

            // Accessors and setters
            void setPositionTitle(string inPositionTitle);
            string getPositionTitle();
    
			void setPositionNumber(int inPositionNumber);
			int getPositionNumber();
	
			void setOklad(int inOklad);
            int getOklad();
            
			void setObovyazky(string inObovyazky);
            string getObovyazky();
            
			void setVymogy(string inVymogy);
            string getVymogy();
			
        private:
            string mPositionTitle;
			int mPositionNumber;
            int mOklad;
            string mObovyazky;
            string mVymogy;
    };
}
