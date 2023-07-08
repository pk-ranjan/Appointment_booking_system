#include <iostream>
#include "CallCenter.h"
int main() {

    CallCenter* callCenter = new CallCenter();
    callCenter->dialog();
    delete callCenter;

    return 0;
}
