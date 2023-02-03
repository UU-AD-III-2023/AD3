#include "Cost.h"

Cost::Cost() {
    this->value = -1;
}

string Cost::toString() {
    /* ... */
    return "";
}

bool Cost::isEqualTo(Cost c) {
    /* ... */
    return this->value==c.value;
}

bool Cost::isBetterThan(Cost c) {
    /* ... */
    return this->value<c.value;
}