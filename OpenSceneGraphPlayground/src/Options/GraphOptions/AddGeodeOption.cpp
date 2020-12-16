#include "Options\GraphOptions\AddGeodeOption.h"

AddGeodeOption::AddGeodeOption()
{
}

void AddGeodeOption::displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::TreeNode("Add Geode")) {
		if (ImGui::Button("Add Geode")) {
			osg::ref_ptr<osg::Geode> geodeToAdd = new osg::Geode;
			currentTreeGeneratorVisitor->selectedNode->asGroup()->addChild(geodeToAdd);
		}

		ImGui::TreePop();
	}
}
