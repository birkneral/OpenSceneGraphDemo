#pragma once
#include <Options\GraphOption.h>

class AddShapeDrawableOption : GraphOption {
public:
	AddShapeDrawableOption();

	void displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;
private:
	const char* typesOfShapes[3] = { "Sphere", "Box", "Cone" };

	int shapeTypeSelectionIndex = 0;

	float shapePositionInput[3] = { 0.0f, 0.0f, 0.0f };
	float shapeColorInput[4] = { 0.4f, 0.7f, 0.0f, 1.0f };

	float sphereRadiusInput = 0.1f;

	float boxSizeInput[3] = { 1.0f, 1.0f, 1.0f };

	float coneRadiusInput = 0.1f;
	float coneHeightInput = 1.0f;

};