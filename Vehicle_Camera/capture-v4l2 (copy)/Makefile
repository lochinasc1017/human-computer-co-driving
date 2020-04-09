CC := g++
APP := cap

SRCS := \
        main.cpp 

OBJS := $(SRCS:.cpp=.o)

CPPFLAGS += \
        `pkg-config --cflags opencv`

LDFLAGS += \
	`pkg-config --libs opencv` -L./ -lvideoCapture 

all: $(APP)

%.o: %.cpp
	@echo "Compiling: $<"
	$(CC) -g -O0 $(CPPFLAGS) -c $< -o $@

$(APP): $(OBJS)
	@echo "Linking: $@"
	$(CC) -o $@ $(OBJS) $(CPPFLAGS) $(LDFLAGS)

clean:
	@rm -rf $(APP) $(OBJS)

