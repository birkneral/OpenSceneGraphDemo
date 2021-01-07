#include "Options\GraphOptions\AddNodeFromFileOption.h"
#include <osgDB\ReadFile>
#include <filesystem>
#include "UtilityFunctions.h"

AddNodeFromFileOption::AddNodeFromFileOption()
{
	collectAllOsgFileNamesInDataDirectory();
}

void AddNodeFromFileOption::displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::TreeNode("Add Node from OSG File")) {

		if (!availableOsgFiles.empty()) {

			UtilityFunctions::displayImGuiComboBox("File to Add", availableOsgFiles, fileSelectionIndex);

			if (ImGui::Button("Add Node")) {
				osg::ref_ptr<osg::Node> nodeToAdd = osgDB::readNodeFile(pathToDataDirectory + availableOsgFiles[fileSelectionIndex]);
				currentTreeGeneratorVisitor->selectedNode->asGroup()->addChild(nodeToAdd);
			}
		}
		else {
			ImGui::Text("Unable to find any file of datatype .osg or .osgt in the data directory.");
		}

		ImGui::TreePop();
	}	
}

void AddNodeFromFileOption::collectAllOsgFileNamesInDataDirectory()
{
	for (const auto& entry : std::filesystem::directory_iterator(pathToDataDirectory)) {
		if (entry.path().extension() == ".osg" || entry.path().extension() == ".osgt") {
			availableOsgFiles.push_back(entry.path().filename().string());
		}
	}
}
