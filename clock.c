#include "clock.h"
#include <stdio.h>
#include <time.h>
#include <math.h>

void init_clock(Clock *clock, ClockMode mode) {
    clock->mode = mode;
    clock->show_date = 0;
    update_clock(clock);
}

void update_clock(Clock *clock) {
    time_t current_time;
    struct tm *time_info;

    time(&current_time);
    time_info = localtime(&current_time);

    clock->hour = time_info->tm_hour;
    clock->minute = time_info->tm_min;
    clock->second = time_info->tm_sec;
}

void display_clock(const Clock *clock) {
    int y = -10;
    int x = -10;
    system("cls");
    
    if (clock->mode == DIGITAL_MODE) {
        printf("디지털 시계\n");
        printf("===========\n");
        printf("시간: %02d:%02d:%02d\n", 
               clock->hour, clock->minute, clock->second);
        
        if (clock->show_date) {
            time_t current_time;
            struct tm *time_info;
            char date_string[20];
            
            time(&current_time);
            time_info = localtime(&current_time);
            strftime(date_string, sizeof(date_string), "%Y-%m-%d", time_info);
            printf("날짜: %s\n", date_string);
        }
    } else {
        // 아날로그 시계 출력
        printf("아날로그 시계\n");
        printf("=============\n");
        
        // 시계판 그리기
        for ( y = -10; y <= 10; y++) {
            for ( x = -10; x <= 10; x++) {
                double distance = sqrt(x*x + y*y);
                if (fabs(distance - 10) < 0.5) {
                    printf("O");
                } else if (x == 0 && y == 0) {
                    printf("+");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        
        // 시침, 분침, 초침 그리기
        double hour_angle = (clock->hour % 12 + clock->minute / 60.0) * 30.0;
        double minute_angle = clock->minute * 6.0;
        double second_angle = clock->second * 6.0;
        
        printf("\n시침: %.1f도\n", hour_angle);
        printf("분침: %.1f도\n", minute_angle);
        printf("초침: %.1f도\n", second_angle);
    }
    
    printf("\n명령어:\n");
    printf("D - 날짜 표시 토글\n");
    printf("M - 모드 변경\n");
    printf("Q - 종료\n");
}

void toggle_date(Clock *clock) {
    clock->show_date = !clock->show_date;
}

void toggle_mode(Clock *clock) {
    clock->mode = (clock->mode == DIGITAL_MODE) ? ANALOG_MODE : DIGITAL_MODE;
} 