#include <stdlib.h>
#include "variables.h"
#include "arrays.h"
#include "utils.h"
int main(void) { 

map_name(0, "s");
map_name(1, "ejemplo");
map_name(2, "lista");
map_name(3, "aux");
map_name(4, "num");
print_var(anon_str("hola"), 1);
assign(0, anon_str("jeje"));
print_var(get_var(0), 1);
toupper_str(0);
print_var(get_var(0), 1);
assign(1, anon_int(2));
print_var(anon_float(4.50000), 1);
assign(2, anon_arr(3, anon_int(1), anon_int(2), anon_int(3)));
assign(3, array_index(get_var(2), anon_int(1)));
reset_iterator(get_var(2));

while( hasNext(get_var(2))){
assign(4, next(get_var(2)));
print_var(get_var(4), 1);
}

exit(0);
}
