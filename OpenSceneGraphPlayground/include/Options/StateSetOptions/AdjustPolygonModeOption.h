#pragma once
#include <Options\StateSetOption.h>
#include <osg\PolygonMode>
#include <osg\BlendFunc>

class AdjustPolygonModeOption : StateSetOption {
public:
	AdjustPolygonModeOption();

	void displayStateSetOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;
private:
	int faceSelectionIndex = 0;
	int modeSelectionIndex = 0;
	int flagSelectionIndex = 0;

	const char* polygonModeFaces[3] = { "FRONT", "BACK", "FRONT_AND_BACK" };
	const char* polygonModeModes[3] = { "GL_POINT", "GL_LINE", "GL_FILL" };

	std::map<int, osg::PolygonMode::Face> selectionIdToPolygonModeFace;
	std::map<int, osg::PolygonMode::Mode> selectionIdToPolygonModeMode;
};