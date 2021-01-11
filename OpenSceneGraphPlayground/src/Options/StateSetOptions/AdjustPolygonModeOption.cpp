#include "Options\StateSetOptions\AdjustPolygonModeOption.h"
#include <UtilityFunctions.h>

AdjustPolygonModeOption::AdjustPolygonModeOption() : StateSetOption()
{
	selectionIdToPolygonModeFace[0] = osg::PolygonMode::Face::FRONT;
	selectionIdToPolygonModeFace[1] = osg::PolygonMode::Face::BACK;
	selectionIdToPolygonModeFace[2] = osg::PolygonMode::Face::FRONT_AND_BACK;

	selectionIdToPolygonModeMode[0] = osg::PolygonMode::Mode::POINT;
	selectionIdToPolygonModeMode[1] = osg::PolygonMode::Mode::LINE;
	selectionIdToPolygonModeMode[2] = osg::PolygonMode::Mode::FILL;

}

void AdjustPolygonModeOption::displayStateSetOption(osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode)
{
	if (ImGui::TreeNode("Polygon Mode")) {

		ImGui::Text("Currently Used:");
		osg::ref_ptr<osg::PolygonMode> currentPolygonMode = dynamic_cast<osg::PolygonMode*>(stateSetOfCurrentlySelectedNode->getAttribute(osg::StateAttribute::POLYGONMODE));

		if (currentPolygonMode != NULL) {
			osg::PolygonMode::Mode frontMode = currentPolygonMode->getMode(osg::PolygonMode::Face::FRONT);
			osg::PolygonMode::Mode backMode = currentPolygonMode->getMode(osg::PolygonMode::Face::BACK);

			ImGui::Text("	Front: ");
			ImGui::SameLine();
			ImGui::Text(glConstToStringMap[frontMode].c_str());
			ImGui::Text("	Back: ");
			ImGui::SameLine();
			ImGui::Text(glConstToStringMap[backMode].c_str());
		}
		else {
			ImGui::Text("	Polygon mode is not set for this node.");
		}

		ImGui::Text("Select Polygon Mode:");				
		UtilityFunctions::displayImGuiComboBox("P-Face", polygonModeFaces, faceSelectionIndex);
		UtilityFunctions::displayImGuiComboBox("P-Mode", polygonModeModes, modeSelectionIndex);
		UtilityFunctions::displayImGuiComboBox("P-Flag", availableFlags, flagSelectionIndex);

		if (ImGui::Button("Set Polygon Mode")) {
			currentPolygonMode = new osg::PolygonMode;
			currentPolygonMode->setMode(selectionIdToPolygonModeFace[faceSelectionIndex], selectionIdToPolygonModeMode[modeSelectionIndex]);
			stateSetOfCurrentlySelectedNode->setAttribute(currentPolygonMode, selectionIdToStateAttributeFlag[flagSelectionIndex]);
		}

		ImGui::TreePop();
	}
}
