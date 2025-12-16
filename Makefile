## Makefile

```makefile
APP := data-recovery-tool
SRC := src/ui/main.c src/ui/main_window.c src/recovery/scanner.c src/recovery/recover.c src/common/log.c
INCLUDE := -Iinclude
CFLAGS := -Wall -Wextra -O2 $(INCLUDE)
LDLIBS := $(shell pkg-config --libs gtk4)
CPPFLAGS := $(shell pkg-config --cflags gtk4)

all: $(APP)

$(APP): $(SRC)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(APP) $(SRC) $(LDLIBS)

run: all
	./$(APP)

clean:
	rm -f $(APP)
```

Notes:
- Uses GTK4. Install dev packages before building.
