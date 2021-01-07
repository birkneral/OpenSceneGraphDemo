#pragma once
#include <Options\StateSetOption.h>
#include <osg\PolygonMode>
#include <osg\BlendFunc>

class AdjustPolygonModeOption : StateSetOption {
public:
	AdjustPolygonModeOption();

	void displayStateSetOption(osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode) override;
private:
	int faceSelectionIndex = 0;
	int modeSelectionIndex = 0;
	int flagSelectionIndex = 0;

	std::vector<std::string> polygonModeFaces = { "FRONT", "BACK", "FRONT_AND_BACK" };
	std::vector<std::string> polygonModeModes = { "GL_POINT", "GL_LINE", "GL_FILL" };

	std::map<int, osg::PolygonMode::Face> selectionIdToPolygonModeFace;
	std::map<int, osg::PolygonMode::Mode> selectionIdToPolygonModeMode;
};