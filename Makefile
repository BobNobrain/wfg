PROJECT_ROOT = .
SRC_DIR = $(PROJECT_ROOT)/src
BIN_DIR = $(PROJECT_ROOT)/bin
INC_DIR = $(PROJECT_ROOT)/include
OBJ_DIR = $(PROJECT_ROOT)/obj
CLASSES_SUBDIRS = exception parser

TARGET = $(BIN_DIR)/wfg

SRC_CPP = main.cpp
OBJ_CPP = $(SRC_CPP:.cpp=.o)

CLASSES_CPP = ArgParser \
	Interpreter State Value \
	Command Expression \
	parser/Parser parser/Token \
	exception/ParserException
CLASSES_OBJECTS = $(addsuffix .o,$(CLASSES_CPP))

# Program version
GIT_REVISION = $(shell git rev-parse HEAD)
PROGRAM_VERSION = wfg v0.0.1 [$(GIT_REVISION)]
PROGRAM_VERSION_MACRO = PROGRAM_VERSION="$(PROGRAM_VERSION)"

# Compiler & linker flags
CFLAGS = -Wall -std=c++11 -iquote $(INC_DIR) -D'$(PROGRAM_VERSION_MACRO)'
LFLAGS =

vpath %.cpp $(SRC_DIR)
vpath %.h $(INC_DIR)

$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(BIN_DIR))

.PHONY: all
all: program

.PHONY: program
program: $(TARGET)

$(TARGET): $(addprefix $(OBJ_DIR)/,$(OBJ_CPP)) $(addprefix $(OBJ_DIR)/,$(CLASSES_OBJECTS))
	@echo Building $(PROGRAM_VERSION)
	g++ $(LFLAGS) -o $(TARGET) $^

define createclassrule
$(OBJ_DIR)/$(addsuffix .o,$(1)): $(SRC_DIR)/$(addsuffix .cpp,$(1)) $(INC_DIR)/$(addsuffix .h,$(1))
	g++ $$(CFLAGS) -c $$< -o $$@
endef

$(foreach classfile,$(CLASSES_CPP),$(eval $(call createclassrule,$(classfile))))

define createcpprule
$(OBJ_DIR)/$(1): $(SRC_DIR)/$(1:.o=.cpp)
	g++ $$(CFLAGS) -c $$< -o $$@
endef

$(foreach objfile,$(OBJ_CPP),$(eval $(call createcpprule,$(objfile))))

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	mkdir $(OBJ_DIR)
	mkdir $(addprefix $(OBJ_DIR)/,$(CLASSES_SUBDIRS))

.PHONY: fullclean
fullclean: clean
	rm -rf $(BIN_DIR)
	mkdir $(BIN_DIR)

.PHONY: show
show:
	@echo CLASSES_CPP $(CLASSES_CPP)
	@echo OBJ_CPP $(OBJ_CPP)
	@echo CFLAGS $(CFLAGS)
	@echo PROGRAM_VERSION $(PROGRAM_VERSION)
	@echo Directories $(SRC_DIR) $(INC_DIR) $(OBJ_DIR) $(BIN_DIR)

.PHONY: class
class:
	@if [[ "$(name)" == "" ]]; then echo "Use: name=MyClass make class"; exit 1; fi
	@echo "#pragma once" >> $(INC_DIR)/$(name).h
	@echo >> $(INC_DIR)/$(name).h
	@echo "class $(name) {" >> $(INC_DIR)/$(name).h
	@echo "public:" >> $(INC_DIR)/$(name).h
	@echo "    $(name)();" >> $(INC_DIR)/$(name).h
	@echo "};" >> $(INC_DIR)/$(name).h
	@echo "#include \"$(name).h\"" >> $(SRC_DIR)/$(name).cpp
	@echo >> $(SRC_DIR)/$(name).cpp
	@echo "$(name)::$(name)() {" >> $(SRC_DIR)/$(name).cpp
	@echo "    // TODO" >> $(SRC_DIR)/$(name).cpp
	@echo "}" >> $(SRC_DIR)/$(name).cpp
