#include <iostream>
#include <Windows.h>

#include <osgDB/ReadFile>
#include <osgViewer/Viewer>


int main() {
	osg::ref_ptr<osg::Node> root = osgDB::readNodeFile("OpenSceneGraphData\\cow.osg");

	osgViewer::Viewer viewer;
	viewer.setSceneData(root.get());

	viewer.run();
}