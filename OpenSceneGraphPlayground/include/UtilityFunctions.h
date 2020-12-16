#pragma once
#include <imgui\imgui.h>
#include <string>
#include <vector>
#include <filesystem>

class UtilityFunctions {
public:
	static void displayImGuiComboBox(std::string comboBoxLabel, const char* selectableValues[], int& selectionIndex);
	static void displayImGuiComboBox(std::string comboBoxLabel, std::vector<std::string> selectableValues, int& selectionIndex);


	static std::vector<std::string> collectAllOsgFileNamesInDataDirectory();
};