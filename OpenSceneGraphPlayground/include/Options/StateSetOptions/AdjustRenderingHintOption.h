#pragma once
#include <Options\StateSetOption.h>
#include <osg\PolygonMode>
#include <osg\BlendFunc>

class AdjustRenderingHintOption : StateSetOption {
public:
	AdjustRenderingHintOption();

	void displayStateSetOption(osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode) override;
private:
	int renderingHintSelection = 0;

	std::vector<std::string> renderingHintOptions = { "Default", "Opaque", "Transparent" };

	std::map<int, std::string> renderingHintToString;
	std::map<int, osg::StateSet::RenderingHint> selectionIdToRenderingHint;

};