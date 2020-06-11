// Copyright (c) 2019-2020 The Bigbang developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

// #include <exception>
// #include <iostream>

// #include "entry.h"
// #include "util.h"

// using namespace bigbang;

// void Shutdown()
// {
//     CBbEntry::GetInstance().Stop();
// }

// int main(int argc, char** argv)
// {
//     CBbEntry& entry = CBbEntry::GetInstance();
//     try
//     {
//         if (entry.Initialize(argc, argv))
//         {
//             entry.Run();
//         }
//     }
//     catch (std::exception& e)
//     {
//         xengine::StdError(__PRETTY_FUNCTION__, e.what());
//     }
//     catch (...)
//     {
//         xengine::StdError(__PRETTY_FUNCTION__, "unknown");
//     }

//     entry.Exit();

//     return 0;
//}

// Copyright (c) 2019-2020 The Bigbang developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <exception>
#include <iostream>

#include "entry.h"
#include "util.h"
#include <thread>
#include <future>
using namespace std; 

using namespace bigbang;

void Shutdown()
{
    CBbEntry::GetInstance().Stop();
}

const char *info = "abcdefg-1234567890-abcdefg-1234567890-abcdefg-1234567890-abcdefg-1234567890-abcdefg-1234567890-abcdefg-1234567890-abcdefg-1234567890-abcdefg-1234567890";
int n = 1000 * 1000;
void Trace()
{
    for (int i = 0; i < n; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(3));
        xengine::StdTrace("Trace","%s,%d",info,i);
    }
}

void Debug()
{
    for (int i = 0; i < n; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(2));
        xengine::StdDebug("Debug","%s,%d",info,i);
    }
}

void Log()
{
    for (int i = 0; i < n * 3; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(1));
        xengine::StdLog("Log","%s,%d",info,i);
    }
}

void Warn()
{
    for (int i = 0; i < n; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(2));
        xengine::StdWarn("Warn","%s,%d",info,i);
    }
}

void Error()
{
    for (int i = 0; i < n; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(3));
        xengine::StdError("Error","%s,%d",info,i);
    }
}


int main(int argc, char** argv)
{
    boost::filesystem::path pathData = "/home/mathxh/log";
    xengine::InitLog(pathData,true,false,10,2048); 
    std::thread t1(Trace);
    std::thread t2(Debug);
    std::thread t3(Log);
    std::thread t4(Warn);
    std::thread t5(Error);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
    CBbEntry& entry = CBbEntry::GetInstance();
    try
    {
        if (entry.Initialize(argc, argv))
        {
            entry.Run();
        }
    }
    catch (std::exception& e)
    {
        xengine::StdError(__PRETTY_FUNCTION__, e.what());
    }
    catch (...)
    {
        xengine::StdError(__PRETTY_FUNCTION__, "unknown");
    }

    entry.Exit();

    return 0;
}

