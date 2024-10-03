#ifndef MODE_H
#define MODE_H

void set_mode(int mode);
int get_current_mode();
void export_gpio(int pin[20]);
int set_gpio_direction(int pin, const char *direction);
int set_gpio_value(int pin, int value);

#endif