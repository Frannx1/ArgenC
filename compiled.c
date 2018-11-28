#include <stdlib.h>
#include "variables.h"
#include "arrays.h"
#include "utils.h"
int main(void) { 

mapAName(0, "s");
mapAName(1, "ejemplo");
mapAName(2, "lista");
mapAName(3, "aux");
mapAName(4, "num");
printVariable(anonString("hola"), 1);
assign(0, anonString("jeje"));
printVariable(getVariable(0), 1);
toUpperString(0);
printVariable(getVariable(0), 1);
assign(1, anonInteger(2));
printVariable(anonFloat(4.50000), 1);
assign(2, anonArray(3, anonInteger(1), anonInteger(2), anonInteger(3)));
assign(3, indexOfArray(getVariable(2), anonInteger(1)));
resetIterator(getVariable(2));

while(hasNext(getVariable(2))) {
assign(4, next(getVariable(2)));
printVariable(getVariable(4), 1);
}

exit(0);
}
