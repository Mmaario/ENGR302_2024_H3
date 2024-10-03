#include "mode.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define GPIO_EXPORT_PATH "/sys/class/gpio/export"
#define GPIO_UNEXPORT_PATH "/sys/class/gpio/unexport"
#define GPIO_DIRECTION_PATH "/sys/class/gpio/gpio%d/direction"
#define GPIO_VALUE_PATH "/sys/class/gpio/gpio%d/value"

int current_mode = -1;

void export_gpio(int pin[20]) {
    FILE *export_file = fopen(GPIO_EXPORT_PATH, "w");
    usleep(1000);
    if (export_file == NULL) {
        perror("Error exporting GPIO");
        exit(1);
    }
    for (int i = 0; i < 6; i++) {
        fprintf(export_file, "%d", pin[i]);
    }

    fclose(export_file);
}

int set_gpio_direction(int pin, const char *direction) {
    char direction_path[40];
    sprintf(direction_path, GPIO_DIRECTION_PATH, pin);   
    int fd = open(direction_path, O_WRONLY);
    


    
    if (fd == -1) {
        perror("Error setting GPIO direction:");
        printf("%d \n",pin);
        return -1;
    }

    if (write(fd, direction, strlen(direction)) == -1) {
        perror("Error writing to direction file");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}

int set_gpio_value(int pin, int value) {
    char value_path[40];
 
    sprintf(value_path, GPIO_VALUE_PATH, pin);
    int fd = open(value_path, O_WRONLY);

    if (fd == -1) {
        perror("Error setting GPIO value");
        return -1;
    }

    char value_str = (value == 1) ? '1' : '0';
    if (write(fd, &value_str, 1) == -1) {
        perror("Error writing to value file");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
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
