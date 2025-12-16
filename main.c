src/ui/main.c
```c
#include <gtk/gtk.h>
#include "main_window.h"

int main(int argc, char *argv[]) {
    gtk_init();
    GtkWidget* window = create_main_window();
    gtk_window_present(GTK_WINDOW(window));
    gtk_main();
    return 0;
}
```

### include/scanner.h
```c
#ifndef SCANNER_H
#define SCANNER_H

typedef struct {
    int count;
    // TODO: add items array with metadata, paths, sizes, timestamps
} scan_result_t;

scan_result_t scan_drive(const char* path);

#endif
```

### src/recovery/scanner.c
```c
#include "scanner.h"
#include <stdio.h>

scan_result_t scan_drive(const char* path) {
    (void)path;
    // Placeholder: real implementation would parse filesystem structures
    scan_result_t r = { .count = 3 };
    printf("Scanning drive: %s\n", path);
    return r;
}
```
