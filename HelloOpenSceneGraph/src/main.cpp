#include <Windows.h>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

#include <osgViewer/config/SingleWindow>
#include <osgGA/TrackballManipulator>

int main(int argc, char** argv) {
	osg::ref_ptr<osg::Node> root = osgDB::readNodeFile("OpenSceneGraphData\\cow.osg");

	osgViewer::Viewer viewer;
	viewer.setSceneData(root.get());

	// To display viewer in single window, comment the following line in:
	//viewer.apply(new osgViewer::SingleWindow(100, 100, 1024, 600));

	viewer.run();

	// The code lines below can be commented in to use a coded simulation loop insted of the run method.
	// This brings some drawbacks compared to the use of the run method.
	// For further information please read chapter 12 section "Digging into the simulation loop" of "OpenSceneGraph 3.0 - Beginner´s Guide" 
	// (http://www.openscenegraph.org/index.php/documentation/books/10-openscenegraph-beginners-guide-published)
	
	// The run method automatically sets TrackballManipulator, if it is not called it must be set manually
	//viewer.setCameraManipulator(new osgGA::TrackballManipulator);

	//while (!viewer.done()) {
	//	viewer.frame();
	//	//std::cout << "Frame rendered" << std::endl;
	//}

	return 0;
}