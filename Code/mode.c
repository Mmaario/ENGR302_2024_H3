#include "mode.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Example GPIO setup for BeagleBone Black
#define GPIO_PIN_BASE "/sys/class/gpio/gpio"
#define NUM_MODES 6

int current_mode = -1;

void export_gpio(int pin) {
    FILE *export_file = fopen("/sys/class/gpio/export", "w");
    if (export_file == NULL) {
        perror("Error exporting GPIO");
        exit(1);
    }
    fprintf(export_file, "%d", pin);
    fclose(export_file);
}

void set_gpio_direction(int pin, const char *direction) {
    char path[50];
    sprintf(path, GPIO_PIN_BASE "%d/direction", pin);
    FILE *direction_file = fopen(path, "w");
    if (direction_file == NULL) {
        perror("Error setting GPIO direction");
        exit(1);
    }
    fprintf(direction_file, "%s", direction);
    fclose(direction_file);
}

void set_gpio_value(int pin, int value) {
    char path[50];
    sprintf(path, GPIO_PIN_BASE "%d/value", pin);
    FILE *value_file = fopen(path, "w");
    if (value_file == NULL) {
        perror("Error setting GPIO value");
        exit(1);
    }
    fprintf(value_file, "%d", value);
    fclose(value_file);
}

void set_mode(int mode) {
    if (mode == current_mode) return;

    // Deactivate current mode
    if (current_mode != -1) {
        set_gpio_value(current_mode, 0);
    }

    // Activate new mode
    set_gpio_value(mode, 1);
    current_mode = mode;
}

int get_current_mode() {
    return current_mode;
}
