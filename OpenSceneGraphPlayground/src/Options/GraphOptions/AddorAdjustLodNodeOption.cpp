#include "Options\GraphOptions\AddorAdjustLodNodeOption.h"

AddorAdjustLodNodeOption::AddorAdjustLodNodeOption()
{
	availableOsgFiles = UtilityFunctions::collectAllOsgFileNamesInDataDirectory();
}

void AddorAdjustLodNodeOption::displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::TreeNode("Add or Adjust LOD Node")) {

		if (ImGui::Button("Add LOD")) {
			osg::ref_ptr<osg::LOD> lodToAdd = new osg::LOD;
			currentTreeGeneratorVisitor->selectedNode->asGroup()->addChild(lodToAdd);
		}

		if (std::strcmp(currentTreeGeneratorVisitor->selectedNode->className(), "LOD") == 0) {
			osg::Node* selectedNode = currentTreeGeneratorVisitor->selectedNode;
			osg::ref_ptr<osg::LOD> currentSelectedLod = dynamic_cast<osg::LOD*>(selectedNode);

			if (ImGui::TreeNode("Current Children")) {

				unsigned int numChildNodes = currentSelectedLod->getNumChildren();

				for (unsigned int i = 0; i < numChildNodes; i++)
				{
					osg::ref_ptr<osg::Node> currentChild = currentSelectedLod->getChild(i);
					float minRange = currentSelectedLod->getMinRange(i);
					float maxRange = currentSelectedLod->getMaxRange(i);

					ImGui::Text(currentChild->className());

					ImGui::SameLine();
					ImGui::Text(", Min Range: ");
					ImGui::SameLine();
					ImGui::Text(std::to_string(minRange).c_str());
					ImGui::SameLine();
					ImGui::Text(", Max Range: ");
					ImGui::SameLine();
					ImGui::Text(std::to_string(maxRange).c_str());

					if (ImGui::Button("Remove")) {
						currentSelectedLod->removeChild(currentChild);
					}
				}

				ImGui::TreePop();
			}

			if (ImGui::TreeNode("Add a Child from File")) {
				if (!availableOsgFiles.empty()) {

					UtilityFunctions::displayImGuiComboBox("File to Add", availableOsgFiles, fileSelectionIndex);

					ImGui::InputFloat("Min Range", &minRangeInput);
					ImGui::InputFloat("Max Range", &maxRangeInput);
					ImGui::InputFloat("Simplifier Ratio", &sampleRatioInput);

					if (sampleRatioInput <= 1.0f && sampleRatioInput > 0.0f && minRangeInput < maxRangeInput) {
						if (ImGui::Button("Add Node")) {
							std::string pathToDataDirectory = "OpenSceneGraphData\\";
							osg::ref_ptr<osg::Node> nodeToAdd = osgDB::readNodeFile(pathToDataDirectory + availableOsgFiles[fileSelectionIndex]);

							osgUtil::Simplifier simplifier;
							simplifier.setSampleRatio(sampleRatioInput);
							nodeToAdd->accept(simplifier);

							currentSelectedLod->addChild(nodeToAdd, minRangeInput, maxRangeInput);
						}
					}
					else {
						ImGui::Text("Please set sample ration in range of 0.0 to 1.0 and\nset range values so, that max is higher than min.");
					}
				}
				else {
					ImGui::Text("Unable to find any file of datatype .osg or .osgt in the data directory.");
				}

				ImGui::TreePop();
			}
		}

		ImGui::TreePop();
	}
}
