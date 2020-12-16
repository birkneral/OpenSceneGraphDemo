#include "UtilityFunctions.h"

void UtilityFunctions::displayImGuiComboBox(std::string comboBoxLabel, const char* selectableValues[], int& selectionIndex)
{
	const char* currentSelection = selectableValues[selectionIndex];
	if (ImGui::BeginCombo(comboBoxLabel.c_str(), currentSelection)) {
		for (int n = 0; n < IM_ARRAYSIZE(selectableValues); n++)
		{
			const bool is_selected = (selectionIndex == n);
			if (ImGui::Selectable(selectableValues[n], is_selected))
				selectionIndex = n;

			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}

}

void UtilityFunctions::displayImGuiComboBox(std::string comboBoxLabel, std::vector<std::string> selectableValues, int& selectionIndex)
{
	const char* currentSelection = selectableValues[selectionIndex].c_str();
	if (ImGui::BeginCombo(comboBoxLabel.c_str(), currentSelection)) {
		for (int n = 0; n < selectableValues.size(); n++)
		{
			const bool is_selected = (selectionIndex == n);
			if (ImGui::Selectable(selectableValues[n].c_str(), is_selected))
				selectionIndex = n;

			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}
}

std::vector<std::string> UtilityFunctions::collectAllOsgFileNamesInDataDirectory()
{
	std::string pathToDataDirectory = "OpenSceneGraphData\\";

	std::vector<std::string> availableOsgFiles;

	for (const auto& entry : std::filesystem::directory_iterator(pathToDataDirectory)) {
		if (entry.path().extension() == ".osg" || entry.path().extension() == ".osgt") {
			availableOsgFiles.push_back(entry.path().filename().string());
		}
	}
	return availableOsgFiles;
}
