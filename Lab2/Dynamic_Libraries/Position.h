#include <iostream>
#include <string>

namespace Records {
    
	const double kDefaultSalary = 3000.0;
    
	class Position {
        public:
            Position();
            Position(int id, const std::string& name, double salary, const std::string& responsibilities, const std::string& requirements);
            
            void giveBonus(int bonus);              //gives a bonus
            void givePenalty(int penalty);          //sets a penalty
            void displayPositionDetails() const;    //displays position details

            // Accessors and setters
            int getPositionId() const;
            void setPositionId(int id);

            std::string getPositionName() const;
            void setPositionName(const std::string& name);

            double getSalary() const;
            void setSalary(double salary);

            double getBonus() const;
            void setBonus(int bonus);

            double getPenalty() const;
            void setPenalty(int penalty);

            std::string getResponsibility() const;
            void setResponsibility(const std::string& responsibilities);

            std::string getRequirements() const;
            void setRequirements(const std::string& requirements);
			
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
