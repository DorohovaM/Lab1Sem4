#include "Stopwatch.h"

int Stopwatch_test() 
{
    Stopwatch stopwatch;

    stopwatch.start();
    int x;
    cin >> x;
    stopwatch.stop();

    stopwatch.start();
    cin >> x;
    stopwatch.stop();

    stopwatch.show_history();
    stopwatch.reset();
    stopwatch.show_history();

    return 0;
}