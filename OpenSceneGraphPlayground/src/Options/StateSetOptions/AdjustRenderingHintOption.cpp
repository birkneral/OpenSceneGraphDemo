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

void AdjustRenderingHintOption::displayStateSetOption(osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode)
{
	if (ImGui::TreeNode("Rendering Hint")) {

		ImGui::Text("Currently Used:");

		int currentRenderingHint = stateSetOfCurrentlySelectedNode->getRenderingHint();

		ImGui::Text("	");
		ImGui::SameLine();
		ImGui::Text(renderingHintToString[currentRenderingHint].c_str());

		ImGui::Text("Set Rendering Hint:");

		UtilityFunctions::displayImGuiComboBox("Rendering Hint", renderingHintOptions, renderingHintSelection);

		if (ImGui::Button("Set Rendering Hint")) {
			stateSetOfCurrentlySelectedNode->setRenderingHint(selectionIdToRenderingHint[renderingHintSelection]);
		}

		ImGui::TreePop();
	}
}
