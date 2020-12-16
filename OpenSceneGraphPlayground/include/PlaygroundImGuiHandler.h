#pragma once
#include "windows.h"
#include <osgGA\NodeTrackerManipulator>
#include "OsgImGuiHandler.hpp"
#include "TreeGeneratorVisitor.h"
#include "Options\GraphOptions\AddGeodeOption.h"
#include "Options\GraphOptions\AddGroupOption.h"
#include "Options\GraphOptions\AddShapeDrawableOption.h"
#include "Options\GraphOptions\DeleteNodeOption.h"
#include "Options\GraphOptions\AddMatrixTransformOption.h"
#include "Options\GraphOptions\AddNodeFromFileOption.h"
#include "Options\GraphOptions\AddGeometryOption.h"
#include "Options\GraphOptions\AddIndexedGeometryOption.h"
#include "Options\GraphOptions\AddLightSourceOption.h"
#include "Options\GraphOptions\AddOrAdjustSwitchNodeOption.h"
#include "Options\GraphOptions\AddOrAdjustLodNodeOption.h"
#include "Options\StateSetOptions\AdjustStateOption.h"

class PlaygroundImGuiHandler : public OsgImGuiHandler {
public:
	PlaygroundImGuiHandler(osg::ref_ptr<osgViewer::Viewer> viewer, osg::ref_ptr<osg::Group> rootNode);

protected:
	void drawUi() override;
private:
	osg::ref_ptr<osgGA::NodeTrackerManipulator> nodeTrackballManipulator;
	
	osg::ref_ptr<osgViewer::Viewer> viewer;
	osg::ref_ptr<osg::Group> rootNode;
	TreeGeneratorVisitor treeGeneratorVisitor;

	float backgroundColorInput[3] = { 0.0f, 0.0f, 0.0f };


	AddGeodeOption addGeodeOption;
	AddGroupOption addGroupOption;
	DeleteNodeOption deleteNodeOption;
	AddShapeDrawableOption addShapeDrawableOption;
	AddMatrixTransformOption addMatrixTransformOption;
	AddNodeFromFileOption addNodeFromFileOption;
	AddGeometryOption addGeometryOption;
	AddIndexedGeometryOption addIndexedGeometryOption;
	AddLightSourceOption addLightSourceOption;
	AdjustStateOption adjustStateOption;
	AddOrAdjustSwitchNodeOption addOrAdjustSwitchNodeOption;
	AddorAdjustLodNodeOption addOrAdjustLodNodeOption;
};