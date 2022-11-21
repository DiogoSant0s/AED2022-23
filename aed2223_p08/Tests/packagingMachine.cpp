#include "packagingMachine.h"
#include <sstream>

PackagingMachine::PackagingMachine(int boxCap) : boxCapacity(boxCap) {}

unsigned PackagingMachine::numberOfBoxes() {return boxes.size();}

unsigned PackagingMachine::addBox(Box& b1) {
	boxes.push(b1);
	return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {return this -> objects;}
HeapBox PackagingMachine::getBoxes() const {return this -> boxes;}

// ---------------------------------------------

// TODO
unsigned PackagingMachine::loadObjects(vector<Object>& objs) {

	return 0;
}

// TODO
Box PackagingMachine::searchBox(Object& obj) {

    return Box(0);
}


// TODO
unsigned PackagingMachine::packObjects() {

	return 0;
}

// TODO
stack<Object> PackagingMachine::boxWithMoreObjects() const {
    stack<Object> res;

	return res;
}



