#include "Options\StateSetOptions\AdjustStateOption.h"

AdjustStateOption::AdjustStateOption()
{

}

void AdjustStateOption::displayStateSetOption(osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode)
{
	if (ImGui::TreeNode("Adjust State")) {

		if (stateSetOfCurrentlySelectedNode != NULL) {
			adjustPolygonModeOption.displayStateSetOption(stateSetOfCurrentlySelectedNode);
			adjustRenderingHintOption.displayStateSetOption(stateSetOfCurrentlySelectedNode);
			adjustBlendFunctionOption.displayStateSetOption(stateSetOfCurrentlySelectedNode);
			adjustLightStateOption.displayStateSetOption(stateSetOfCurrentlySelectedNode);
			addShaderOption.displayStateSetOption(stateSetOfCurrentlySelectedNode);
		}
		else {
			ImGui::Text("Please select node.");
		}

		ImGui::TreePop();
	}
}