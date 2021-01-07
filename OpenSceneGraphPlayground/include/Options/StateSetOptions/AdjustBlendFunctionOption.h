#pragma once
#include <Options\StateSetOption.h>
#include <osg\PolygonMode>
#include <osg\BlendFunc>

class AdjustBlendFunctionOption : StateSetOption {
public:
	AdjustBlendFunctionOption();

	void displayStateSetOption(osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode) override;
private:

	int sourceBlendFunctionSelectionIndex = 0;
	int destinationBlendFunctionSelectionIndex = 0;
	int flagSelectionIndex = 0;
	int modeOnOffSelectionIndex = 0;

	std::vector<std::string> blendFuncSelection = { "GL_DST_ALPHA", "GL_DST_COLOR", "GL_ONE", "GL_ONE_MINUS_DST_ALPHA",
								   "GL_ONE_MINUS_DST_COLOR", "GL_ONE_MINUS_SRC_ALPHA", "GL_ONE_MINUS_SRC_COLOR", "GL_SRC_ALPHA",
								   "GL_SRC_ALPHA_SATURATE", "GL_SRC_COLOR", "GL_CONSTANT_COLOR", "GL_ONE_MINUS_CONSTANT_COLOR",
								   "GL_CONSTANT_ALPHA", "GL_ONE_MINUS_CONSTANT_ALPHA", "GL_ZERO",
	};


	std::map<int, GLenum> blendModeSelectionToGLenum; 
};