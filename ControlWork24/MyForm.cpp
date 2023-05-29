/* 24.	����� ����� ������������� ������� � ���������. 
�������� �������, ����������� �������� � ������������ ����� ����� ������������� ������� � ���� ���������,
� ����� ������� ��� ���������� ���� �������. 
���� � ��������� ������� ��������� ����� ����� ������������� ��������� � ���������� ��������, ����� ������� ������ ������� ��� ��������.
��������, ��� ��������� {1,1,3,5,8,13,3,5,8,8,5} ��� ������ ������� {5, 3} � {8, 3}.*/
#include "MyForm.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <sstream>

using namespace ControlWork24;
using namespace System;
using namespace System::Windows::Forms;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm);

    return 0;
}


// �������, ������������ ����� ����� ������������� �������� � �� ���������� ����������
std::vector<std::pair<int, int>> mostFrequentElements(const std::vector<int>& range) {
    std::unordered_map<int, int> frequencyMap;

    // ������� ������� ������� �������� � ���������
    for (int num : range) {
        frequencyMap[num]++;
    }

    std::vector<std::pair<int, int>> mostFrequent;

    int maxFrequency = 0;

    // ���������� ������������ �������
    for (const auto& pair : frequencyMap) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
        }
    }

    // ���������� ���� ��������� � ������������ �������� � �������������� ������
    for (const auto& pair : frequencyMap) {
        if (pair.second == maxFrequency) {
            mostFrequent.push_back(std::make_pair(pair.first, pair.second));
        }
    }

    return mostFrequent;
}

System::Void ControlWork24::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string inputRange = msclr::interop::marshal_as<std::string>(textBox1->Text);

    // ���������� ���������� ��������� �� �����
    std::vector<int> range;
    std::istringstream iss(inputRange);
    int num;
    while (iss >> num)
    {
        range.push_back(num);
    }
    std::vector<std::pair<int, int>> result = mostFrequentElements(range);
    // ������������ ������ � �����������
    std::string outputStr = "����� ����� ������������� ��������:\n";
    for (const auto& pair : result) {
        outputStr += std::to_string(pair.first) + " (���������� ����������: " + std::to_string(pair.second) + ")\n";
    }

    String^ output = gcnew String(outputStr.c_str());
    resultLabel->Text = output;
}
    
