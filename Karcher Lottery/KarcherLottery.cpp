#include "KarcherLottery.h"

using namespace System;
using namespace System::Windows::Forms;

void KarcherLottery::KarcherLottery::CreateInputFile()
{
    std::wofstream myfile;
    myfile.open("seznam soutezicich.txt", std::ios::app);
    myfile.close();
}

std::vector<std::wstring> KarcherLottery::KarcherLottery::PrepareParticipants()
{
    std::wstring line;
    std::wifstream myfile(L"seznam soutezicich.txt");
    std::vector<std::wstring> participants;

    std::locale loc("cs_CZ.UTF-8");
    myfile.imbue(loc);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            participants.push_back(line);
        }
        myfile.close();
    }

    return participants;
}

std::vector<std::wstring> KarcherLottery::KarcherLottery::GenerateWinners(std::vector<std::wstring> participants)
{
    int max_contenders = participants.size();
    std::vector<std::wstring> winners;
    std::wstring winner;
    srand(time(NULL));

    if (max_contenders > 0)
    {
        for (size_t i = 0; i < 5; i++)
        {
            unsigned int random_winner = 0;

            random_winner = rand() % max_contenders;
            winner = participants.at(random_winner);
            bool old_winner = false;

            for (std::vector<std::wstring>::iterator it = winners.begin(); it != winners.end(); ++it)
            {
                if (*it == winner)
                {
                    old_winner = true;
                    i--;
                    break;
                }
            }

            if (old_winner == false)
            {
                winners.push_back(winner);
            }
        }
    }

    return winners;
}

System::String^ KarcherLottery::KarcherLottery::ConvertToSystemString(std::wstring string)
{
    std::wstring str = string;
    System::String^ newSystemString = gcnew System::String(str.c_str());
    return newSystemString;
}

[STAThreadAttribute()]
void Main(array<System::String^>^ args)// it's now void and starts with capital M
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew KarcherLottery::KarcherLottery());

    //CreateInputFile();
}