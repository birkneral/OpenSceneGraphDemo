#include "Options\GraphOptions\AddOrAdjustSwitchNodeOption.h"
#include <string>
#include <osg/Switch>

AddOrAdjustSwitchNodeOption::AddOrAdjustSwitchNodeOption()
{
}

void AddOrAdjustSwitchNodeOption::displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::TreeNode("Add or adjust Switch Node")) {

		if (ImGui::Button("Add Switch")) {
			osg::ref_ptr<osg::Switch> switchToAdd = new osg::Switch;
			currentTreeGeneratorVisitor->selectedNode->asGroup()->addChild(switchToAdd);
		}

		if (currentTreeGeneratorVisitor->selectedNode != NULL && std::strcmp(currentTreeGeneratorVisitor->selectedNode->className(), "Switch") == 0) {
			if (ImGui::TreeNode("Adjust Switch Values")) {	
				osg::ref_ptr<osg::Switch> currentSelectedSwitch = currentTreeGeneratorVisitor->selectedNode->asSwitch();
				int numChildNodes = currentSelectedSwitch->getNumChildren();

				ImGui::Text("Children:");

				for (unsigned int i = 0; i < numChildNodes; i++)
				{
					osg::ref_ptr<osg::Node> currentChild = currentSelectedSwitch->getChild(i);
					bool valueOfCurrentChild = currentSelectedSwitch->getChildValue(currentChild);

					ImGui::Text("	");
					ImGui::SameLine();
					ImGui::Text(currentChild->className());

					ImGui::SameLine();
					ImGui::Text(", Value: ");
					ImGui::SameLine();
					std::string valueAsString = valueOfCurrentChild ? "True" : "False";
					ImGui::Text(valueAsString.c_str());
				
					ImGui::SameLine();
					std::string btnLabel = "Toggle" + std::to_string(i);
					if (ImGui::Button(btnLabel.c_str())) {
						currentSelectedSwitch->setChildValue(currentChild, !valueOfCurrentChild);
					}
				}

				if (ImGui::Button("Set all on")) {
					currentSelectedSwitch->setAllChildrenOn();
				}

				if (ImGui::Button("Set all off")) {
					currentSelectedSwitch->setAllChildrenOff();
				}

				ImGui::TreePop();
			}
		}

		ImGui::TreePop();
	}
}
