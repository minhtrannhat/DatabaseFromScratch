#include "./REPL/input1.h"
#include <stdbool.h>

int main(int argc, char *argv[]) { 

    InputBuffer *input_buffer = new_input_buffer();

    while(true){
      parse_input(input_buffer);
    }

    return 0; 
}
