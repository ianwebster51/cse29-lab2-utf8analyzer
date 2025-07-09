#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// helper
int8_t get_byte(char c) {
	if ( (c & 0xc0) == 0x80 ) { return 0; }
	else if ( (c & 0x80) == 0x00 ) { return 1; }
	else if ( (c & 0xe0) == 0xc0 ) { return 2; }
	else if ( (c & 0xf0) == 0xe0 ) { return 3; }
	else if ( (c & 0xf8) == 0xf0 ) { return 4; }
	else { return -1; }
}

// is_valid
// returns 1 if valid, 0 otherwise
uint8_t is_valid_ascii(const char str[]) {
	// get length in bytes
	int8_t bytes = 0;
	for (uint8_t i = 0; str[i] != '\0'; ++i) {
		// check bytes
		bytes = get_byte(str[i]);
		if (bytes != 1) { return 0; }
	}
	return 1;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }

    // implement the UTF-8 analyzer here
	
	// test
	//printf("Should be 1: %hhu", is_valid_ascii("Test String") );
}
