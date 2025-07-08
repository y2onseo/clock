#ifndef CLOCK_H
#define CLOCK_H

#include <time.h>
#include <windows.h>

// 시계 모드 열거형
typedef enum {
    DIGITAL_MODE,
    ANALOG_MODE
} ClockMode;

// 시계 구조체
typedef struct {
    ClockMode mode;
    int hour;
    int minute;
    int second;
    int show_date;
} Clock;

// 함수 선언
void init_clock(Clock *clock, ClockMode mode);
void update_clock(Clock *clock);
void display_clock(const Clock *clock);
void toggle_date(Clock *clock);
void toggle_mode(Clock *clock);

#endif // CLOCK_H 