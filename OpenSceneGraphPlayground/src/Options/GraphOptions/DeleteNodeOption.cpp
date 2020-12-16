#include "Options\GraphOptions\DeleteNodeOption.h"

DeleteNodeOption::DeleteNodeOption()
{
}

void DeleteNodeOption::displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::Button("Delete Node")) {
		osg::ref_ptr<osg::Group> parentNode = currentTreeGeneratorVisitor->selectedNode->getParent(0);
		parentNode->removeChild(currentTreeGeneratorVisitor->selectedNode);
		currentTreeGeneratorVisitor->selectedNode = NULL;
	}
}
