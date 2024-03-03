
# Llibs framework example ---> Bare Minimum

# Compiler --------------------->
CC = gcc

# LLIBS BUILD ------------------------------------------>**

# Llibs path --------------------->
LLIBS_PATH = paste/your/path # DON'T FORGET TO PASTE PATH FOR LLIBS

# OS --------------------->
OS := $(shell node $(LLIBS_PATH)/scripts/os.js)

# Compiler flags for Llibs --------------------->
LLIBS_CFLAGS = -MMD -std=c11 -Iinclude -I$(LLIBS_PATH)/cross/include

# Use Lingua framework ------------------------------------------>
# LLIBS_CFLAGS += -D USE_LINGUA

# Llibs native path (for .c files) ------------------------------------------>
LLIBS_NATIVE_PATH := $(shell node $(LLIBS_PATH)/scripts/native.js $(OS))

# Different files --------------------->
LLIBS_SRC_FILES := $(shell node $(LLIBS_PATH)/scripts/find.js $(LLIBS_PATH)/$(LLIBS_NATIVE_PATH) .c)\
	$(shell node $(LLIBS_PATH)/scripts/find.js $(LLIBS_PATH)/cross/ .c)
LLIBS_OBJ_FILES := $(LLIBS_SRC_FILES:.c=.o)
LLIBS_DEP_FILES := $(LLIBS_OBJ_FILES:.o=.d)

# PROJECT BUILD ------------------------------------------>**

# Compiler flags for project --------------------->
PROJECT_CFLAGS = -std=c11 -Iinclude

# Project out --------------------->
PROJECT_OUT := bin/out$(shell node $(LLIBS_PATH)/scripts/ext.js)

# Include Llibs framework --------------------->
PROJECT_CFLAGS += -I$(LLIBS_PATH)/cross/include

# Different files --------------------->
PROJECT_SRC_FILES := $(shell node $(LLIBS_PATH)/scripts/find.js src .c)
PROJECT_OBJ_FILES := $(PROJECT_SRC_FILES:.c=.o)
PROJECT_DEP_FILES := $(PROJECT_OBJ_FILES:.o=.d)

# Default Target --------------------->
all: $(PROJECT_OUT)

# Linking Llibs and Lena together --------------------->
$(PROJECT_OUT): $(PROJECT_OBJ_FILES) $(LLIBS_OBJ_FILES)
	$(CC) $(PROJECT_CFLAGS) -o $@ $^

# Compiling Lena object files --------------------->
$(PROJECT_SRC_FILES:.c=.o): %.o: %.c
	$(CC) $(PROJECT_CFLAGS) -c $< -o $@

# Compiling Llibs object files --------------------->
$(LLIBS_SRC_FILES:.c=.o): %.o: %.c
	$(CC) $(LLIBS_CFLAGS) -c $< -o $@

# Include generated dependencies --------------------->
-include $(PROJECT_DEP_FILES) $(LLIBS_DEP_FILES)

# Clean --------------------->
clean:
	rm -f $(PROJECT_OUT) $(PROJECT_OBJ_FILES) $(PROJECT_DEP_FILES) $(LLIBS_DEP_FILES)