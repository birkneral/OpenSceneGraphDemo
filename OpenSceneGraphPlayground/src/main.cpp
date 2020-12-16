#include <iostream>
#include <Windows.h>
#include "GL/glew.h"

#include <osgViewer/Viewer>
#include <osgViewer/config/SingleWindow>
#include <osgDB/ReadFile>

#include <imgui/imgui.h>

#include "OsgImGuiHandler.hpp"
#include "GlewInitOperation.h"
#include "PlaygroundImGuiHandler.h"


#include <osg/ShapeDrawable>
#include <osg/Geode>
#include <osgGA/DriveManipulator>
#include <osgGA/StandardManipulator>


int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	viewer->setName("OSG Editor");
	
	osg::ref_ptr<osg::Group> root = new osg::Group;

	osg::ref_ptr<osg::Node> axes = osgDB::readNodeFile("OpenSceneGraphData\\axes.osgt");
	root->addChild(axes);

	PlaygroundImGuiHandler *eventHandler = new PlaygroundImGuiHandler(viewer, root);

	viewer.get()->setRealizeOperation(new GlewInitOperation);
	viewer.get()->addEventHandler(eventHandler);
	viewer.get()->addEventHandler(new osgViewer::StatsHandler);
	viewer.get()->apply(new osgViewer::SingleWindow(100, 100, 1024, 600));
	viewer.get()->setSceneData(root.get());

	return viewer.get()->run();
}


