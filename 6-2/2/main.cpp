#include "accounts.h"
#include <iostream>
#include <sstream>

int main() {
    Manager manager; //change name
    
    auto log = [](std::string&& msg, int result) {
        if (result == 0) {
            std::cout << "Success: ";
        }
        else if (result == 1){
            std::cout << "Failure: ";
        }
        std::cout << msg << std::endl;
    };
    auto no_account = [] {
        std::cout << "Account does not exist" << std::endl;
    };

    while (true) {
        char job = '\0';
        std::cout << "Job?" << std::endl;
        std::cin >> job;

        switch (job) {
        //New account
        case 'N': {
            int id = manager.GetSize();
            std::stringstream stream;
            stream << "Account for user " << id << " registered";

            log(stream.str(), manager.NewAccount());
            std::cout << manager.Log(id) << std::endl;
            break;
        }
        //Deposit
        case 'D': {
            int id = 0, money = 0;
            std::cin >> id >> money;

            if (manager.GetSize() == 0) {
                no_account();
                continue;
            }

            std::stringstream stream;
            stream << "Deposit to user " << id << ' ' << money;

            log(stream.str(), manager.Deposit(id, money));
            std::cout << manager.Log(id) << std::endl;
            break;
        }
        //Withdraw
        case 'W': {
            int id = 0, money = 0;
            std::cin >> id >> money;

            if (manager.GetSize() == 0) {
                no_account();
                continue;
            }

            std::stringstream stream;
            stream << "Withdraw from user " << id << ' ' << money;

            log(stream.str(), manager.Withdraw(id, money));
            std::cout << manager.Log(id) << std::endl;
            break;
        }
        //Transfer
        case 'T': { 
            int src = 0, dst = 0, money = 0;
            std::cin >> src >> dst >> money;

            if (manager.GetSize() == 0) {
                no_account();
                continue;
            }

            std::stringstream stream;
            stream << "Transfer from user " << src << " to user " << dst << ' ' << money;
        
            log(stream.str(), manager.Transfer(src, dst, money));
            if (src > dst) {
                std::swap(src, dst);
            }
            std::cout << manager.Log(src) << std::endl;
            std::cout << manager.Log(dst) << std::endl;
            break;
        }
        //Quit
        case 'Q':
            return 0;
        }
    }
    return 0;
}