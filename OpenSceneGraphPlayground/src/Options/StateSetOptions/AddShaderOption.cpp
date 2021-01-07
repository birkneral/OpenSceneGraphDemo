#include "Options\StateSetOptions\AddShaderOption.h"
#include <filesystem>
#include <UtilityFunctions.h>
#include <osgDB\ReadFile>

AddShaderOption::AddShaderOption()
{
	vertexShaderFiles = collectFileNamesWithGivenEndingInDataDirectory(".vert");
	fragmentShaderFiles = collectFileNamesWithGivenEndingInDataDirectory(".frag");
	geometryShaderFiles = collectFileNamesWithGivenEndingInDataDirectory(".geom");
	geometryShaderFiles.insert(geometryShaderFiles.begin(), " ");
}

void AddShaderOption::displayStateSetOption(osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode)
{
	if (ImGui::TreeNode("Add use of a shader")) {

		if (ImGui::TreeNode("Uniforms")) {
			osg::StateSet::UniformList currentUniforms = stateSetOfCurrentlySelectedNode->getUniformList();

			if (ImGui::TreeNode("Current uniforms")) {
				for (const auto& [unifromName, uniformToFlagPair] : currentUniforms) {
					ImGui::Text("	Name:");
					ImGui::SameLine();
					ImGui::Text(unifromName.c_str());
					ImGui::Text("	Datatype:");
					ImGui::SameLine();
					osg::ref_ptr<osg::Uniform> uniform = uniformToFlagPair.first;
					osg::Uniform::Type uniformType = uniform->getType();
					ImGui::Text(glConstToStringMap[uniformType].c_str());
					ImGui::Text("	Flag:");
					ImGui::SameLine();
					ImGui::Text(stateAttributeFlagToString[uniformToFlagPair.second].c_str());

					if (ImGui::Button("Remove uniform")) {
						stateSetOfCurrentlySelectedNode->removeUniform(uniform);
					}
				}
				ImGui::TreePop();
			}

			if (ImGui::TreeNode("Add uniform")) {

				UtilityFunctions::displayImGuiComboBox("S-Flag", availableFlags, uniformFlagSelectionIndex);

				UtilityFunctions::displayImGuiComboBox("Uniform type", uniformTypes, uniformTypeSelectionIndex);

				ImGui::InputText("Uniform name", uniformNameInput, IM_ARRAYSIZE(uniformNameInput));
				std::string cleanedUniformName = uniformNameInput;
				cleanedUniformName.erase(remove(cleanedUniformName.begin(), cleanedUniformName.end(), ' '), cleanedUniformName.end());

				displayAddUnifromButton(stateSetOfCurrentlySelectedNode, cleanedUniformName);

				ImGui::TreePop();
			}
			ImGui::TreePop();
		}

		if (vertexShaderFiles.size() > 0 && fragmentShaderFiles.size() > 0) {
			if (ImGui::TreeNode("Shader")) {

				UtilityFunctions::displayImGuiComboBox("Vertex shader to add", vertexShaderFiles, vertexShaderFileSelectionIndex);

				UtilityFunctions::displayImGuiComboBox("Fragment shader to add", fragmentShaderFiles, fragmetShaderFileSelectionIndex);

				UtilityFunctions::displayImGuiComboBox("Geometry shader to add", geometryShaderFiles, geometryShaderFileSelectionIndex);

				UtilityFunctions::displayImGuiComboBox("Sh-Flag", availableFlags, shaderFlagSelectionIndex);

				UtilityFunctions::displayImGuiComboBox("Sh-On/Off", onOffSelections, shaderOnOffSelectionIndex);

				if (ImGui::Button("Add program with selected shader")) {
					osg::ref_ptr<osg::Program> program = new osg::Program;
					osg::ref_ptr<osg::Shader> vertexShader = osgDB::readShaderFile(pathToShaderDirectory + vertexShaderFiles[vertexShaderFileSelectionIndex]);
					osg::ref_ptr<osg::Shader> fragmentShader = osgDB::readShaderFile(pathToShaderDirectory + fragmentShaderFiles[fragmetShaderFileSelectionIndex]);
					program->addShader(vertexShader.get());
					program->addShader(fragmentShader.get());

					if (geometryShaderFileSelectionIndex != 0) {
						osg::ref_ptr<osg::Shader> geometryShader = osgDB::readShaderFile(vertexShaderFiles[vertexShaderFileSelectionIndex]);
						program->addShader(geometryShader.get());
					}

					stateSetOfCurrentlySelectedNode->setAttributeAndModes(program, selectionIdToStateAttributeFlag[shaderFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[shaderOnOffSelectionIndex]);
				}
				ImGui::TreePop();
			}
		}
		else {
			ImGui::Text("Please put at least one vertex (.vert)");
			ImGui::Text("and one fragmet (.frag) shader file in the data directory.");
		}
		ImGui::TreePop();
	}
}

void AddShaderOption::displayAddUnifromButton(osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode, std::string cleanedUniformName)
{

	if (uniformTypeSelectionIndex == 0) {
		ImGui::InputFloat("Float Value", &uniformFloatInput);

		if (ImGui::Button("Add Float Uniform")) {
			osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(), uniformFloatInput);
			stateSetOfCurrentlySelectedNode->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex]);
		}
	}

	if (uniformTypeSelectionIndex == 1) {
		ImGui::InputFloat2("Float Vec2 Value", uniformFloatTwoInput);

		if (ImGui::Button("Add Float Vec2 Uniform")) {
			osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(), osg::Vec2(uniformFloatTwoInput[0], uniformFloatTwoInput[1]));
			stateSetOfCurrentlySelectedNode->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[shaderOnOffSelectionIndex]);
		}
	}

	if (uniformTypeSelectionIndex == 2) {
		ImGui::InputFloat3("Float Vec3 Value", uniformFloatThreeInput);

		if (ImGui::Button("Add Float Vec3 Uniform")) {
			osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(), osg::Vec3(uniformFloatThreeInput[0], uniformFloatThreeInput[1], uniformFloatThreeInput[2]));
			stateSetOfCurrentlySelectedNode->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[shaderOnOffSelectionIndex]);
		}
	}

	if (uniformTypeSelectionIndex == 3) {
		ImGui::InputFloat4("Float Vec4 Value", uniformFloatFourInput);

		if (ImGui::Button("Add Float Vec4 Uniform")) {
			osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(), osg::Vec4(uniformFloatFourInput[0], uniformFloatFourInput[1], uniformFloatFourInput[2], uniformFloatFourInput[3]));
			stateSetOfCurrentlySelectedNode->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[shaderOnOffSelectionIndex]);
		}
	}

	if (uniformTypeSelectionIndex == 4) {
		ImGui::InputInt("Int Value", &uniformInputInt);

		if (ImGui::Button("Add Int Uniform")) {
			osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(), uniformInputInt);
			stateSetOfCurrentlySelectedNode->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[shaderOnOffSelectionIndex]);
		}
	}

	if (uniformTypeSelectionIndex == 5) {
		ImGui::InputFloat2("Mat2 Row1", uniformFloatMatTwoRowOneInput);
		ImGui::InputFloat2("Mat2 Row2", uniformFloatMatTwoRowTwoInput);

		if (ImGui::Button("Add Mat2 Uniform")) {
			osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(),
				osg::Matrix2(uniformFloatMatTwoRowOneInput[0], uniformFloatMatTwoRowOneInput[1],
					uniformFloatMatTwoRowTwoInput[0], uniformFloatMatTwoRowTwoInput[1]));
			stateSetOfCurrentlySelectedNode->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[shaderOnOffSelectionIndex]);
		}
	}

	if (uniformTypeSelectionIndex == 6) {
		ImGui::InputFloat3("Mat3 Row1", uniformFloatMatThreeRowOneInput);
		ImGui::InputFloat3("Mat3 Row2", uniformFloatMatThreeRowTwoInput);
		ImGui::InputFloat3("Mat3 Row3", uniformFloatMatThreeRowThreeInput);

		if (ImGui::Button("Add Mat3 Uniform")) {
			osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(),
				osg::Matrix3(uniformFloatMatThreeRowOneInput[0], uniformFloatMatThreeRowOneInput[1], uniformFloatMatThreeRowOneInput[2],
					uniformFloatMatThreeRowTwoInput[0], uniformFloatMatThreeRowTwoInput[1], uniformFloatMatThreeRowTwoInput[2],
					uniformFloatMatThreeRowThreeInput[0], uniformFloatMatThreeRowThreeInput[1], uniformFloatMatThreeRowThreeInput[2]));
			stateSetOfCurrentlySelectedNode->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[shaderOnOffSelectionIndex]);
		}
	}

	if (uniformTypeSelectionIndex == 7) {
		ImGui::InputFloat4("Mat4 Row1", uniformFloatMatFourRowOneInput);
		ImGui::InputFloat4("Mat4 Row2", uniformFloatMatFourRowTwoInput);
		ImGui::InputFloat4("Mat4 Row3", uniformFloatMatFourRowThreeInput);
		ImGui::InputFloat4("Mat4 Row4", uniformFloatMatFourRowFourInput);

		if (ImGui::Button("Add Mat4 Uniform")) {
			osg::ref_ptr<osg::Uniform> uniformToAdd = new osg::Uniform(cleanedUniformName.c_str(),
				osg::Matrixf(uniformFloatMatFourRowOneInput[0], uniformFloatMatFourRowOneInput[1], uniformFloatMatFourRowOneInput[2], uniformFloatMatFourRowOneInput[3],
					uniformFloatMatFourRowTwoInput[0], uniformFloatMatFourRowTwoInput[1], uniformFloatMatFourRowTwoInput[2], uniformFloatMatFourRowTwoInput[3],
					uniformFloatMatFourRowThreeInput[0], uniformFloatMatFourRowThreeInput[1], uniformFloatMatFourRowThreeInput[2], uniformFloatMatFourRowThreeInput[3],
					uniformFloatMatFourRowFourInput[0], uniformFloatMatFourRowFourInput[1], uniformFloatMatFourRowFourInput[2], uniformFloatMatFourRowFourInput[3]));
			stateSetOfCurrentlySelectedNode->addUniform(uniformToAdd, selectionIdToStateAttributeFlag[uniformFlagSelectionIndex] | selectionIdToStateAttributeModeOnOff[shaderOnOffSelectionIndex]);
		}
	}
}

std::vector<std::string> AddShaderOption::collectFileNamesWithGivenEndingInDataDirectory(std::string fileEnding)
{
	std::vector<std::string> fileNames;
	for (const auto& entry : std::filesystem::directory_iterator(pathToShaderDirectory)) {
		if (entry.path().extension() == fileEnding) {
			fileNames.push_back(entry.path().filename().string());
		}
	}

	return fileNames;
}
