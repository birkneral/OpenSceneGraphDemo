#include "Options\GraphOptions\AddGroupOption.h"

AddGroupOption::AddGroupOption()
{
}

void AddGroupOption::displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::TreeNode("Add Group")) {
		if (ImGui::Button("Add Group")) {
			osg::ref_ptr<osg::Group> groupToAdd = new osg::Group;
			currentTreeGeneratorVisitor->selectedNode->asGroup()->addChild(groupToAdd);
		}

		ImGui::TreePop();
	}
}
