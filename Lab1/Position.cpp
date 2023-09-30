#include <iostream>
#include <string>
#include "Position.h"
using namespace std;
namespace Records {
    Position::Position() {
        mPositionTitle = "";
        mOklad = kDefaultStartingOklad;
        mObovyazky = "";
        mVymogy = "";
    }

    void Position::giveBonus(int inBonusSize) {
        setOklad(getOklad() + inBonusSize);
    }

    void Position::givePenalty(int inPenaltySize) {
        setOklad(getOklaf() - inPenaltySize);
    }

    void Position::display() {
        cout << "Position: " << getPositionTitle() << endl;
        cout << "-------------------------" << endl;
        cout << "Oklad:" << getOklad() << " grn." << endl;
        cout << "Obovyazky:" << getObovyazky() << endl;
        cout << "Vymogy: " << getVymogy() << endl;
        cout << endl;
    }

    // Accessors and setters
    void Position::setPositionTitle(string inPositionTitle) {
        mPositionTitle = inPositionTitle;
    }

    string Position::getPositionTitle() {
        return mPositionTitle;
    }

    void Position::setOklad(int inOklad) {
        mOklad = inOklad;
    }

    int Position::getOklad() {
        return mOklad;
    }

    void Position::setObovyazky(string inObovtazky) {
        mObovyazky = inObovyazky;
    }

    string Position::getObovyazky() {
        return mObovyazky;
    }

    void Position::setVymogy(string inVymogy) {
        mVymogy = inVymogy;
    }

    int Position::getVymogy() {
        return mVymogy;
    }
}
