#pragma once
#include <Options\StateSetOption.h>
#include <osg\PolygonMode>
#include <osg\BlendFunc>

class AddShaderOption : StateSetOption {
public:
	AddShaderOption();

	void displayStateSetOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;
private:
	std::string pathToShaderDirectory = "OpenSceneGraphData\\shaders\\";

	std::vector<std::string> vertexShaderFiles;
	std::vector<std::string> fragmentShaderFiles;
	std::vector<std::string> geometryShaderFiles;

	int vertexShaderFileSelectionIndex = 0;
	int fragmetShaderFileSelectionIndex = 0;
	int geometryShaderFileSelectionIndex = 0;
	int shaderFlagSelectionIndex = 0;
	int shaderOnOffSelectionIndex = 0;

	int uniformTypeSelectionIndex = 0;
	char uniformNameInput[128] = "Enter Uniform Name";
	int uniformFlagSelectionIndex = 0;
	int uniformOnOffSelectionIndex = 0;

	float uniformFloatInput = 0.0f;
	float uniformFloatTwoInput[2] = { 0.0f, 0.0f };
	float uniformFloatThreeInput[3] = { 0.0f, 0.0f, 0.0f };
	float uniformFloatFourInput[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	int uniformInputInt = 0;
	float uniformFloatMatTwoRowOneInput[2] = { 0.0f, 0.0f };
	float uniformFloatMatTwoRowTwoInput[2] = { 0.0f, 0.0f };
	float uniformFloatMatThreeRowOneInput[3] = { 0.0f, 0.0f, 0.0f };
	float uniformFloatMatThreeRowTwoInput[3] = { 0.0f, 0.0f, 0.0f };
	float uniformFloatMatThreeRowThreeInput[3] = { 0.0f, 0.0f, 0.0f };
	float uniformFloatMatFourRowOneInput[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float uniformFloatMatFourRowTwoInput[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float uniformFloatMatFourRowThreeInput[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float uniformFloatMatFourRowFourInput[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

	const char* uniformTypes[8] = {
	"GL_Float", "GL_FLOAT_VEC2", "GL_FLOAT_VEC3", "GL_FLOAT_VEC4",
	"GL_INT", "GL_FLOAT_MAT2", "GL_FLOAT_MAT3", "GL_FLOAT_MAT4",
	};

	void displayAddUnifromButton(osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode, std::string cleanedUniformName);

	std::vector<std::string> collectFileNamesWithGivenEndingInDataDirectory(std::string fileEnding);

};