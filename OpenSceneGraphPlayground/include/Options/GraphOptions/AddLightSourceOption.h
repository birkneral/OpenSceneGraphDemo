#pragma once
#include <Options\GraphOption.h>

class AddLightSourceOption : GraphOption {
public:
	AddLightSourceOption();

	void displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;
private:
	int lightSourceTypeSelectionIndex = 0;

	std::vector<std::string> lightSourceTypes = { "Directional Light", "Point Light" };

	bool overwriteDefaultLightInput = false;
	float lightDirectionInput[3] = { 0.0f, 0.0f, 0.0f };
	float lightPositionInput[3] = { 0.0f, 0.0f, 0.0f };
	float diffuseLightColorInput[4] = { 0.4f, 0.7f, 0.0f, 1.0f };
	float ambientLightColorInput[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
};