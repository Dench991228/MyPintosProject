#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H

#include <round.h>
#include <stdint.h>

#include <stdint.h>
typedef int myfloat;
/*偏移量*/
#define shift 16
/*把整数转换为定点数*/
#define convert_float(n) ((myfloat)(n<<shift))
/*把定点数转换为整数*/
#define convert_integer(x) (x>0?(int)((x+(1<<shift)/2)>>shift):(int)((x-(1<<shift)/2)>>shift))
/*定点数相乘*/
#define mult(x,y) (((int64_t)x*(int64_t)y)>>shift)
/*定点数相除*/
#define div(x,y) ((int64_t)x<<shift)/y
/* Number of timer interrupts per second. */
#define TIMER_FREQ 100

void timer_init (void);
void timer_calibrate (void);

int64_t timer_ticks (void);
int64_t timer_elapsed (int64_t);

/* Sleep and yield the CPU to other threads. */
void timer_sleep (int64_t ticks);
void timer_msleep (int64_t milliseconds);
void timer_usleep (int64_t microseconds);
void timer_nsleep (int64_t nanoseconds);

/* Busy waits. */
void timer_mdelay (int64_t milliseconds);
void timer_udelay (int64_t microseconds);
void timer_ndelay (int64_t nanoseconds);

void timer_print_stats (void);

#endif /* devices/timer.h */
