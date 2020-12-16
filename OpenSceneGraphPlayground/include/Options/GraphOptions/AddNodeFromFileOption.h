#pragma once
#include <Options\GraphOption.h>

class AddNodeFromFileOption : GraphOption {
public:
	AddNodeFromFileOption();

	void displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;
	
	void collectAllOsgFileNamesInDataDirectory();

private:
	std::string pathToDataDirectory = "OpenSceneGraphData\\";
	std::vector<std::string> availableOsgFiles;
	
	int fileSelectionIndex = 0;
};