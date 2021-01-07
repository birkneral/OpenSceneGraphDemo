#include "Options\StateSetOptions\AdjustLightStateOption.h"
#include <UtilityFunctions.h>

AdjustLightStateOption::AdjustLightStateOption() : StateSetOption()
{
}

void AdjustLightStateOption::displayStateSetOption(osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode)
{
	if (ImGui::TreeNode("Lights")) {

		if (ImGui::TreeNode("Overall Lighting")) {


			osg::StateAttribute::GLModeValue currentLightingState = stateSetOfCurrentlySelectedNode->getMode(GL_LIGHTING);

			ImGui::Text("State of Mode GL_LIGHTING:");
			ImGui::SameLine();
			ImGui::Text(stateAttributeFlagToString[currentLightingState].c_str());

			UtilityFunctions::displayImGuiComboBox("L-Flag", availableFlags, lightingFlagSelectionIndex);

			UtilityFunctions::displayImGuiComboBox("L-On/Off", onOffSelections, lightingOnOffSelectionIndex);

			if (ImGui::Button("Set Lighting")) {
				stateSetOfCurrentlySelectedNode->setMode(GL_LIGHTING, selectionIdToStateAttributeFlag[lightingFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[lightingOnOffSelectionIndex]);
			}

			ImGui::TreePop();
		}

		if (ImGui::TreeNode("Single Lights")) {

			ImGui::Text("Current Light States:");

			int light0Value = GL_LIGHT0;

			for (int i = 0; i < 8; i++)
			{
				osg::StateAttribute::GLModeValue currentLightState = stateSetOfCurrentlySelectedNode->getMode(light0Value + i);

				std::string stateLabel = "	State of Mode GL_LIGHT";
				stateLabel.append(std::to_string(i).c_str());
				stateLabel.append(":");

				ImGui::Text(stateLabel.c_str());
				ImGui::SameLine();
				ImGui::Text(stateAttributeFlagToString[currentLightState].c_str());
			}

			ImGui::Text("Set Light States:");

			for (int i = 0; i < 8; i++)
			{

				std::string lightLabel = "Light";
				lightLabel.append(std::to_string(i).c_str());
				lightLabel.append(":");

				ImGui::Text(lightLabel.c_str());

				std::string lightFlagLabel = "L-Flag";
				lightFlagLabel.append(std::to_string(i).c_str());
				lightFlagLabel.append(":");

				UtilityFunctions::displayImGuiComboBox(lightFlagLabel, availableFlags, specificLightsFlagSelectionIndices[i]);

				std::string lightOnOffLabel = "L-OnOff";
				lightOnOffLabel.append(std::to_string(i).c_str());
				lightOnOffLabel.append(":");

				UtilityFunctions::displayImGuiComboBox(lightOnOffLabel, onOffSelections, specificLightsOnOffSelectionIndices[i]);

				std::string lightButtonLabel = "Set Light";
				lightButtonLabel.append(std::to_string(i).c_str());
				lightButtonLabel.append(":");

				if (ImGui::Button(lightButtonLabel.c_str())) {
					stateSetOfCurrentlySelectedNode->setMode(light0Value + i, selectionIdToStateAttributeFlag[specificLightsFlagSelectionIndices[i]] | selectionIdToStateAttributeModeOnOff[specificLightsOnOffSelectionIndices[i]]);
				}
			}
		}

		ImGui::TreePop();
	}
}
