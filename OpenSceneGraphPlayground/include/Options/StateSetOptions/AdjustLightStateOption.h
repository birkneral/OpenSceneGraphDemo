#pragma once
#include <Options\StateSetOption.h>
#include <osg\PolygonMode>
#include <osg\BlendFunc>

class AdjustLightStateOption : StateSetOption {
public:
	AdjustLightStateOption();

	void displayStateSetOption(osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode);
private:
	int lightingFlagSelectionIndex = 0;
	int lightingOnOffSelectionIndex = 0;

	int specificLightsFlagSelectionIndices[8];
	int specificLightsOnOffSelectionIndices[8];
};