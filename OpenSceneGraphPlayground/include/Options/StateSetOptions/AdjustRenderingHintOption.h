#pragma once
#include <Options\StateSetOption.h>
#include <osg\PolygonMode>
#include <osg\BlendFunc>

class AdjustRenderingHintOption : StateSetOption {
public:
	AdjustRenderingHintOption();

	void displayStateSetOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;
private:
	int renderingHintSelection = 0;

	const char* renderingHintOptions[3] = { "Default", "Opaque", "Transparent" };

	std::map<int, std::string> renderingHintToString;
	std::map<int, osg::StateSet::RenderingHint> selectionIdToRenderingHint;

};