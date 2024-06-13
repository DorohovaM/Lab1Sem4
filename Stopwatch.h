#pragma once
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;


class Stopwatch
{
    vector<double> history;
    clock_t start_time;
    clock_t end_time;
    bool is_running;
    double result;

public:

    Stopwatch();

    friend ostream& operator<<(ostream& os, const Stopwatch& sw);

    void start();
    void stop();
    void reset();
    void show_history();
};

Stopwatch::Stopwatch() {

    start_time = 0;
    end_time = 0;
    is_running = false;
}

void Stopwatch::start() {

    if (!is_running) {
        start_time = clock();
        is_running = true;
        cout << "Stopwatch is started" << endl << "Write 0 to stop" << endl;
    }
    else {
        cout << "Stopwatch yas already been started" << endl << "Write 0 to stop" << endl;
    }
}

void Stopwatch::stop() {

    if (is_running) {
        end_time = clock();
        is_running = false;
        cout << "Stopwatch is stopped" << endl << endl;
        result = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        history.emplace_back(result);
    }
    else {
        cout << "Stopwatch hasn't been started" << endl;
    }
}

void Stopwatch::reset() {

    start_time = 0;
    end_time = 0;
    is_running = false;
    history.clear();
    history.resize(0);
    cout << "The history is deleted" << endl;
}

void Stopwatch::show_history() {

    cout << "The history: " << endl;
    for (int i = 0; i < history.size(); i++)
        cout << history[i] << " secs" << endl;
}

ostream& operator<<(ostream& os, const Stopwatch& sw) {

    os << sw.result << " secs" << endl;
    return os;
}