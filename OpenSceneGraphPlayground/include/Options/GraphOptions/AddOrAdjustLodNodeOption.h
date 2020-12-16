#pragma once
#include <Options\GraphOption.h>
#include <osg\LOD>
#include <osgDB\ReadFile>
#include <UtilityFunctions.h>
#include <osgUtil\Simplifier>

class AddorAdjustLodNodeOption : GraphOption {
public:
	AddorAdjustLodNodeOption();

	void displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;
private:
	std::vector<std::string> availableOsgFiles;

	int fileSelectionIndex = 0;

	float minRangeInput = 0.0f;
	float maxRangeInput = 50.0f;
	float sampleRatioInput = 1.0f;
};