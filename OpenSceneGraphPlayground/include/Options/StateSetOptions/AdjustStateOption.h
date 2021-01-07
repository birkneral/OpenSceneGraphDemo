#pragma once
#include <Options\GraphOption.h>
#include <osg\PolygonMode>
#include <osg\BlendFunc>
#include <Options\StateSetOptions\AddShaderOption.h>
#include <Options\StateSetOptions\AdjustLightStateOption.h>
#include <Options\StateSetOptions\AdjustPolygonModeOption.h>
#include <Options\StateSetOptions\AdjustRenderingHintOption.h>
#include <Options\StateSetOptions\AdjustBlendFunctionOption.h>


class AdjustStateOption : StateSetOption {
public:
	AdjustStateOption();

	void displayStateSetOption(osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode) override;
private:
	AdjustBlendFunctionOption adjustBlendFunctionOption;
	AddShaderOption addShaderOption;
	AdjustLightStateOption adjustLightStateOption;
	AdjustPolygonModeOption adjustPolygonModeOption;
	AdjustRenderingHintOption adjustRenderingHintOption;
};