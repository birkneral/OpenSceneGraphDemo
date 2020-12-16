#include "Options\StateSetOptions\AdjustBlendFunctionOption.h"
#include <UtilityFunctions.h>

AdjustBlendFunctionOption::AdjustBlendFunctionOption()
{
	blendModeSelectionToGLenum[0] = GL_DST_ALPHA;
	blendModeSelectionToGLenum[1] = GL_DST_COLOR;
	blendModeSelectionToGLenum[2] = GL_ONE;
	blendModeSelectionToGLenum[3] = GL_ONE_MINUS_DST_ALPHA;
	blendModeSelectionToGLenum[4] = GL_ONE_MINUS_DST_COLOR;
	blendModeSelectionToGLenum[5] = GL_ONE_MINUS_SRC_ALPHA;
	blendModeSelectionToGLenum[6] = GL_ONE_MINUS_SRC_COLOR;
	blendModeSelectionToGLenum[7] = GL_SRC_ALPHA;
	blendModeSelectionToGLenum[8] = GL_SRC_ALPHA_SATURATE;
	blendModeSelectionToGLenum[9] = GL_CONSTANT_COLOR;
	blendModeSelectionToGLenum[10] = GL_ONE_MINUS_CONSTANT_COLOR;
	blendModeSelectionToGLenum[11] = GL_CONSTANT_ALPHA;
	blendModeSelectionToGLenum[12] = GL_ONE_MINUS_CONSTANT_ALPHA;
	blendModeSelectionToGLenum[13] = GL_ZERO;
}

void AdjustBlendFunctionOption::displayStateSetOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::TreeNode("Blend function")) {

		osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode = currentTreeGeneratorVisitor->selectedNode->getOrCreateStateSet();

		ImGui::Text("Currently used:");

		osg::StateAttribute::GLModeValue currentBlendModeValue = stateSetOfCurrentlySelectedNode->getMode(GL_BLEND);

		ImGui::Text("	State of mode GL_BLEND:");
		ImGui::SameLine();
		ImGui::Text(stateAttributeFlagToString[currentBlendModeValue].c_str());

		osg::ref_ptr<osg::BlendFunc> currentBlendFunction = dynamic_cast<osg::BlendFunc*>(stateSetOfCurrentlySelectedNode->getAttribute(osg::StateAttribute::BLENDFUNC));

		if (currentBlendFunction != NULL) {
			GLenum sourceMode = currentBlendFunction->getSource();
			GLenum destinationMode = currentBlendFunction->getDestination();

			ImGui::Text("	Source: ");
			ImGui::SameLine();
			ImGui::Text(glConstToStringMap[sourceMode].c_str());
			ImGui::Text("	Destination: ");
			ImGui::SameLine();
			ImGui::Text(glConstToStringMap[destinationMode].c_str());
		}
		else {
			ImGui::Text("	There is no blend function set for this node.");
		}

		ImGui::Text("Set blend function:");

		UtilityFunctions::displayImGuiComboBox("Source blend func", blendFuncSelection, sourceBlendFunctionSelectionIndex);

		UtilityFunctions::displayImGuiComboBox("Destination blend func", blendFuncSelection, destinationBlendFunctionSelectionIndex);

		UtilityFunctions::displayImGuiComboBox("B-Flag", availableFlags, flagSelectionIndex);

		UtilityFunctions::displayImGuiComboBox("B-On/Off", onOffSelections, modeOnOffSelectionIndex);

		if (ImGui::Button("Set blend func")) {
			currentBlendFunction = new osg::BlendFunc;
			currentBlendFunction->setFunction(blendModeSelectionToGLenum[sourceBlendFunctionSelectionIndex], blendModeSelectionToGLenum[destinationBlendFunctionSelectionIndex]);
			stateSetOfCurrentlySelectedNode->setAttributeAndModes(currentBlendFunction, selectionIdToStateAttributeFlag[flagSelectionIndex] | selectionIdToStateAttributeModeOnOff[modeOnOffSelectionIndex]);
		}

		ImGui::TreePop();
	}
}
