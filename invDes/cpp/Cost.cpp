#include "Cost.h"

Cost::Cost() {
    this->value = -1;
    this->improvement=0;
}

string Cost::toString() {
    /* ... */
    return "";
}

bool Cost::isEqualTo(Cost c) {
    /* ... */
    return improvement==c.improvement && value==c.value;
}

bool Cost::isBetterThan(Cost c) {
    /* ... */
    return ((!(value<c.value) && (improvement>c.improvement)));
}