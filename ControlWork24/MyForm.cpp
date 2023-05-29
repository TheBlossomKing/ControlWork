/* 24.	Самый часто встречающийся элемент в диапазоне. 
Напишите функцию, принимающую диапазон и возвращающую самый часто встречающийся элемент в этом диапазоне,
а также сколько раз встретился этот элемент. 
Если в диапазоне имеется несколько самых часто встречающихся элементов с одинаковой частотой, тогда функция должна вернуть все элементы.
Например, для диапазона {1,1,3,5,8,13,3,5,8,8,5} она должна вернуть {5, 3} и {8, 3}.*/
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


// Функция, возвращающая самые часто встречающиеся элементы и их количество повторений
std::vector<std::pair<int, int>> mostFrequentElements(const std::vector<int>& range) {
    std::unordered_map<int, int> frequencyMap;

    // Подсчет частоты каждого элемента в диапазоне
    for (int num : range) {
        frequencyMap[num]++;
    }

    std::vector<std::pair<int, int>> mostFrequent;

    int maxFrequency = 0;

    // Нахождение максимальной частоты
    for (const auto& pair : frequencyMap) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
        }
    }

    // Добавление всех элементов с максимальной частотой в результирующий вектор
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

    // Разделение введенного диапазона на числа
    std::vector<int> range;
    std::istringstream iss(inputRange);
    int num;
    while (iss >> num)
    {
        range.push_back(num);
    }
    std::vector<std::pair<int, int>> result = mostFrequentElements(range);
    // Формирование строки с результатом
    std::string outputStr = "Самые часто встречающиеся элементы:\n";
    for (const auto& pair : result) {
        outputStr += std::to_string(pair.first) + " (количество повторений: " + std::to_string(pair.second) + ")\n";
    }

    String^ output = gcnew String(outputStr.c_str());
    resultLabel->Text = output;
}
    
