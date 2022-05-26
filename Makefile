CXXFLAGS = -g -Wall -msse -std=c++11 -DGLM_ENABLE_EXPERIMENTAL -D_GLIBCXX_DEBUG
LDFLAGS = -lpthread
TARGET = RenderTest

HEADER_DIR=./include
SRC_DIR=./src

OSFLAG :=
RM_BIN_PATH :=
RM_BUILD_PATH :=

LIB_DIRS =-L
INC_DIRS =-Iinclude

ifeq ($(OS),Windows_NT)
	CXX = clang++
	RM = del /Q
	RM_BIN_PATH =.\\bin\\win32\\debug\\
	RM_BUILD_PATH =.\\build\\win32\\

	LIB_DIRS +=./lib/win32/glfw-3.2.1/src
	INC_DIRS += -I./lib/win32/glfw-3.2.1/include
	INC_DIRS += -I./lib/win32/rapidxml-1.13

	BIN_DIR=./bin/win32/debug
	BUILD_DIR=./build/win32

	OUT_TARGET=$(TARGET).exe

	CXXFLAGS +=-target x86_64-pc-windows-gnu
	LDFLAGS +=-target x86_64-pc-windows-gnu -lglfw3 -lgdi32 -lopengl32

	OSFLAG += -D WIN32
	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		OSFLAG += -D AMD64
	endif
	ifeq ($(PROCESSOR_ARCHITECTURE),x86)
		OSFLAG += -D IA32
	endif
else
	CXX = clang++-6.0
	RM = rm -rf

	RM_BIN_PATH =$(BIN_DIR)/
	RM_BUILD_PATH =$(BUILD_DIR)/

	LIB_DIRS +=./lib/linux_i386/glfw-3.2.1/build/src
	INC_DIRS += -I./lib/linux_i386/glfw-3.2.1/include
	INC_DIRS += -I./lib/linux_i386/rapidxml-1.13

	BIN_DIR=./bin/linux_i386/debug
	BUILD_DIR=./build/linux_i386

	OUT_TARGET=$(TARGET).out

	LDFLAGS +=-ldl -lglfw

	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		OSFLAG += -D LINUX
	endif
	ifeq ($(UNAME_S),Darwin)
		OSFLAG += -D OSX
	endif
		UNAME_P := $(shell uname -p)
	ifeq ($(UNAME_P),x86_64)
		OSFLAG += -D AMD64
	endif
		ifneq ($(filter %86,$(UNAME_P)),)
		OSFLAG += -D IA32
		endif
	ifneq ($(filter arm%,$(UNAME_P)),)
		OSFLAG += -D ARM
	endif
endif

HEADER_FILES := $(wildcard $(HEADER_DIR)/*.hpp) $(wildcard $(HEADER_DIR)/*.h)
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*.c)
O_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRC_FILES))
O_FILES := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(O_FILES))

all: $(TARGET)

$(TARGET): $(O_FILES)
	$(CXX) $(LIB_DIRS) $(O_FILES) -o $(BUILD_DIR)/$(OUT_TARGET) $(LDFLAGS)

$(BIN_DIR)/$(TARGET).o: $(SRC_DIR)/$(TARGET).cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@
							
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(RM_BIN_PATH)*.o
	$(RM) $(RM_BUILD_PATH)$(OUT_TARGET)
