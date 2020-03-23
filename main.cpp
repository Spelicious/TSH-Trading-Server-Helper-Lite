#include <windows.h>
#include "iostream"
#include <dinput.h>

int main()
{
    // Copyright - steamcommunity.com/id/Spelicious
    SetConsoleTitle( TEXT("Trading Server Helper v0.3 by Spelicious"));
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "               TradingServerHelper v0.3              " << std::endl;
    std::cout << "   Copyright 2020 - https://github.com/Spelicious/   " << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "                                                     " << std::endl;
    std::cout << "         To start TradingServerHelper press '8'.     " << std::endl;
    std::cout << "       If you want to close the program press '9'.   " << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;

    int timer = 0;
    int stalking = 0;
    while (true) {
        timer++;
        Sleep(100);
        if (GetAsyncKeyState(0x39)) {
            std::cout << "Trading Helper will close in 3 seconds." << std::endl;
            Sleep(3000);
            return 0;
        }
        if (GetAsyncKeyState(0x38)) {
            std::cout << "Trading Helper is started!" << std::endl;
            stalking = 1;
        }
        /*
        IF timer > 100 = 10 seconds + 2 seconds (to execute keys)
        IF timer > 150 = 15 seconds + 2 seconds (to execute keys)
        IF timer > 200 = 20 seconds + 2 seconds (to execute keys)
        IF timer > 250 = 25 seconds + 2 seconds (to execute keys)
        IF timer > 300 = 30 seconds + 2 seconds (to execute keys)
        IF timer > 350 = 35 seconds + 2 seconds (to execute keys)
        */
        if (timer > 130) {
            timer = 0;
            if (stalking) {

                INPUT ip;
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0; 
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = 0;

                // Press the "7" key
                ip.ki.wScan = DIKEYBOARD_7;
                ip.ki.dwFlags = 0; // 0 for key press
                SendInput(1, &ip, sizeof(INPUT));
                Sleep(50);
                // Release the "7" key
                ip.ki.dwFlags = KEYEVENTF_KEYUP; 
                SendInput(1, &ip, sizeof(INPUT));

                std::cout << "Bind '7' was pressed." << std::endl;
                Sleep(2000);
                std::cout << "--------------------------------------------------------" << std::endl;
            }
        }
    }
}
