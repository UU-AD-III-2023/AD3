#include "Cost.h"

Cost::Cost() {
    this->value = 0;
}

string Cost::toString() {
    /* ... */
    return "";
}

bool Cost::isEqualTo(Cost c) {
    /* ... */
    return c.value>0;
}

bool Cost::isBetterThan(Cost c) {
    /* ... */
    return c.value==0;
}