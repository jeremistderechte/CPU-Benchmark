#include <iostream>
#include <iomanip>
#include <chrono>

int calculate_points(double executionTime){
    return 1.0 / executionTime * 10000.0;
}

void calculate_pi() {

    bool execute = true;
    char answer = '\0';

    while (execute) {

        using std::chrono::high_resolution_clock;
        using std::chrono::duration_cast;
        using std::chrono::duration;
        using std::chrono::seconds;
        auto t1 = high_resolution_clock::now();

        unsigned int iterations = -1;

// Single Core Test

        float denominator = 1.0;
        float quarter_of_pi = 0.0;

        std::cout << "Calculating pi with " << iterations << " iterations" << std::endl;
        for (int i = 0; i < iterations; i++) {
            if (i % 2 == 0) {
                quarter_of_pi += (1.0 / denominator);
            } else {
                quarter_of_pi -= (1.0 / denominator);
            }
            denominator += 2.0;
        }

        float pi = quarter_of_pi * 4.0;

        std::cout << "The approximation of pi is: " << std::setprecision(10) << pi << " after " << iterations
                  << " iterations" << std::endl;

        auto t2 = high_resolution_clock::now();

/* Getting number of milliseconds as a double. */
        duration<double> ms_double = t2 - t1;

        std::cout << "Your Benchmark Score: " << calculate_points(ms_double.count()) << std::endl;

        bool ask_repeat = true;

        while (ask_repeat) {

            std::cout << "Repeat the benchmark? (y/n): ";
            std::cin >> answer;

            if (answer == 'n') {
                break;
            } else if (answer == 'y') {
                std::cout << std::endl;
                ask_repeat = false;
            } else {
                std::cout << "Wrong character" << "(" << answer << ")" << std::endl;
            }
        }
    }
}

void clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}

int main()
{
    int user_choice = 0;
    std::string start_options[] = {"Start Benchmark", "System information", "Exit benchmark"};
    std::string socials[] = {"Linkedin: https://www.linkedin.com/in/jeremy-barenkamp/",
                             "YoutTube: https://www.youtube.com/@ghardware2440",
                             "Github: https://github.com/jeremistderechte"};

    std::cout << "Welcome to CPB (cross platform CPU Benchmark) by Jeremy Barenkamp" << std::endl << std::endl;
    std::cout << "My socials:" << std::endl;

    for (int i = 0; i< sizeof(socials) / sizeof(socials[0]); i++){
        std::cout << socials[i] << std::endl;
    }
    std::cout << "\n";


    for (int i = 0; i< sizeof(start_options) / sizeof(start_options[0]); i++){
        if (i == 0){
            std::cout << "What do you want to do? (Chose between 0-" << (sizeof(start_options) / sizeof(start_options[0])-1) << ")" << std::endl << std::endl;
        }

        std::cout << "(" << i << ") " << start_options[i] << std::endl;

    }

    std::cout << "\n";
    std::cin >> user_choice;

    switch (user_choice) {
        case 0:
            calculate_pi();
            break;
        case 1:
            //display system specs
            break;
        case 2:
            return 0;
        default:
            clear();
            main();

    }






    //return 0;
}