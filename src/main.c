
#include <stdlib.h>
#include <string.h>

#include <llibs/main.h>
#include <llibs/memory.h>

int main(int argc, char* argv[]) {

	lstr* buffer = lalloc((llen)argc, sizeof(lstr));
	if (!buffer)
		return EXIT_FAILURE;

	for (llen i = 0; i < (llen)argc; ++i) {
		buffer[i].length = strlen(argv[i]);
		buffer[i].ptr = argv[i];
	}

	return lmain(argc, buffer);
}
