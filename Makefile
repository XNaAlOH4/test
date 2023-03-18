BIN=main

all:$(BIN)

%: %.c
  gcc $^ -o $@
