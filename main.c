#include "clock.h"
#include <stdio.h>
#include <conio.h>

int main() {
    Clock my_clock;
    char input;
    
    // 디지털 모드로 초기화
    init_clock(&my_clock, DIGITAL_MODE);
    
    while (1) {
        update_clock(&my_clock);
        display_clock(&my_clock);
        
        if (_kbhit()) {
            input = _getch();
            switch (input) {
                case 'd':
                case 'D':
                    toggle_date(&my_clock);
                    break;
                case 'm':
                case 'M':
                    toggle_mode(&my_clock);
                    break;
                case 'q':
                case 'Q':
                    return 0;
            }
        }
        
        Sleep(1000);
    }
    
    return 0;
} 