#pragma once
#include <Options\GraphOption.h>
#include <osg\PolygonMode>
#include <osg\BlendFunc>
#include <Options\StateSetOptions\AddShaderOption.h>
#include <Options\StateSetOptions\AdjustLightStateOption.h>
#include <Options\StateSetOptions\AdjustPolygonModeOption.h>
#include <Options\StateSetOptions\AdjustRenderingHintOption.h>
#include <Options\StateSetOptions\AdjustBlendFunctionOption.h>


class AdjustStateOption : GraphOption {
public:
	AdjustStateOption();

	void displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor);
private:
	AdjustBlendFunctionOption adjustBlendFunctionOption;
	AddShaderOption addShaderOption;
	AdjustLightStateOption adjustLightStateOption;
	AdjustPolygonModeOption adjustPolygonModeOption;
	AdjustRenderingHintOption adjustRenderingHintOption;

	//std::string pathToShaderDirectory = "OpenSceneGraphData\\shaders\\";

	//std::vector<std::string> vertexShaderFiles;
	//std::vector<std::string> fragmentShaderFiles;
	//std::vector<std::string> geometryShaderFiles;

	//int polygonModeFaceSelectionIndex = 0;
	//int polygonModeModeSelectionIndex = 0;
	//int polygonModeFlagSelectionIndex = 0;
	//int renderingHintSelection = 0;

	//int sourceBlendFunctionSelectionIndex = 0;
	//int destinationBlendFunctionSelectionIndex = 0;
	//int stateAttributeBlendFuncFlagSelectionIndex = 0;
	//int stateAttributeBlendOnOffSelectionIndex = 0;

	//int stateAttributeLightingFlagSelection = 0;
	//int stateAttributeLightingOnOffSelection = 0;

	//int stateAttributeLightsFlagSelection[8]; 
	//int stateAttributeLightsOnOffSelection[8];

	//int vertexShaderFileSelectionIndex = 0;
	//int fragmetShaderFileSelectionIndex = 0;
	//int geometryShaderFileSelectionIndex = 0;
	//int shaderFlagSelectionIndex = 0;
	//int shaderOnOffSelectionIndex = 0;

	//int uniformTypeSelectionIndex = 0;
	//char uniformNameInput[128] = "Enter Uniform Name";
	//int uniformFlagSelectionIndex = 0;
	//int uniformOnOffSelectionIndex = 0;

	//float uniformInputFloat = 0.0f;
	//float uniformFloatTwoInput[2] = { 0.0f, 0.0f };
	//float uniformFloatThreeInput[3] = { 0.0f, 0.0f, 0.0f };
	//float uniformFloatFourInput[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	//int uniformInputInt = 0;
	//float uniformFloatMatTwoRowOneInput[2] = { 0.0f, 0.0f };
	//float uniformFloatMatTwoRowTwoInput[2] = { 0.0f, 0.0f };
	//float uniformFloatMatThreeRowOneInput[3] = { 0.0f, 0.0f, 0.0f };
	//float uniformFloatMatThreeRowTwoInput[3] = { 0.0f, 0.0f, 0.0f };
	//float uniformFloatMatThreeRowThreeInput[3] = { 0.0f, 0.0f, 0.0f };
	//float uniformFloatMatFourRowOneInput[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	//float uniformFloatMatFourRowTwoInput[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	//float uniformFloatMatFourRowThreeInput[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	//float uniformFloatMatFourRowFourInput[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

	//void displayPolygonModeOption(osg::ref_ptr<osg::StateSet> currentStateSet);
	//void displayRenderingHintOption(osg::ref_ptr<osg::StateSet> currentStateSet);
	//void displayBlendFuncOption(osg::ref_ptr<osg::StateSet> currentStateSet);
	//void displayLightOption(osg::ref_ptr<osg::StateSet> currentStateSet);
	//void displayAddShaderOption(osg::ref_ptr<osg::StateSet> currentStateSet);

	//std::vector<std::string> collectFileNamesWithGivenEndingInDataDirectory(std::string fileEnding);

	//std::map<int, std::string> renderingHintToString;
	//
 //   std::map<int, std::string> glConstToStringMap;
	//std::map<unsigned int, std::string> stateAttributeFlagToString;

	//std::map<int, osg::StateAttribute::Values> selectionIdToStateAttributeFlag;
	//std::map<int, osg::StateAttribute::Values> selectionIdToStateAttributeModeOnOff;

	//std::map<int, osg::StateSet::RenderingHint> selectionIdToRenderingHint;

	//std::map<int, osg::PolygonMode::Face> selectionIdToPolygonModeFace;
	//std::map<int, osg::PolygonMode::Mode> selectionIdToPolygonModeMode;


	//std::map<int, GLenum> blendModeSelectionToGLenum;
};