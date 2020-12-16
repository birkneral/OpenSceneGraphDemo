#include "Options\StateSetOptions\AdjustRenderingHintOption.h"
#include <UtilityFunctions.h>

AdjustRenderingHintOption::AdjustRenderingHintOption()
{
	selectionIdToRenderingHint[0] = osg::StateSet::RenderingHint::DEFAULT_BIN;
	selectionIdToRenderingHint[1] = osg::StateSet::RenderingHint::OPAQUE_BIN;
	selectionIdToRenderingHint[2] = osg::StateSet::RenderingHint::TRANSPARENT_BIN;

	renderingHintToString[0] = "Default";
	renderingHintToString[1] = "Opaque";
	renderingHintToString[2] = "Transparent";
}

void AdjustRenderingHintOption::displayStateSetOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::TreeNode("Rendering hint")) {

		osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode = currentTreeGeneratorVisitor->selectedNode->getOrCreateStateSet();

		ImGui::Text("Currently used:");

		int currentRenderingHint = stateSetOfCurrentlySelectedNode->getRenderingHint();

		ImGui::Text("	");
		ImGui::SameLine();
		ImGui::Text(renderingHintToString[currentRenderingHint].c_str());

		ImGui::Text("Set rendering hint:");

		UtilityFunctions::displayImGuiComboBox("Rendering hint", renderingHintOptions, renderingHintSelection);

		if (ImGui::Button("Set rendering hint")) {
			stateSetOfCurrentlySelectedNode->setRenderingHint(selectionIdToRenderingHint[renderingHintSelection]);
		}

		ImGui::TreePop();
	}
}
