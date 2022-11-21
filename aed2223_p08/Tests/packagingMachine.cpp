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
    int c = 0;
    auto it = objs.begin();
    while (it != objs.end()) {
        if (it -> getWeight() <= boxCapacity) {
            objects.push(*it);
            objs.erase(it);
            c++;
        } else {
            it++;
        }
    }
	return c;
}

// TODO
Box PackagingMachine::searchBox(Object& obj) {
    vector<Box> box;
    while (!boxes.empty()) {
        if (boxes.top().getFree() >= obj.getWeight()) {
            Box bx = boxes.top();
            boxes.pop();
            for (const auto& i : box) {boxes.push(i);}
            return bx;
        } else {
            box.push_back(boxes.top());
            boxes.pop();
        }
    }
    for (const auto& i : box) {
        boxes.push(i);
    }
    return Box(boxCapacity);
}


// TODO
unsigned PackagingMachine::packObjects() {
    Box temp;
    while (!objects.empty()) {
        Object tmp = objects.top();
        objects.pop();
        temp = searchBox(tmp);
        temp.addObject(tmp);
        boxes.push(temp);
    }
	return boxes.size();
}

// TODO
stack<Object> PackagingMachine::boxWithMoreObjects() const {
    stack<Object> res;
    HeapBox box = boxes;
    unsigned int max = INT32_MIN;
    if (box.empty()) {return res;}
    while (!box.empty()) {
        if (box.top().getSize() > max) {
            res = box.top().getObjects();
            max = box.top().getSize();
        }
        box.pop();
    }
	return res;
}



