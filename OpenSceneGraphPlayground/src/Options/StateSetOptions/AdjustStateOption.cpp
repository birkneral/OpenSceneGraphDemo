#include "Options\StateSetOptions\AdjustStateOption.h"
#include <osg\PolygonMode>
#include <osg\StateAttribute>
#include <osg\BlendFunc>
#include <osgDB\ReadFile>
#include <filesystem>
#include <iostream>
#include "Options\StateSetOptions\AdjustStateOption.h"

AdjustStateOption::AdjustStateOption()
{
	//vertexShaderFiles = collectFileNamesWithGivenEndingInDataDirectory(".vert");
	//fragmentShaderFiles = collectFileNamesWithGivenEndingInDataDirectory(".frag");
	//geometryShaderFiles = collectFileNamesWithGivenEndingInDataDirectory(".geom");
	//geometryShaderFiles.insert(geometryShaderFiles.begin(), " ");

	//glConstToStringMap[GL_POINT] = "GL_POINT";
	//glConstToStringMap[GL_LINE] = "GL_LINE";
	//glConstToStringMap[GL_FILL] = "GL_FILL";

	//glConstToStringMap[GL_DST_ALPHA] = "GL_DST_ALPHA";
	//glConstToStringMap[GL_DST_COLOR] = "GL_DST_COLOR";
	//glConstToStringMap[GL_ONE] = "GL_ONE";
	//glConstToStringMap[GL_ONE_MINUS_DST_ALPHA] = "GL_ONE_MINUS_DST_ALPHA";
	//glConstToStringMap[GL_ONE_MINUS_DST_COLOR] = "GL_ONE_MINUS_DST_COLOR";
	//glConstToStringMap[GL_ONE_MINUS_SRC_ALPHA] = "GL_ONE_MINUS_SRC_ALPHA";
	//glConstToStringMap[GL_ONE_MINUS_SRC_COLOR] = "GL_ONE_MINUS_SRC_COLOR";
	//glConstToStringMap[GL_SRC_ALPHA] = "GL_SRC_ALPHA";
	//glConstToStringMap[GL_SRC_ALPHA_SATURATE] = "GL_SRC_ALPHA_SATURATE";
	//glConstToStringMap[GL_SRC_COLOR] = "GL_SRC_COLOR";
	//glConstToStringMap[GL_CONSTANT_COLOR] = "GL_CONSTANT_COLOR";
	//glConstToStringMap[GL_ONE_MINUS_CONSTANT_COLOR] = "GL_ONE_MINUS_CONSTANT_COLOR";
	//glConstToStringMap[GL_CONSTANT_ALPHA] = "GL_CONSTANT_ALPHA";
	//glConstToStringMap[GL_ONE_MINUS_CONSTANT_ALPHA] = "GL_ONE_MINUS_CONSTANT_ALPHA";
	//glConstToStringMap[GL_ZERO] = "GL_ZERO";

	//glConstToStringMap[GL_FLOAT] = "GL_Float";
	//glConstToStringMap[GL_FLOAT_VEC2] = "GL_FLOAT_VEC2";
	//glConstToStringMap[GL_FLOAT_VEC3] = "GL_FLOAT_VEC3";
	//glConstToStringMap[GL_FLOAT_VEC4] = "GL_FLOAT_VEC4";
	//glConstToStringMap[GL_INT] = "GL_INT";
	//glConstToStringMap[GL_UNSIGNED_INT] = "GL_UNSIGNED_INT";
	//glConstToStringMap[GL_FLOAT_MAT2] = "GL_FLOAT_MAT2";
	//glConstToStringMap[GL_FLOAT_MAT3] = "GL_FLOAT_MAT3";
	//glConstToStringMap[GL_FLOAT_MAT4] = "GL_FLOAT_MAT4";

	//blendModeSelectionToGLenum[0] = GL_DST_ALPHA;
	//blendModeSelectionToGLenum[1] = GL_DST_COLOR;
	//blendModeSelectionToGLenum[2] = GL_ONE;
	//blendModeSelectionToGLenum[3] = GL_ONE_MINUS_DST_ALPHA;
	//blendModeSelectionToGLenum[4] = GL_ONE_MINUS_DST_COLOR;
	//blendModeSelectionToGLenum[5] = GL_ONE_MINUS_SRC_ALPHA;
	//blendModeSelectionToGLenum[6] = GL_ONE_MINUS_SRC_COLOR;
	//blendModeSelectionToGLenum[7] = GL_SRC_ALPHA;
	//blendModeSelectionToGLenum[8] = GL_SRC_ALPHA_SATURATE;
	//blendModeSelectionToGLenum[9] = GL_CONSTANT_COLOR;
	//blendModeSelectionToGLenum[10] = GL_ONE_MINUS_CONSTANT_COLOR;
	//blendModeSelectionToGLenum[11] = GL_CONSTANT_ALPHA;
	//blendModeSelectionToGLenum[12] = GL_ONE_MINUS_CONSTANT_ALPHA;
	//blendModeSelectionToGLenum[13] = GL_ZERO;

	//renderingHintToString[0] = "Default";
	//renderingHintToString[1] = "Opaque";
	//renderingHintToString[2] = "Transparent";

	//selectionIdToRenderingHint[0] = osg::StateSet::RenderingHint::DEFAULT_BIN;
	//selectionIdToRenderingHint[1] = osg::StateSet::RenderingHint::OPAQUE_BIN;
	//selectionIdToRenderingHint[2] = osg::StateSet::RenderingHint::TRANSPARENT_BIN;

	//selectionIdToStateAttributeFlag[0] = osg::StateAttribute::Values::OVERRIDE;
	//selectionIdToStateAttributeFlag[1] = osg::StateAttribute::Values::PROTECTED;
	//selectionIdToStateAttributeFlag[2] = osg::StateAttribute::Values::INHERIT;

	//selectionIdToStateAttributeModeOnOff[0] = osg::StateAttribute::Values::ON;
	//selectionIdToStateAttributeModeOnOff[1] = osg::StateAttribute::Values::OFF;

	//selectionIdToPolygonModeFace[0] = osg::PolygonMode::Face::FRONT;
	//selectionIdToPolygonModeFace[1] = osg::PolygonMode::Face::BACK;
	//selectionIdToPolygonModeFace[2] = osg::PolygonMode::Face::FRONT_AND_BACK;

	//selectionIdToPolygonModeMode[0] = osg::PolygonMode::Mode::POINT;
	//selectionIdToPolygonModeMode[1] = osg::PolygonMode::Mode::LINE;
	//selectionIdToPolygonModeMode[2] = osg::PolygonMode::Mode::FILL;

	//stateAttributeFlagToString[osg::StateAttribute::ON] = "ON";
	//stateAttributeFlagToString[osg::StateAttribute::OFF] = "OFF";
	//stateAttributeFlagToString[osg::StateAttribute::OVERRIDE] = "OVERIDE";
	//stateAttributeFlagToString[osg::StateAttribute::ON + osg::StateAttribute::OVERRIDE] = "ON + OVERIDE";
	//stateAttributeFlagToString[osg::StateAttribute::PROTECTED] = "PROTECTED";
	//stateAttributeFlagToString[osg::StateAttribute::ON + osg::StateAttribute::PROTECTED] = "ON + PROTECTED";
	//stateAttributeFlagToString[osg::StateAttribute::INHERIT] = "INHERIT";
	//stateAttributeFlagToString[osg::StateAttribute::ON + osg::StateAttribute::INHERIT] = "ON + INHERIT";

}

void AdjustStateOption::displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::TreeNode("Adjust State")) {

		if (currentTreeGeneratorVisitor->selectedNode != NULL) {

			adjustPolygonModeOption.displayStateSetOption(currentTreeGeneratorVisitor);
			adjustRenderingHintOption.displayStateSetOption(currentTreeGeneratorVisitor);
			adjustBlendFunctionOption.displayStateSetOption(currentTreeGeneratorVisitor);
			adjustLightStateOption.displayStateSetOption(currentTreeGeneratorVisitor);
			addShaderOption.displayStateSetOption(currentTreeGeneratorVisitor);
		}
		else {
			ImGui::Text("Please select node.");
		}

		ImGui::TreePop();
	}
}

//void AdjustStateOption::displayPolygonModeOption(osg::ref_ptr<osg::StateSet> currentStateSet)
//{
//
//	if (ImGui::TreeNode("Polygon mode")) {
//
//		//ImGui::Text("Associated mode: ");
//		//ImGui::SameLine();
//		////This info is from table on p. 201 of OpenSceneGraph 3.0 Beginner´s Guide
//		//ImGui::Text("None");
//
//		ImGui::Text("Currently used:");
//
//		osg::ref_ptr<osg::PolygonMode> currentPolygonMode = dynamic_cast<osg::PolygonMode*>(currentStateSet->getAttribute(osg::StateAttribute::POLYGONMODE));
//
//		if (currentPolygonMode != NULL) {
//			osg::PolygonMode::Mode frontMode = currentPolygonMode->getMode(osg::PolygonMode::Face::FRONT);
//			osg::PolygonMode::Mode backMode = currentPolygonMode->getMode(osg::PolygonMode::Face::BACK);
//
//			ImGui::Text("	Front: ");
//			ImGui::SameLine();
//			ImGui::Text(glConstToStringMap[frontMode].c_str());
//			ImGui::Text("	Back: ");
//			ImGui::SameLine();
//			ImGui::Text(glConstToStringMap[backMode].c_str());
//		}
//		else {
//			ImGui::Text("	Polygon mode is not set for this node.");
//		}
//
//		ImGui::Text("Set polygon mode:");
//
//		const char* polygonModeFaces[] = { "FRONT", "BACK", "FRONT_AND_BACK" };
//		const char* polygonModeModes[] = { "GL_POINT", "GL_LINE", "GL_FILL" };
//		const char* stateAttributeFlags[] = { "OVERRIDE", "PROTECTED", "INHERITAT" };
//
//		const char* comboLabelFace = polygonModeFaces[polygonModeFaceSelectionIndex];  // Label to preview before opening the combo (technically could be anything)(
//		if (ImGui::BeginCombo("P-Face", comboLabelFace)) {
//			for (int n = 0; n < IM_ARRAYSIZE(polygonModeFaces); n++)
//			{
//				const bool is_selected = (polygonModeFaceSelectionIndex == n);
//				if (ImGui::Selectable(polygonModeFaces[n], is_selected))
//					polygonModeFaceSelectionIndex = n;
//
//				if (is_selected)
//					ImGui::SetItemDefaultFocus();
//			}
//			ImGui::EndCombo();
//		}
//
//		const char* comboLabelMode = polygonModeModes[polygonModeModeSelectionIndex];  // Label to preview before opening the combo (technically could be anything)(
//		if (ImGui::BeginCombo("P-Mode", comboLabelMode)) {
//			for (int n = 0; n < IM_ARRAYSIZE(polygonModeModes); n++)
//			{
//				const bool is_selected = (polygonModeModeSelectionIndex == n);
//				if (ImGui::Selectable(polygonModeModes[n], is_selected))
//					polygonModeModeSelectionIndex = n;
//
//				if (is_selected)
//					ImGui::SetItemDefaultFocus();
//			}
//			ImGui::EndCombo();
//		}
//
//		const char* comboLabelStateAttributeFlag = stateAttributeFlags[polygonModeFlagSelectionIndex];  // Label to preview before opening the combo (technically could be anything)(
//		if (ImGui::BeginCombo("P-Flag", comboLabelStateAttributeFlag)) {
//			for (int n = 0; n < IM_ARRAYSIZE(stateAttributeFlags); n++)
//			{
//				const bool is_selected = (polygonModeFlagSelectionIndex == n);
//				if (ImGui::Selectable(stateAttributeFlags[n], is_selected))
//					polygonModeFlagSelectionIndex = n;
//
//				if (is_selected)
//					ImGui::SetItemDefaultFocus();
//			}
//			ImGui::EndCombo();
//		}
//
//		if (ImGui::Button("Set Polygon mode")) {
//			currentPolygonMode = new osg::PolygonMode;
//			currentPolygonMode->setMode(selectionIdToPolygonModeFace[polygonModeFaceSelectionIndex], selectionIdToPolygonModeMode[polygonModeModeSelectionIndex]);
//			currentStateSet->setAttribute(currentPolygonMode, selectionIdToStateAttributeFlag[polygonModeFlagSelectionIndex]);
//		}
//
//		ImGui::TreePop();
//	}
//}
//
//void AdjustStateOption::displayRenderingHintOption(osg::ref_ptr<osg::StateSet> currentStateSet) {
//
//	if (ImGui::TreeNode("Rendering hint")) {
//
//		ImGui::Text("Currently used:");
//
//		int currentRenderingHint = currentStateSet->getRenderingHint();
//
//		ImGui::Text("	");
//		ImGui::SameLine();
//		ImGui::Text(renderingHintToString[currentRenderingHint].c_str());
//
//		ImGui::Text("Set rendering hint:");
//		const char* renderingHintOptions[] = { "Default", "Opaque", "Transparent" };
//		const char* comboLabelRenderingHint = renderingHintOptions[renderingHintSelection];  // Label to preview before opening the combo (technically could be anything)(
//		if (ImGui::BeginCombo("Rendering hint", comboLabelRenderingHint)) {
//			for (int n = 0; n < IM_ARRAYSIZE(renderingHintOptions); n++)
//			{
//				const bool is_selected = (renderingHintSelection == n);
//				if (ImGui::Selectable(renderingHintOptions[n], is_selected))
//					renderingHintSelection = n;
//
//				if (is_selected)
//					ImGui::SetItemDefaultFocus();
//			}
//			ImGui::EndCombo();
//		}
//
//		if (ImGui::Button("Set rendering hint")) {
//			currentStateSet->setRenderingHint(selectionIdToRenderingHint[renderingHintSelection]);
//		}
//
//		ImGui::TreePop();
//	}
//	
//}
//
//void AdjustStateOption::displayBlendFuncOption(osg::ref_ptr<osg::StateSet> currentStateSet)
//{
//	if (ImGui::TreeNode("Blend function")) {
//
//		ImGui::Text("Currently used:");
//
//		osg::StateAttribute::GLModeValue currentBlendModeValue = currentStateSet->getMode(GL_BLEND);
//
//		ImGui::Text("	State of mode GL_BLEND:");
//		ImGui::SameLine();
//		ImGui::Text(stateAttributeFlagToString[currentBlendModeValue].c_str());
//
//		osg::ref_ptr<osg::BlendFunc> currentBlendFunction = dynamic_cast<osg::BlendFunc*>(currentStateSet->getAttribute(osg::StateAttribute::BLENDFUNC));
//
//
//		if (currentBlendFunction != NULL) {
//			GLenum sourceMode = currentBlendFunction->getSource();
//			GLenum destinationMode = currentBlendFunction->getDestination();
//
//			ImGui::Text("	Source: ");
//			ImGui::SameLine();
//			ImGui::Text(glConstToStringMap[sourceMode].c_str());
//			ImGui::Text("	Destination: ");
//			ImGui::SameLine();
//			ImGui::Text(glConstToStringMap[destinationMode].c_str());
//		}
//		else {
//			ImGui::Text("	There is no blend function set for this node.");
//		}
//
//		ImGui::Text("Set blend function:");
//
//		const char* blendFuncOptions[] = { "GL_DST_ALPHA", "GL_DST_COLOR", "GL_ONE", "GL_ONE_MINUS_DST_ALPHA",
//										   "GL_ONE_MINUS_DST_COLOR", "GL_ONE_MINUS_SRC_ALPHA", "GL_ONE_MINUS_SRC_COLOR", "GL_SRC_ALPHA",
//										   "GL_SRC_ALPHA_SATURATE", "GL_SRC_COLOR", "GL_CONSTANT_COLOR", "GL_ONE_MINUS_CONSTANT_COLOR",
//										   "GL_CONSTANT_ALPHA", "GL_ONE_MINUS_CONSTANT_ALPHA", "GL_ZERO",
//										 };
//
//		const char* comboLabelSourceBlendFunction = blendFuncOptions[sourceBlendFunctionSelectionIndex];  // Label to preview before opening the combo (technically could be anything)(
//		if (ImGui::BeginCombo("Source blend func", comboLabelSourceBlendFunction)) {
//			for (int n = 0; n < IM_ARRAYSIZE(blendFuncOptions); n++)
//			{
//				const bool is_selected = (sourceBlendFunctionSelectionIndex == n);
//				if (ImGui::Selectable(blendFuncOptions[n], is_selected))
//					sourceBlendFunctionSelectionIndex = n;
//
//				if (is_selected)
//					ImGui::SetItemDefaultFocus();
//			}
//			ImGui::EndCombo();
//		}
//
//		const char* comboLabelDestinationBlendFunction = blendFuncOptions[destinationBlendFunctionSelectionIndex];  // Label to preview before opening the combo (technically could be anything)(
//		if (ImGui::BeginCombo("Dest blend func", comboLabelDestinationBlendFunction)) {
//			for (int n = 0; n < IM_ARRAYSIZE(blendFuncOptions); n++)
//			{
//				const bool is_selected = (destinationBlendFunctionSelectionIndex == n);
//				if (ImGui::Selectable(blendFuncOptions[n], is_selected))
//					destinationBlendFunctionSelectionIndex = n;
//
//				if (is_selected)
//					ImGui::SetItemDefaultFocus();
//			}
//			ImGui::EndCombo();
//		}
//
//
//		const char* stateAttributeFlags[] = { "OVERRIDE", "PROTECTED", "INHERITAT" };
//		const char* comboLabelStateAttributeFlag = stateAttributeFlags[stateAttributeBlendFuncFlagSelectionIndex];  // Label to preview before opening the combo (technically could be anything)(
//		if (ImGui::BeginCombo("B-Flag", comboLabelStateAttributeFlag)) {
//			for (int n = 0; n < IM_ARRAYSIZE(stateAttributeFlags); n++)
//			{
//				const bool is_selected = (stateAttributeBlendFuncFlagSelectionIndex == n);
//				if (ImGui::Selectable(stateAttributeFlags[n], is_selected))
//					stateAttributeBlendFuncFlagSelectionIndex = n;
//
//				if (is_selected)
//					ImGui::SetItemDefaultFocus();
//			}
//			ImGui::EndCombo();
//		}
//
//		const char* stateAttributeOnOffs[] = { "ON", "OFF" };
//		const char* comboLabelStateBlendOnOff = stateAttributeOnOffs[stateAttributeBlendOnOffSelectionIndex];  // Label to preview before opening the combo (technically could be anything)(
//		if (ImGui::BeginCombo("B-On/Off", comboLabelStateBlendOnOff)) {
//			for (int n = 0; n < IM_ARRAYSIZE(stateAttributeOnOffs); n++)
//			{
//				const bool is_selected = (stateAttributeBlendOnOffSelectionIndex == n);
//				if (ImGui::Selectable(stateAttributeOnOffs[n], is_selected))
//					stateAttributeBlendOnOffSelectionIndex = n;
//
//				if (is_selected)
//					ImGui::SetItemDefaultFocus();
//			}
//			ImGui::EndCombo();
//		}
//
//
//		if (ImGui::Button("Set blend func")) {
//			currentBlendFunction = new osg::BlendFunc;
//			currentBlendFunction->setFunction(blendModeSelectionToGLenum[sourceBlendFunctionSelectionIndex], blendModeSelectionToGLenum[destinationBlendFunctionSelectionIndex]);
//			currentStateSet->setAttributeAndModes(currentBlendFunction, selectionIdToStateAttributeFlag[stateAttributeBlendFuncFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[stateAttributeBlendOnOffSelectionIndex]);
//		}
//
//		ImGui::TreePop();
//	}
//}
//
//void AdjustStateOption::displayLightOption(osg::ref_ptr<osg::StateSet> stateSetOfSelectedNode)
//{
//	if (ImGui::TreeNode("Lights")) {
//
//		if (ImGui::TreeNode("Overall Lighting")) {
//			
//			osg::StateAttribute::GLModeValue currentLightingState = stateSetOfSelectedNode->getMode(GL_LIGHTING);
//
//			ImGui::Text("State of mode GL_LIGHTING:");
//			ImGui::SameLine();
//			ImGui::Text(stateAttributeFlagToString[currentLightingState].c_str());
//
//			const char* stateAttributeFlags[] = { "OVERRIDE", "PROTECTED", "INHERITAT" };
//			const char* comboLabelStateAttributeFlag = stateAttributeFlags[stateAttributeLightingFlagSelection];  // Label to preview before opening the combo (technically could be anything)(
//			if (ImGui::BeginCombo("L-Flag", comboLabelStateAttributeFlag)) {
//				for (int n = 0; n < IM_ARRAYSIZE(stateAttributeFlags); n++)
//				{
//					const bool is_selected = (stateAttributeLightingFlagSelection == n);
//					if (ImGui::Selectable(stateAttributeFlags[n], is_selected))
//						stateAttributeLightingFlagSelection = n;
//
//					if (is_selected)
//						ImGui::SetItemDefaultFocus();
//				}
//				ImGui::EndCombo();
//			}
//
//			const char* stateAttributeOnOffs[] = { "ON", "OFF" };
//			const char* comboLabelStateBlendOnOff = stateAttributeOnOffs[stateAttributeLightingOnOffSelection];  // Label to preview before opening the combo (technically could be anything)(
//			if (ImGui::BeginCombo("B-On/Off", comboLabelStateBlendOnOff)) {
//				for (int n = 0; n < IM_ARRAYSIZE(stateAttributeOnOffs); n++)
//				{
//					const bool is_selected = (stateAttributeLightingOnOffSelection == n);
//					if (ImGui::Selectable(stateAttributeOnOffs[n], is_selected))
//						stateAttributeLightingOnOffSelection = n;
//
//					if (is_selected)
//						ImGui::SetItemDefaultFocus();
//				}
//				ImGui::EndCombo();
//			}
//
//			if (ImGui::Button("Set Lighting")) {
//				stateSetOfSelectedNode->setMode(GL_LIGHTING, selectionIdToStateAttributeFlag[stateAttributeLightingFlagSelection] | selectionIdToStateAttributeModeOnOff[stateAttributeLightingOnOffSelection]);
//			}
//
//
//			ImGui::TreePop();
//		}
//
//		if (ImGui::TreeNode("Single lights")) {
//
//			ImGui::Text("Current light states:");
//
//			int light0Value = GL_LIGHT0;
//
//			for (int i = 0; i < 8; i++)
//			{
//				osg::StateAttribute::GLModeValue currentLightState = stateSetOfSelectedNode->getMode(light0Value + i);
//
//				std::string stateLabel = "	State of mode GL_LIGHT";
//				stateLabel.append(std::to_string(i).c_str());
//				stateLabel.append(":");
//
//				ImGui::Text(stateLabel.c_str());
//				ImGui::SameLine();
//				ImGui::Text(stateAttributeFlagToString[currentLightState].c_str());
//			}
//
//			ImGui::Text("Set light states:");
//
//			for (int i = 0; i < 8; i++)
//			{
//
//				std::string lightLabel = "Light";
//				lightLabel.append(std::to_string(i).c_str());
//				lightLabel.append(":");
//
//				ImGui::Text(lightLabel.c_str());
//
//				const char* stateAttributeFlags[] = { "OVERRIDE", "PROTECTED", "INHERITAT" };
//				const char* comboLabelStateAttributeFlag = stateAttributeFlags[stateAttributeLightsFlagSelection[i]];
//
//				std::string lightFlagLabel = "L-Flag";
//				lightFlagLabel.append(std::to_string(i).c_str());
//				lightFlagLabel.append(":");
//
//				if (ImGui::BeginCombo(lightFlagLabel.c_str(), comboLabelStateAttributeFlag)) {
//					for (int n = 0; n < IM_ARRAYSIZE(stateAttributeFlags); n++)
//					{
//						const bool is_selected = (stateAttributeLightsFlagSelection[i] == n);
//						if (ImGui::Selectable(stateAttributeFlags[n], is_selected))
//							stateAttributeLightsFlagSelection[i] = n;
//
//						if (is_selected)
//							ImGui::SetItemDefaultFocus();
//					}
//					ImGui::EndCombo();
//				}
//
//				std::string lightOnOffLabel = "L-OnOff";
//				lightOnOffLabel.append(std::to_string(i).c_str());
//				lightOnOffLabel.append(":");
//
//
//				const char* stateAttributeOnOffs[] = { "ON", "OFF" };
//				const char* comboLabelStateBlendOnOff = stateAttributeOnOffs[stateAttributeLightsOnOffSelection[i]];
//				if (ImGui::BeginCombo(lightOnOffLabel.c_str(), comboLabelStateBlendOnOff)) {
//					for (int n = 0; n < IM_ARRAYSIZE(stateAttributeOnOffs); n++)
//					{
//						const bool is_selected = (stateAttributeLightsOnOffSelection[i] == n);
//						if (ImGui::Selectable(stateAttributeOnOffs[n], is_selected))
//							stateAttributeLightsOnOffSelection[i] = n;
//
//						if (is_selected)
//							ImGui::SetItemDefaultFocus();
//					}
//					ImGui::EndCombo();
//				}
//
//				std::string lightButtonLabel = "Set Light";
//				lightButtonLabel.append(std::to_string(i).c_str());
//				lightButtonLabel.append(":");
//
//				if (ImGui::Button(lightButtonLabel.c_str())) {
//					stateSetOfSelectedNode->setMode(light0Value + i, selectionIdToStateAttributeFlag[stateAttributeLightsFlagSelection[i]] | selectionIdToStateAttributeModeOnOff[stateAttributeLightsOnOffSelection[i]]);
//				}
//			}
//		}
//	
//		ImGui::TreePop();
//	}
//}
//
//void AdjustStateOption::displayAddShaderOption(osg::ref_ptr<osg::StateSet> currentStateSet)
//{
//	if (ImGui::TreeNode("Add use of a shader")) {
//
//		if (ImGui::TreeNode("Uniforms")) {
//			osg::StateSet::UniformList currentUniforms = currentStateSet->getUniformList();
//
//			if (ImGui::TreeNode("Current uniforms")) {
//				for (const auto& [unifromName, uniformToFlagPair] : currentUniforms) {
//					ImGui::Text("	Name:");
//					ImGui::SameLine();
//					ImGui::Text(unifromName.c_str());
//					ImGui::Text("	Datatype:");
//					ImGui::SameLine();
//					osg::ref_ptr<osg::Uniform> uniform = uniformToFlagPair.first;
//					osg::Uniform::Type uniformType = uniform->getType();
//					ImGui::Text(glConstToStringMap[uniformType].c_str());
//					ImGui::Text("	Flag:");
//					ImGui::SameLine();
//					ImGui::Text(stateAttributeFlagToString[uniformToFlagPair.second].c_str());
//					if (ImGui::Button("Remove uniform")) {
//						currentStateSet->removeUniform(uniform);
//					}
//				}
//				ImGui::TreePop();
//			}
//
//			if (ImGui::TreeNode("Add uniform")) {
//
//				const char* uniformTypes[] = {
//					"GL_Float", "GL_FLOAT_VEC2", "GL_FLOAT_VEC3", "GL_FLOAT_VEC4",
//					"GL_INT", "GL_FLOAT_MAT2", "GL_FLOAT_MAT3", "GL_FLOAT_MAT4",
//				};
//
//				const char* stateAttributeFlags[] = { "OVERRIDE", "PROTECTED", "INHERITAT" };
//				const char* comboLabelStateAttributeFlag = stateAttributeFlags[uniformFlagSelectionIndex];  // Label to preview before opening the combo (technically could be anything)(
//				if (ImGui::BeginCombo("B-Flag", comboLabelStateAttributeFlag)) {
//					for (int n = 0; n < IM_ARRAYSIZE(stateAttributeFlags); n++)
//					{
//						const bool is_selected = (uniformFlagSelectionIndex == n);
//						if (ImGui::Selectable(stateAttributeFlags[n], is_selected))
//							uniformFlagSelectionIndex = n;
//
//						if (is_selected)
//							ImGui::SetItemDefaultFocus();
//					}
//					ImGui::EndCombo();
//				}
//
//				if (ImGui::BeginCombo("Uniform type", uniformTypes[uniformTypeSelectionIndex])) {
//					for (int n = 0; n < IM_ARRAYSIZE(uniformTypes); n++)
//					{
//						const bool is_selected = (uniformTypeSelectionIndex == n);
//						if (ImGui::Selectable(uniformTypes[n], is_selected))
//							uniformTypeSelectionIndex = n;
//
//						if (is_selected)
//							ImGui::SetItemDefaultFocus();
//					}
//					ImGui::EndCombo();
//				}
//
//				ImGui::InputText("Uniform name", uniformNameInput, IM_ARRAYSIZE(uniformNameInput));
//				std::string cleanedUniformName = uniformNameInput;
//				cleanedUniformName.erase(remove(cleanedUniformName.begin(), cleanedUniformName.end(), ' '), cleanedUniformName.end());
//
//				if (uniformTypeSelectionIndex == 0) {
//					ImGui::InputFloat("Float Value", &uniformInputFloat);
//
//					if (ImGui::Button("Add Float Uniform")) {
//						osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(), uniformInputFloat);
//						currentStateSet->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex]);
//					}
//				}
//
//				if (uniformTypeSelectionIndex == 1) {
//					ImGui::InputFloat2("Float Vec2 Value", uniformFloatTwoInput);
//
//					if (ImGui::Button("Add Float Vec2 Uniform")) {
//						osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(), osg::Vec2(uniformFloatTwoInput[0], uniformFloatTwoInput[1]));
//						currentStateSet->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[stateAttributeLightsOnOffSelection[uniformOnOffSelectionIndex]]);
//					}
//				}
//
//				if (uniformTypeSelectionIndex == 2) {
//					ImGui::InputFloat3("Float Vec3 Value", uniformFloatThreeInput);
//
//					if (ImGui::Button("Add Float Vec3 Uniform")) {
//						osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(), osg::Vec3(uniformFloatThreeInput[0], uniformFloatThreeInput[1], uniformFloatThreeInput[2]));
//						currentStateSet->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[stateAttributeLightsOnOffSelection[uniformOnOffSelectionIndex]]);
//					}
//				}
//
//				if (uniformTypeSelectionIndex == 3) {
//					ImGui::InputFloat4("Float Vec4 Value", uniformFloatFourInput);
//
//					if (ImGui::Button("Add Float Vec4 Uniform")) {
//						osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(), osg::Vec4(uniformFloatFourInput[0], uniformFloatFourInput[1], uniformFloatFourInput[2], uniformFloatFourInput[3]));
//						currentStateSet->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[stateAttributeLightsOnOffSelection[uniformOnOffSelectionIndex]]);
//					}
//				}
//
//				if (uniformTypeSelectionIndex == 4) {
//					ImGui::InputInt("Int Value", &uniformInputInt);
//
//					if (ImGui::Button("Add Int Uniform")) {
//						osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(), uniformInputInt);
//						currentStateSet->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[stateAttributeLightsOnOffSelection[uniformOnOffSelectionIndex]]);
//					}
//				}
//
//				if (uniformTypeSelectionIndex == 5) {
//					ImGui::InputFloat2("Mat2 Row1", uniformFloatMatTwoRowOneInput);
//					ImGui::InputFloat2("Mat2 Row2", uniformFloatMatTwoRowTwoInput);
//
//					if (ImGui::Button("Add Mat2 Uniform")) {
//						osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(),
//							osg::Matrix2(uniformFloatMatTwoRowOneInput[0], uniformFloatMatTwoRowOneInput[1],
//								uniformFloatMatTwoRowTwoInput[0], uniformFloatMatTwoRowTwoInput[1]));
//						currentStateSet->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[stateAttributeLightsOnOffSelection[uniformOnOffSelectionIndex]]);
//					}
//				}
//
//				if (uniformTypeSelectionIndex == 6) {
//					ImGui::InputFloat3("Mat3 Row1", uniformFloatMatThreeRowOneInput);
//					ImGui::InputFloat3("Mat3 Row2", uniformFloatMatThreeRowTwoInput);
//					ImGui::InputFloat3("Mat3 Row3", uniformFloatMatThreeRowThreeInput);
//
//					if (ImGui::Button("Add Mat3 Uniform")) {
//						osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(),
//							osg::Matrix3(uniformFloatMatThreeRowOneInput[0], uniformFloatMatThreeRowOneInput[1], uniformFloatMatThreeRowOneInput[2],
//								uniformFloatMatThreeRowTwoInput[0], uniformFloatMatThreeRowTwoInput[1], uniformFloatMatThreeRowTwoInput[2],
//								uniformFloatMatThreeRowThreeInput[0], uniformFloatMatThreeRowThreeInput[1], uniformFloatMatThreeRowThreeInput[2]));
//						currentStateSet->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[stateAttributeLightsOnOffSelection[uniformOnOffSelectionIndex]]);
//					}
//				}
//
//				if (uniformTypeSelectionIndex == 7) {
//					ImGui::InputFloat4("Mat4 Row1", uniformFloatMatFourRowOneInput);
//					ImGui::InputFloat4("Mat4 Row2", uniformFloatMatFourRowTwoInput);
//					ImGui::InputFloat4("Mat4 Row3", uniformFloatMatFourRowThreeInput);
//					ImGui::InputFloat4("Mat4 Row4", uniformFloatMatFourRowFourInput);
//
//					if (ImGui::Button("Add Mat4 Uniform")) {
//						osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(),
//							osg::Matrixf(uniformFloatMatFourRowOneInput[0], uniformFloatMatFourRowOneInput[1], uniformFloatMatFourRowOneInput[2], uniformFloatMatFourRowOneInput[3],
//								uniformFloatMatFourRowTwoInput[0], uniformFloatMatFourRowTwoInput[1], uniformFloatMatFourRowTwoInput[2], uniformFloatMatFourRowTwoInput[3],
//								uniformFloatMatFourRowThreeInput[0], uniformFloatMatFourRowThreeInput[1], uniformFloatMatFourRowThreeInput[2], uniformFloatMatFourRowThreeInput[3],
//								uniformFloatMatFourRowFourInput[0], uniformFloatMatFourRowFourInput[1], uniformFloatMatFourRowFourInput[2], uniformFloatMatFourRowFourInput[3]));
//						currentStateSet->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[stateAttributeLightsOnOffSelection[uniformOnOffSelectionIndex]]);
//					}
//				}
//
//				ImGui::TreePop();
//			}
//			ImGui::TreePop();
//		}
//
//		if (vertexShaderFiles.size() > 0 && fragmentShaderFiles.size() > 0) {
//			if (ImGui::TreeNode("Shader")) {
//				const char* vertexShaderComboLabel = vertexShaderFiles[vertexShaderFileSelectionIndex].c_str();  // Label to preview before opening the combo (technically could be anything)(
//				if (ImGui::BeginCombo("Vertex shader to add", vertexShaderComboLabel))
//				{
//					for (int n = 0; n < vertexShaderFiles.size(); n++)
//					{
//						const bool is_selected = (vertexShaderFileSelectionIndex == n);
//						if (ImGui::Selectable(vertexShaderFiles[n].c_str(), is_selected))
//							vertexShaderFileSelectionIndex = n;
//
//						// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
//						if (is_selected)
//							ImGui::SetItemDefaultFocus();
//					}
//					ImGui::EndCombo();
//				}
//
//				const char* fragmetShaderComboLabel = fragmentShaderFiles[fragmetShaderFileSelectionIndex].c_str();  // Label to preview before opening the combo (technically could be anything)(
//				if (ImGui::BeginCombo("Fragment shader to add", fragmetShaderComboLabel))
//				{
//					for (int n = 0; n < fragmentShaderFiles.size(); n++)
//					{
//						const bool is_selected = (fragmetShaderFileSelectionIndex == n);
//						if (ImGui::Selectable(fragmentShaderFiles[n].c_str(), is_selected))
//							fragmetShaderFileSelectionIndex = n;
//
//						// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
//						if (is_selected)
//							ImGui::SetItemDefaultFocus();
//					}
//					ImGui::EndCombo();
//				}
//
//				const char* geometryShaderComboLabel = geometryShaderFiles[geometryShaderFileSelectionIndex].c_str();  // Label to preview before opening the combo (technically could be anything)(
//				if (ImGui::BeginCombo("File to add", geometryShaderComboLabel))
//				{
//					for (int n = 0; n < geometryShaderFiles.size(); n++)
//					{
//						const bool is_selected = (geometryShaderFileSelectionIndex == n);
//						if (ImGui::Selectable(geometryShaderFiles[n].c_str(), is_selected))
//							geometryShaderFileSelectionIndex = n;
//
//						// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
//						if (is_selected)
//							ImGui::SetItemDefaultFocus();
//					}
//					ImGui::EndCombo();
//				}
//
//				const char* stateAttributeFlags[] = { "OVERRIDE", "PROTECTED", "INHERITAT" };
//				const char* comboLabelStateAttributeFlag = stateAttributeFlags[shaderFlagSelectionIndex];  // Label to preview before opening the combo (technically could be anything)(
//				if (ImGui::BeginCombo("Sh-Flag", comboLabelStateAttributeFlag)) {
//					for (int n = 0; n < IM_ARRAYSIZE(stateAttributeFlags); n++)
//					{
//						const bool is_selected = (shaderFlagSelectionIndex == n);
//						if (ImGui::Selectable(stateAttributeFlags[n], is_selected))
//							shaderFlagSelectionIndex = n;
//
//						if (is_selected)
//							ImGui::SetItemDefaultFocus();
//					}
//					ImGui::EndCombo();
//				}
//
//				const char* stateAttributeOnOffs[] = { "ON", "OFF" };
//				const char* comboLabelStateBlendOnOff = stateAttributeOnOffs[shaderOnOffSelectionIndex];  // Label to preview before opening the combo (technically could be anything)(
//				if (ImGui::BeginCombo("Sh-On/Off", comboLabelStateBlendOnOff)) {
//					for (int n = 0; n < IM_ARRAYSIZE(stateAttributeOnOffs); n++)
//					{
//						const bool is_selected = (shaderOnOffSelectionIndex == n);
//						if (ImGui::Selectable(stateAttributeOnOffs[n], is_selected))
//							shaderOnOffSelectionIndex = n;
//
//						if (is_selected)
//							ImGui::SetItemDefaultFocus();
//					}
//					ImGui::EndCombo();
//				}
//
//				if (ImGui::Button("Add program with selected shader")) {
//					osg::ref_ptr<osg::Program> program = new osg::Program;
//					osg::ref_ptr<osg::Shader> vertexShader = osgDB::readShaderFile(pathToShaderDirectory + vertexShaderFiles[vertexShaderFileSelectionIndex]);
//					osg::ref_ptr<osg::Shader> fragmentShader = osgDB::readShaderFile(pathToShaderDirectory + fragmentShaderFiles[fragmetShaderFileSelectionIndex]);
//					program->addShader(vertexShader.get());
//					program->addShader(fragmentShader.get());
//
//					if (geometryShaderFileSelectionIndex != 0) {
//						osg::ref_ptr<osg::Shader> geometryShader = osgDB::readShaderFile(vertexShaderFiles[vertexShaderFileSelectionIndex]);
//						program->addShader(geometryShader.get());
//					}
//
//					currentStateSet->setAttributeAndModes(program, selectionIdToStateAttributeFlag[shaderFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[shaderOnOffSelectionIndex]);
//				}
//				ImGui::TreePop();
//			}
//		}
//		else {
//			ImGui::Text("Please put at least one vertex (.vert)");
//			ImGui::Text("and one fragmet (.frag) shader file in the data directory.");
//		}
//		ImGui::TreePop();
//	}
//}
//
//std::vector<std::string> AdjustStateOption::collectFileNamesWithGivenEndingInDataDirectory(std::string fileEnding)
//{
//	std::vector<std::string> fileNames;
//	for (const auto& entry : std::filesystem::directory_iterator(pathToShaderDirectory)) {
//		if (entry.path().extension() == fileEnding) {
//			fileNames.push_back(entry.path().filename().string());
//		}
//	}
//
//	return fileNames;
//}
